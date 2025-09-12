# python3 -m venv nilahugh
# source nilahugh/bin/activate
# python3 venv.py
# deactivate

import os

if __name__ == "__main__":
    print(f"Your current virtual env is {os.environ.get('VIRTUAL_ENV')}")
