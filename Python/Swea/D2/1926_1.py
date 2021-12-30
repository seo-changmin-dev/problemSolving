# solve with recursive function

import sys

sys.stdin = open("./datas/input.txt", 'r')

def go(i: int, N: int) -> None:
    if i > N: return

    ret = 0
    for c in str(i):
        if c in ['3', '6', '9']: ret += 1

    if ret == 0: print(i, end=' ')
    else: print('-'*ret, end=' ')

    return go(i+1, N)

go(1, int(input()))
