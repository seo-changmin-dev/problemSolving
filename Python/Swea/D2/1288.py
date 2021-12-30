import sys

sys.stdin = open("./datas/sample_input.txt", 'r')

for tc in range(int(input())):
    N = int(input())

    visited = [False for _ in range(10)]

    cnt = 0
    curr = N

    while True:
        for e in str(curr): visited[int(e)] = True
        if False in visited: curr += N
        else: break

    print("#{} {}".format(tc+1, curr))
