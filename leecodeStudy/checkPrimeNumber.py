import random

def checkPrimeNumber(num : int) -> bool:
    a = random.randint(1, num)
    if [a ** (num - 1)] % num == 1:
        return True
    else:
        return False