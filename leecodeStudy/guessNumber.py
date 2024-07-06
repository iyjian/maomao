from typing import List

def game(guess: List[int], answer: List[int]) -> int:
    rightTime = 0
    for i in range(3):
        if guess[i] == answer[i]:
            rightTime += 1
    return rightTime


print(game([1, 2, 3], [1, 2, 3]))
print(game([2, 2, 3], [3, 2, 1]))