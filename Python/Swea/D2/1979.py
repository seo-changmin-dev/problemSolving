import sys

sys.stdin = open("./datas/input.txt", 'r')

T = int(input())
for tc in range(1, T+1):
    N, K = map(int, input().split())

    board = [[] for _ in range(N)]
    for i in range(N):
        board[i] += map(str, input().split())

    ret = 0
    for i in range(N):
        ret += list(''.join(board[i]).split('0')).count('1'*K)

    for j in range(N):
        ret += list(''.join([board[i][j] for i in range(N)]).split('0')).count('1'*K)

    print(f"#{tc} {ret}")
