from typing import List
import math
def checkPrimeNumber(num : int) -> bool:
    for maybe_factor in range(2, math.ceil(num / 2)):
        if num % maybe_factor == 0:
            return False
    return True

# def primeFactorization(num : int) -> 


