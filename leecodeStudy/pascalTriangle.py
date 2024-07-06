import math
# C(n,m)= n! / m!(n−m)!


def combination(n : int, m : int) -> int:
    return int(math.factorial(n) / (math.factorial(m) * math.factorial(n - m)))

print(combination(1, 1))
print(combination(5, 2))
print(combination(115, 3))