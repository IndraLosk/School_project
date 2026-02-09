def count_uniq():
    num = int(input())
    res = set()
    for _ in range(num):
        res.add(input())
    print(len(res))


if __name__ == "__main__":
    count_uniq()
