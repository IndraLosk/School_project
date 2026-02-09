def count_polynomial():
    coef, point = input().split()
    coef = int(coef)
    point = float(point)
    result = 0
    for i in range(coef + 1):
        var = float(input())
        degree = coef - i
        result += var * degree * (point ** (degree - 1))
    print(f"{result:.3f}")


if __name__ == "__main__":
    count_polynomial()