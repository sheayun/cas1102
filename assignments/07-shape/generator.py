import random
from string import ascii_lowercase as alphabet

n = random.randint(1, 5)
print (n)

for i in range(n):
    t = random.choice(['C', 'R', 'T'])
    name = "".join(random.choice(alphabet) for _ in range(random.randint(1, 10)))
    c = "".join(random.choice(alphabet) for _ in range(random.randint(1, 10)))
    if t == 'C':
        print("C", name, c, random.randint(1, 1000))
    elif t == 'R':
        print("R", name, c, random.randint(1, 1000), random.randint(1, 1000))
    else:
        print("T", name, c, random.randint(1, 1000), random.randint(1, 1000))
