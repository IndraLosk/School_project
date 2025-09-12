#!/usr/bin/env python3

import timeit
import sys


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


def list_filter_email(emails):
    gmails = list(filter(lambda email: email.endswith("@gmail.com"), emails))
    return gmails


def to_do(fun, loops, emails):
    res = 0
    if fun == "loop":
        loop_timer = timeit.Timer(lambda: loop(emails))
        res = loop_timer.timeit(number=loops)
    elif fun == "list_comprehension":
        list_timer = timeit.Timer(lambda: list_comprehension(emails))
        res = list_timer.timeit(number=loops)
    elif fun == "map":
        map_timer = timeit.Timer(lambda: list_map_email(emails))
        res = map_timer.timeit(number=loops)
    elif fun == "filter":
        filter_timer = timeit.Timer(lambda: list_filter_email(emails))
        res = filter_timer.timeit(number=loops)
    return res


def main():

    if len(sys.argv) == 3:

        emails = [
            "john@gmail.com",
            "james@gmail.com",
            "alice@yahoo.com",
            "anna@live.com",
            "philipp@gmail.com",
        ] * 5

        res = to_do(sys.argv[1], int(sys.argv[2]), emails)
        print(res)


if __name__ == "__main__":
    main()
