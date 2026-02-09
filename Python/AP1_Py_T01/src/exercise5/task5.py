def num_split():
    num = input().split('.')
    number_split = []
    i = 0
    sign = '+'
    while num[0][i] == "-" or num[0][i] == "+":
        sign = num[0][i]
        i += 1
    if i > 1:
        raise ValueError
    point = 0
    digit = num[0][i:]
    if len(num) > 1:
        point = len(num[1])
        digit += num[1]
    number_split.append(sign)
    number_split.append(point)
    number_split.append(digit)
    return number_split


def binory_convert(num):
    full_number = 0
    for i, n in enumerate(num[::-1]):
        if ord(n) < 48 or ord(n) > 57:
            raise ValueError
        full_number += (ord(n) - ord('0')) * (10 ** i)

    binory = 0
    l = 0
    while full_number >= 1:
        binory += (full_number % 2) * (10 ** l)
        full_number //= 2
        l += 1

    binory *= 10 # * 2 
    return binory

def print_convert_number(num):
    if num[0] == "-":
        print(num[0], end="")
    res = 0
    i = 0
    while(num[2] > 0):
        res += (num[2] % 10) * (2 ** (i))
        num[2] //= 10
        i +=1

    res /= 10 ** num[1]

    print(f"{res:.3f}")

if __name__ == "__main__":
    try:
        num = num_split()
        num[2] = binory_convert(num[2])
        print_convert_number(num)
    except:
        print("Incorrect input")