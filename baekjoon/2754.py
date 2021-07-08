# 2754

# solution 1
"""
grade = {
    "A+": 4.3, "A0": 4.0, "A-": 3.7,
    "B+": 3.3, "B0": 3.0, "B-": 2.7,
    "C+": 2.3, "C0": 2.0, "C-": 1.7,
    "D+": 1.3, "D0": 1.0, "D-": 0.7,
    "F" : 0.0
}

print(grade[input()])
"""

# solution 2
basic_grade = {
    'A': 4.0, 'B': 3.0, 'C': 2.0, 'D': 1.0, 'F': 0.0
}
op = {
    '+': 0.3, '0': 0.0, '-': -0.3
}

letter_grade = input() + '0'
print(float(basic_grade[letter_grade[0]]) + float(op[letter_grade[1]]))