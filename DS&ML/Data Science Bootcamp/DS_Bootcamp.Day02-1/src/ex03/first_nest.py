import sys


class Research:

    class Calculations:
        def counts(data):
            heads = sum(row[0] for row in data)
            tails = sum(row[1] for row in data)
            return heads, tails

        def fractions(heads, tails):
            total = heads + tails
            if total == 0:
                res_heads, res_tails = 0, 0
            else:
                res_heads, res_tails = heads / total * 100, tails / total * 100
            return res_heads, res_tails

    def __init__(self, filename):
        self.filename = filename

    def file_reader(self, has_header=True):
        try:
            with open(self.filename, "r") as file:
                lines = file.readlines()
        except FileNotFoundError:
            raise ValueError("File not found")

        if len(lines) != 0 and len(lines[0].strip().split(",")) != 2:
            has_header = False
        if len(lines) < (2 if has_header else 1):
            raise ValueError("Incorrect file structure")

        result = []
        for line in lines[1 if has_header else 0 :]:
            values = line.strip().split(",")
            if (
                len(values) != 2
                or values[0] not in ["0", "1"]
                or values[1] not in ["0", "1"]
            ):
                raise ValueError("Incorrect file structure")
            result.append([int(values[0]), int(values[1])])

        return result


if __name__ == "__main__":
    if len(sys.argv) == 2:
        research = Research(sys.argv[1])
        try:
            result = research.file_reader()
            print(result)
            heads, tails = research.Calculations.counts(result)
            print(heads, tails)
            frac_heads, frac_tails = research.Calculations.fractions(heads, tails)
            print(frac_heads, frac_tails)
        except Exception as e:
            print(e)
    else:
        print("Please specify the file path")
