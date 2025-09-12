#!/usr/bin/env python3
import sys
import resource


def reader(filename):
    try:
        with open(filename, "r") as file:
            lines = file.readlines()
    except Exception as error:
        raise ValueError(f"Can't open the file. Error: {error}")

    return lines


def main():
    if len(sys.argv) == 2:
        try:
            lines = reader(sys.argv[1])
            for line in lines:
                pass
            usage = resource.getrusage(resource.RUSAGE_SELF)
            print(f"Peak Memory Usage = {usage.ru_maxrss / 1024 / 1024} GB")
            print(
                f"User Mode Time + System Mode Time = {usage.ru_utime + usage.ru_stime}s"
            )
        except Exception as error:
            print(error)
    else:
        print("Enter filename!")


if __name__ == "__main__":
    main()
