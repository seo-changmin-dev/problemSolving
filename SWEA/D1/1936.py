def right_win(a: int, b: int) -> bool:
    if a == 1 and b == 2: return True
    if a == 2 and b == 3: return True
    if a == 3 and b == 1: return True
    return False


a, b = map(int, input().split())
if right_win(a, b):
    print("B")
else:
    print("A")