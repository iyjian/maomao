from typing import List




def isHappy(n: int) -> bool:
    n2 = n
    blacklist = []
    while n2 != 1:
        if n2 in blacklist:
            return False                
        blacklist.append(n2)
        n2 = sum([int(digit) ** 2 for digit in str(n2)])
    return True

        

    
print(isHappy(19))
print(isHappy(2))
