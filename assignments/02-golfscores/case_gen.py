import random
from math import floor

PAR = [4] * 18

top = random.sample(range(9), 4)
PAR[top[0]] = 3
PAR[top[1]] = 3
PAR[top[2]] = 5
PAR[top[3]] = 5

bottom = random.sample(range(9, 18), 4)
PAR[bottom[0]] = 3
PAR[bottom[1]] = 3
PAR[bottom[2]] = 5
PAR[bottom[3]] = 5

print(" ".join(map(str, PAR)))

data = [[random.randint(-1, PAR[i]) for i in range(18)] for _ in range(4)]

print("\n".join(map(lambda x: " ".join(map(str, x)), data)))

'''
print(" Player    1    2    3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18 Total")
for p in range(4):
    print(f'      {p+1}', end=' ')
    total = 0
    for i, x in enumerate(data[p]):
        t = x + PAR[i]
        if t < 10:
            print(' ', end='')
        print(f'  {t}', end=' ')
        total += t
    if total < 100:
        print(' ', end='')
    print(f'  {total}')
print("Average", end=' ')
for i in range(18):
    avg = sum((data[p][i] + PAR[i]) for p in range(4)) / 4
    avg = floor(avg * 10 + 0.5) / 10
    if avg < 10:
        print(' ', end='')
    print(f'{avg:.1f}', end=' ')
print()
'''

for p in range(4):
    print(f'Player {p + 1}: {sum(data[p][i] + PAR[i] for i in range(18))}')

for i in range(18):
    avg = sum((data[p][i] + PAR[i]) for p in range(4)) / 4
    avg = floor(avg * 10 + 0.5) / 10
    print(f'Hole {i + 1}: {avg:.1f}')
