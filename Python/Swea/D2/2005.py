import sys

sys.stdin = open("./datas/input.txt", 'r')

dp = [[None] * 10 for _ in range(10)]
for i in range(10):
    dp[i][0] = dp[i][i] = 1

for i in range(1, 10):
    for j in range(1, 10):
        if dp[i - 1][j - 1] is not None and dp[i - 1][j] is not None:
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]

T = int(input())
for tc in range(1, T + 1):
    print(f"#{tc}")
    n = int(input())
    for row in dp:
        result = [x for x in row if x is not None]
        print(*result)
