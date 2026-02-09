def read_file():
    matrix = []
    with open("exercise3/input.txt", "r") as file:
        line = file.readline()
        while line:
            matrix.append(line.rstrip().split(" "))
            line = file.readline()
    return matrix


def is_shape(matrix, i, j):
    dimension = len(matrix)
    temp_i = i
    height = 0
    while temp_i < dimension and matrix[temp_i][j] == "1":
        height += 1
        temp_i += 1

    if (
        i + 1 < dimension
        and 0 <= j - 1
        and (matrix[i][j - 1] == "0" and matrix[i + 1][j - 1] == "1")
    ):
        j -= 1
    for k in range(height):
        for l in range(height):
            matrix[i + k][j + l] = "0"

    return matrix


def main(matrix):
    count_circles = 0
    count_squares = 0
    dimension = len(matrix)
    for i in range(dimension):
        for j in range(dimension):
            if (
                matrix[i][j] == "1"
                and i + 1 < dimension
                and j - 1 >= 0
                and matrix[i + 1][j - 1] == "1"
            ):
                count_circles += 1
                matrix = is_shape(matrix, i, j)
            elif matrix[i][j] == "1":
                count_squares += 1
                matrix = is_shape(matrix, i, j)

    print(count_squares, count_circles)


if __name__ == "__main__":
    matrix = read_file()
    main(matrix)
