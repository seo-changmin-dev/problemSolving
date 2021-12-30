N = int(input())

ret = set()
for i in range(1, int(N**0.5+1)):
    if N%i == 0:
        ret.add(i)
        ret.add(N//i)

print(' '.join(map(str, sorted(ret))))
