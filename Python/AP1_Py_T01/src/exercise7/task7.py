def read_field():

    n, m = map(int, input().split())
    field = []
    for i in range(n):
        row = input().split()
        field.append(list(map(int, row)))

    return n, m, field


def search(n, m, field):

    matrix = field
    for i in range(1, n):
        matrix[i][0] += matrix[i - 1][0]

    for j in range(1, m):
        matrix[0][j] += matrix[0][j - 1]

    path = []
    for i in range(1, n):
        for j in range(1, m):
            num_down = matrix[i][j] + matrix[i - 1][j]
            num_right = matrix[i][j] + matrix[i][j - 1]
            if num_down > num_right:
                matrix[i][j] = num_down
            else:
                matrix[i][j] = num_right
    print(matrix[n - 1][m - 1])


if __name__ == "__main__":
    n, m, field = read_field()
    search(n, m, field)
