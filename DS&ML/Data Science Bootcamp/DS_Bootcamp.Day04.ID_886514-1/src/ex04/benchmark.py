#!/usr/bin/env python3
import random
from collections import Counter
import timeit


def generate_random_list():
    random_list = [random.randint(0, 100) for _ in range(1000000)]
    return random_list


def my_fun_create_dict(random_list):
    diction = {i: 0 for i in range(101)}
    for element in random_list:
        diction[element] += 1

    return diction


def my_fun_top_10(random_list):
    diction = my_fun_create_dict(random_list)
    sorted_dict = sorted(diction.items(), key=lambda x: x[1], reverse=True)
    return dict(sorted_dict[:10])


def counter_create_dict(random_list):
    return dict(Counter(random_list))


def counter_top_10(random_list):
    return dict(Counter(random_list).most_common(10))


def main():
    random_list = generate_random_list()

    t1 = timeit.timeit(lambda: my_fun_create_dict(random_list), number=1)
    t2 = timeit.timeit(lambda: counter_create_dict(random_list), number=1)
    t3 = timeit.timeit(lambda: my_fun_top_10(random_list), number=1)
    t4 = timeit.timeit(lambda: counter_top_10(random_list), number=1)

    print(f"my function: {t1}")
    print(f"Counter: {t2}")
    print(f"my top: {t3}")
    print(f"Counter's top: {t4}")


if __name__ == "__main__":
    main()
