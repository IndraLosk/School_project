import json


def read_file():
    with open("exercise6/input.txt", "r") as file:
        lines = file.read()
        if len(lines) == 0:
            return None
        return json.loads(lines)


def return_json(data):
    result = {"list0": []}
    for k, v in data.items():
        result["list0"].extend(v)

    result["list0"].sort(key=lambda x: x["year"])

    print(json.dumps(result, indent=2))


if __name__ == "__main__":
    try:
        data = read_file()
        if data:
            return_json(data)
        else:
            print("Empty file")
    except:
        print("Incorrect json")


