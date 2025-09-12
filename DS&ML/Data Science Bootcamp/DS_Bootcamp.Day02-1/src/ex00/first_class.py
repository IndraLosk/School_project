class Must_read:
    try:
        with open("data.csv", "r") as file:
            print(file.read())
    except FileNotFoundError:
        print("File not found")


if __name__ == "__main__":
    Must_read()
