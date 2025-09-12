import sys


class Research:

    def __init__(self, filename):
        self.filename = filename

    def file_reader(self):
        try:
            with open(self.filename, "r") as file:
                lines = file.readlines()
        except FileNotFoundError:
            raise ValueError("File not found")

        if len(lines) < 2:
            raise ValueError("Incorrect file structure")
        elif len(lines[0].strip().split(",")) != 2:
            raise ValueError("Incorrect file structure")

        for line in lines[1:]:
            values = line.strip().split(",")
            if (
                len(values) != 2
                or values[0] not in ["0", "1"]
                or values[1] not in ["0", "1"]
            ):
                raise ValueError("Incorrect file structure")

        return "".join(lines)


if __name__ == "__main__":
    if len(sys.argv) == 2:
        research = Research(sys.argv[1])
        try:
            result = research.file_reader()
            print(result)
        except Exception as e:
            print(e)
    else:
        print("Please specify the file path")
