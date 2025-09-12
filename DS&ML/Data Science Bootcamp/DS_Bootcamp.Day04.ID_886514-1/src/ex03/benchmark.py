#!/usr/bin/env python3
import timeit
import sys
from functools import reduce


def loop(num):
    res = 0
    for i in range(1, num + 1):
        res += i * i
    return res


def reduce_loop(num):
    res = reduce(lambda x, y: x + y * y, [i for i in range(1, num + 1)])
    return res


def main():
    if len(sys.argv) == 4:
        if sys.argv[1] == "loop":
            loopt_timer = timeit.Timer(lambda: loop(int(sys.argv[3])))
            loop_time = loopt_timer.timeit(number=int(sys.argv[2]))
            print(loop_time)
        elif sys.argv[1] == "reduce":
            reduce_timer = timeit.Timer(lambda: reduce_loop(int(sys.argv[3])))
            reduce_time = reduce_timer.timeit(number=int(sys.argv[2]))
            print(reduce_time)


if __name__ == "__main__":
    main()
