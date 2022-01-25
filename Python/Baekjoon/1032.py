n = int(input())
data = [input() for _ in range(n)]

result = ''
for i in range(len(data[0])):
    is_common = True
    for j in range(1, n):
        if data[j-1][i] != data[j][i]:
            is_common = False
            break
    if(is_common):
        result = result + data[0][i]
    else:
        result = result + '?'

print(result)