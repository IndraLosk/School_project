#python3 names_extractor.py emails.txt

import sys
def extractor(filename):
    table = []
    try:
        with open(filename, "r") as file:
            lines = file.readlines()
    except FileNotFoundError:
        print(f'Файл {filename} не найден.')
        return

    for line in lines:
        name = line.split(".")[0]
        surname = line.split(".")[1].split("@")[0]
        table.append((name.capitalize(), surname.capitalize(), line))

    with open("employees.tsv", "w") as file:
        file.write('Name\tSurname\tE-mail\n')
        for row in table:
            file.write(f'{row[0]}\t{row[1]}\t{row[2]}')


if __name__ == "__main__":
    if(len(sys.argv) == 2):
        extractor(sys.argv[1])