import sys
from datetime import datetime

sys.stdin = open('datas/input.txt', 'r')

T = int(input())
for tc in range(T):
    # 1. datetime 모듈을 불러옴
    # 2. datetime 클래스 오브젝트로 변경
    # 3. 동작이 정의되어 있는 메서드를 불러옴
    try:
        date_obj = datetime.strptime(input(), "%Y%m%d")
        date_string = '/'.join(str(date_obj.date()).split('-'))
    except:
        date_string = -1
    print(f"#{tc+1} {date_string}")