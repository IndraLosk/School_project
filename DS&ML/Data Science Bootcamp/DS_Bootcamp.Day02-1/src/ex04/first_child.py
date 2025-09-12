import sys
from random import randint


class Research:

    class Calculations:

        def __init__(self, data):
            self.data = data

        def counts(self):
            heads = sum(row[0] for row in self.data)
            tails = sum(row[1] for row in self.data)
            return heads, tails

        def fractions(self):
            heads, tails = self.counts()
            total = heads + tails
            if total == 0:
                res_heads, res_tails = 0, 0
            else:
                res_heads, res_tails = heads / total * 100, tails / total * 100
            return res_heads, res_tails

    class Analytics(Calculations):

        def predict_random(self, n):
            result = []
            for i in range(n):
                r = randint(0, 1)
                if r == 0:
                    result.append([r, 1])
                else:
                    result.append([r, 0])
            return result

        def predict_last(self):
            return self.data[-1]

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
            calc = Research.Calculations(result)
            analytics = Research.Analytics(result)

            heads, tails = calc.counts()
            print(heads, tails)
            frac_heads, frac_tails = calc.fractions()
            print(frac_heads, frac_tails)
            random_predictions = analytics.predict_random(3)
            print(random_predictions)
            last_prediction = analytics.predict_last()
            print(last_prediction)

        except Exception as e:
            print(e)
    else:
        print("Please specify the file path")
