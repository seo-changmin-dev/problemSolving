# 1120
import sys


# length: X <= Y
def string_diff(X, Y):
    x_len = len(X)
    diff = 0

    for i in range(x_len):
        if X[i] != Y[i]:
            diff += 1

    return diff


A, B = sys.stdin.readline().rstrip().split()

A_len, B_len = len(A), len(B)
ret = 987654321

for i in range(B_len - A_len + 1):
    concatenated_A = B[0:i] + A + B[i + A_len:B_len + 1]
    ret = min(ret, string_diff(concatenated_A, B))

print(ret)
