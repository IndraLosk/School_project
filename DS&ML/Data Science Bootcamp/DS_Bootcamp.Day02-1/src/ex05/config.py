file_name = "data.csv"
num_of_steps = 3
report_template = """We have made {observations} observations from tossing a coin: {count_tails} of them were tails and {count_heads} of
them were heads. The probabilities are {tail_percent}% and {head_percent}%, respectively. Our
forecast is that in the next {steps} observations we will have: {new_count_tails} tail and {new_count_heads} heads."""
output_file = "report"
