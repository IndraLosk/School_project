#!/usr/bin/env python3
import timeit


def loop(emails):
    gmails = []
    for email in emails:
        if email.endswith("@gmail.com"):
            gmails.append(email)

    return gmails


def list_comprehension(emails):
    gmails = [email for email in emails if email.endswith("@gmail.com")]
    return gmails


def list_map_email(emails):
    gmails = list(
        map(lambda email: email if email.endswith("@gmail.com") else None, emails)
    )
    return gmails


def main():
    emails = [
        "john@gmail.com",
        "james@gmail.com",
        "alice@yahoo.com",
        "anna@live.com",
        "philipp@gmail.com",
    ] * 5

    loop_timer = timeit.Timer(lambda: loop(emails))
    list_timer = timeit.Timer(lambda: list_comprehension(emails))
    map_timer = timeit.Timer(lambda: list_map_email(emails))

    loop_time = loop_timer.timeit(number=9000000)
    list_time = list_timer.timeit(number=9000000)
    list_map = map_timer.timeit(number=9000000)

    if list_time <= loop_time and list_time <= list_map:
        print("it is better to use a list comprehension")
    elif list_time >= loop_time and list_time >= list_map:
        print("it is better to use a loop")
    else:
        print("it is better to use a map")

    times = sorted([loop_time, list_time, list_map])
    print(f"{times[0]} vs {times[1]} vs {times[2]}")


if __name__ == "__main__":
    main()
