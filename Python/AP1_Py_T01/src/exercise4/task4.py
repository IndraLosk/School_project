from math import factorial


def count_triangle(num):
    res = []
    for i in range(num):
        row = []
        for k in range(i + 1):
            element = factorial(i) / (factorial(k) * factorial(i - k))
            row.append(element)
        res.append(row)
    return res


def print_triangle(num, triangle):
    spaces = num
    for row in triangle:
        for element in row:
            print(int(element), end=" ")
        print()
        spaces -= 1


if __name__ == "__main__":
    try:
        num = int(input())
        if num <= 0:
            print("Natural number was expected")
        else:
            triangle = count_triangle(num)
            print_triangle(num, triangle)
    except:
        print("Natural number was expected")
