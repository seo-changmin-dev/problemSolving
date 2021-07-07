# 10162
T = int(input())
A, B, C = 300, 60, 10

if T%C != 0: print(-1)
else:
    print(T//A, (T%A)//B, (T%B)//C)