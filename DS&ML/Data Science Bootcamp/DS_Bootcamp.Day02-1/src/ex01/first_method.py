class Research:
    def file_reader(self):
        try:
            with open("data.csv", "r") as file:
                lines = file.read()
        except FileNotFoundError:
            lines = "File not found"

        return lines


if __name__ == "__main__":
    research = Research()
    print(research.file_reader())
