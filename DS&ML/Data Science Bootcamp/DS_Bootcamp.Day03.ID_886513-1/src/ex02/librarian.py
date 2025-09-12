# tar -czvf nilahugh.tar.gz ex00/nilahugh/

import os
import subprocess

if __name__ == "__main__":
    env_name = os.environ.get("VIRTUAL_ENV")
    if env_name[-8:] == "nilahugh":
        subprocess.run(["pip", "install", "beautifulsoup4", "pytest"])
        subprocess.run("pip freeze > ex02/requirements.txt", shell=True)
