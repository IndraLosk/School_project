# python3 -m cProfile -s time financial_enhanced.py 'MSFT' 'Total Revenue' > profiling-http.txt
# python3 -m cProfile -s ncalls financial_enhanced.py 'MSFT' 'Total Revenue' > profiling-ncalls.txt

import httpx
import sys
import time
from bs4 import BeautifulSoup


def get_response(ticker):
    url = f"https://finance.yahoo.com/quote/{ticker}/financials/?p={ticker}"
    headers = {"User-Agent": "Mozilla/5.0"}
    with httpx.Client() as client:
        response = client.get(url, headers=headers)
    if response.status_code != 200:
        raise Exception("Incorrect url")

    html_content = response.text

    return html_content


def get_row(soup, field_name):
    table = soup.find("div", class_="tableBody")
    if table == None:
        raise Exception("Incorrect url")

    rows = table.find_all("div", class_="row lv-0 yf-t22klz")

    for row in rows:
        if field_name in row.text:
            columns = row.find_all("div", class_="column")
            columns_values = [col.get_text(strip=True) for col in columns]

    if "columns_values" not in locals():
        raise Exception("Incorrect field_name")
    return columns_values


def main():

    if len(sys.argv) != 3:
        raise Exception("Incorrect number of arguments")
    try:
        soup = BeautifulSoup(get_response(sys.argv[1].upper()), "html.parser")
    except Exception as error:
        raise error

    try:
        row = get_row(soup, sys.argv[2].title())
    except Exception as error:
        raise error

    # time.sleep(5)
    print(tuple(row))


if __name__ == "__main__":
    try:
        main()
    except Exception as error:
        print(error)

    # import pstats

    # stats = pstats.Stats('profiling.prof')
    # stats.strip_dirs().sort_stats('cumulative')
    # with open('pstats-cumulative.txt', 'w') as f:
    #     stats.stream = f
    #     stats.print_stats(5)

# python3 -m cProfile -o profiling.prof financial_enhanced.py MSFT "Total Revenue"
# python3 -c "import pstats; stats = pstats.Stats('profiling.prof'); stats.strip_dirs().sort_stats('cumulative').print_stats(5)" > pstats-cumulative.txt
