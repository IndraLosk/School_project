import logging

file_name = "data.csv"
num_of_steps = 3
report_template = """We have made {observations} observations from tossing a coin: {count_tails} of them were tails and {count_heads} of
them were heads. The probabilities are {tail_percent}% and {head_percent}%, respectively. Our
forecast is that in the next {steps} observations we will have: {new_count_tails} tail and {new_count_heads} heads."""
output_file = "report"

logging.basicConfig(
    level=logging.INFO,
    filename="analytics.log",
    filemode="w",
    format="%(asctime)s %(levelname)s %(message)s",
)

bot_token = "7770197624:AAGU2gHTPByroIWtwvNhhYdJkt8Hh1bdFbc"
url = f"https://api.telegram.org/bot{bot_token}/sendMessage"
chat_id = 1963872870
