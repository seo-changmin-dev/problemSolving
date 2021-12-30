import sys

sys.stdin = open("./datas/input.txt", 'r')


def clap(x: str) -> str:
    total = 0
    for c in x:
        if c in ['3', '6', '9']: total += 1

    if total == 0: return x
    else: return '-'*total


for i in range(1, int(input())+1):
    print(clap(str(i)), end=" ")
