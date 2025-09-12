import sys
def encode(text, shift):
    for char in text:
        if ord(char) >= 65 and ord(char) <= 90:
            new_char = (ord(char) - 65 + shift % 26) % 26 + 65
            print(chr(new_char), end = "")

        elif ord(char) >= 97 and ord(char) <= 122:
            new_char = (ord(char) - 97 + shift % 26) % 26 + 97
            print(chr(new_char), end = "")
        
        else:
            print(char, end = "")

    print()

def decode(text, shift):
    encode(text, -shift)

if __name__ == "__main__":

    if(len(sys.argv) == 4):
        if(sys.argv[1] == "encode"):
            encode (sys.argv[2], int(sys.argv[3]))
        elif(sys.argv[1] == "decode"):
            decode (sys.argv[2], int(sys.argv[3]))