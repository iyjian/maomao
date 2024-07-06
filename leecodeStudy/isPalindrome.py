# 回文数判断方法
# 若一个数字或字符串正序（从左向右）和倒序（从右向左）读都是一样的 它就是回文数
def isPalindrome(x : int) -> bool:
    return str(x) ==  str(x)[:-1]


print(isPalindrome(121))