if __name__ == "__main__":
    is_palindrom = input()
    result = False
    if is_palindrom == is_palindrom[::-1]:
        result = True
    print(result)
