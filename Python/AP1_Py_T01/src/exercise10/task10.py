def input_number():
    n, t = map(int, input().split())
    machines = [list(map(int, input().split())) for _ in range(n)]
    return n, t, machines

def choise(n, t, machines):
    parts = []
    for i in range(n):
        year = machines[i][0]
        for j in range(n):
            if i != j and year == machines[j][0] and machines[i][2] + machines[j][2] == t:
                parts.append((machines[i][1] + machines[j][1]))
    parts.sort()    
    print(parts[0])


if __name__ == "__main__":
    try:
        n, t, machines = input_number()
        choise(n, t, machines)
    except ValueError:
        print("Incorrect input")
    