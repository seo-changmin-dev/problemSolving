import sys

sys.stdin = open("./datas/ex_046_input.txt", 'r', encoding="utf-8")

ret = sum(map(lambda x: 4-ord(x)+ord('A'), input()))
print(ret)
