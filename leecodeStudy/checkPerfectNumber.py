# leecode 507

class CheckPerfectNumber_Solution:
    def checkPerfectNumber_V1(self, num : int) -> bool:
        if num == 1:
            return False
        upper_bound = num
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

    def checkPerfectNumber_V2(self, num : int) -> bool:
        return num in [6, 28, 496, 8128, 33550336]
