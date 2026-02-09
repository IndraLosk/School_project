if __name__ == "__main__":
    a = input().split(" ")
    b = input().split(" ")
    result = sum([float(a[i]) * float(b[i]) for i in range(len(a))])
    print(result)
