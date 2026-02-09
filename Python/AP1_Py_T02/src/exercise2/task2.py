# for test:
# ./img
# https://images2.pics4learning.com/catalog/s/swamp_15.jpg
# https://bad-link-no-website-here.strange/img.png
# https://images2.pics4learning.com/catalog/p/parrot.jpg
# https://fikiwiki.com/uploads/posts/2022-02/1644936435_1-fikiwiki-com-p-krasivie-kartinki-1920kh1080-na-rabochii-s-1.jpg


import asyncio
import aiohttp
from aioconsole import ainput
from pathlib import Path
from tabulate import tabulate


class Download:
    def __init__(self):
        self.session = None
        self.path = None
        self.urls = []

    async def get_session(self):
        self.session = aiohttp.ClientSession()

    async def close_session(self):
        await self.session.close()

    async def add_inf(self, url, status):
        self.urls.append({"url": url, "status": status})

    def print_final(self):
        urls_table = [[url["url"], url["status"]] for url in self.urls]
        print(tabulate(urls_table, headers=["Ссылка", "Статус"], tablefmt="grid"))

    async def one_responce(self, url):
        timeout = aiohttp.ClientTimeout(total=60, connect=10, sock_read=5)
        res = None
        async with self.session.get(url, timeout=timeout) as response:
            if response.status == 200:
                res = await response.read()
        return res

    async def download_one_file(self, filename, content):
        filepath = self.path / filename.split("/")[-1]
        with open(filepath, "wb") as file:
            file.write(content)

    async def download_files(self):
        s = await ainput()
        while s != "":
            try:
                content = await self.one_responce(s)
                await self.download_one_file(s, content)
                await self.add_inf(s, "Успех")
            except Exception as e:
                await self.add_inf(s, "Ошибка")

            s = await ainput()

    def get_path(self):
        path = Path(input())
        while not (path.exists() and path.is_dir()):
            path = Path(input("Path not exist, write new parh: "))

        self.path = path

async def main():
        
        download = Download()
        download.get_path()

        try:
            await download.get_session()
            await download.download_files()
        finally:
            await download.close_session()
            download.print_final()


if __name__ == "__main__":
    asyncio.run(main())
