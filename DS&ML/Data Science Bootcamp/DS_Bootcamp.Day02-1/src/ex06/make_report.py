from config import *
from analytics import Research


def main():
    research = Research(file_name)
    try:
        data = research.file_reader()
        calc = Research.Calculations(data)
        analytics = Research.Analytics(data)

        heads, tails = calc.counts()
        frac_heads, frac_tails = calc.fractions()
        random_predictions = analytics.predict_random(num_of_steps)
        new_heads = sum(row[0] for row in random_predictions)
        new_tails = sum(row[1] for row in random_predictions)

        report = report_template.format(
            observations=len(data),
            count_tails=tails,
            count_heads=heads,
            tail_percent=round(frac_tails, 2),
            head_percent=round(frac_heads, 2),
            steps=num_of_steps,
            new_count_tails=new_tails,
            new_count_heads=new_heads,
        )

        analytics.save_file(report, output_file)

        research.send_message(True)
    except ValueError as e:
        research.send_message(False)


if __name__ == "__main__":
    main()
