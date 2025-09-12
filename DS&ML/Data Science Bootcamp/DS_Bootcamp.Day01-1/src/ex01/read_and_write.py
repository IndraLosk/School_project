def read_csv(filename):
    with open(filename, "r") as file:
        return file.readlines()

def write_tsv(lines, filename):
    with open(filename, 'w') as file:
        for line in lines:
            file.write(line.replace(',', '\t'))

if __name__ == '__main__':
    lines = read_csv("ds.csv")
    write_tsv(lines, "ds.tsv")