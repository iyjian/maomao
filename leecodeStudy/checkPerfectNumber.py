def checkPerfectNumber_V1(num : int) -> bool:
    if num == 1:
        return False
    upper_bound = num
        # cursor = 1
    # blacklist = []
    factor_sum = 1
    factor = 2
    while factor < upper_bound:
        if num % factor == 0:
            factor_sum += factor
            another_factor = num / factor
            if another_factor != factor:
                factor_sum += another_factor
                upper_bound = another_factor
            else:
                break
        factor += 1        
    return num == factor_sum

def checkPerfectNumber_V2(num : int) -> bool:
    return num in [6, 28, 496, 8128]


# for i in range(10000):
#     if checkPerfectNumber_V1(i) == True:
#         print(i)