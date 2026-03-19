import random

u = input()
a, b, c = (int(d) for d in u.split())

# Mat1 : a * b
# Mat2 : b * c

def printMat(Mat):
    result = []
    for i in range(len(Mat)):
        result.append(" ".join(str(x) for x in Mat[i]))
    return "\n".join(result)

Mat1 = [[random.randint(-10, 10) for x in range(b)] for y in range(a)]
Mat2 = [[random.randint(-10, 10) for x in range(c)] for y in range(b)]

Answer = [[None for x in range(c)] for y in range(a)]
for i in range(a):
    for j in range(c):
        sum = 0
        for k in range(b):
            sum += Mat1[i][k] * Mat2[k][j]
        Answer[i][j] = sum

with open("input.txt", "w") as f_in:
    f_in.write(f"{a} {b} {c}\n")
    f_in.write(printMat(Mat1) + "\n")
    f_in.write(printMat(Mat2) + "\n")

with open("output.txt", "w") as f_out:
    f_out.write(printMat(Answer) + "\n")
