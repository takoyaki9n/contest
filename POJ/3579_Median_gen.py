import random

MAX_N = 100000
MAX_X = 1000000000

CASES = 10

N = 10
X = 10

for _ in range(CASES):
    print(N)
    for _ in range(N):
        print(random.randint(1, X), end = " ")
    print("")
