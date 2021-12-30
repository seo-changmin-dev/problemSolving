import sys

sys.stdin = open("./datas/sample_input.txt")
T = int(input())
for tc in range(1, T+1):
    N = int(input())

    a = [0 for _ in range(10)]
    for e in input():
        a[ord(e)-ord('0')] += 1

    m = max(a)
    for i in range(9, -1, -1):
        if a[i] == m:
            print(f"#{tc} {i} {m}")
            break
