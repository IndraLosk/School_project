#python3 letter_starter.py ivan.petrov@corp.com

import sys
def starter(email):
    with open("employees.tsv", "r") as file:
        lines = file.readlines()
        for line in lines:
            row = line.strip().split("\t")
            if row[2] == email:
                print(f'Dear {row[0]}, welcome to our team. We are sure that it will be a pleasure to work with you.' 
                      'That’s a precondition for the professionals that our company hires.')



if __name__ == "__main__":
    if(len(sys.argv) == 2):
        starter(sys.argv[1])