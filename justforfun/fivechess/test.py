import fivechesslib
from fivechesslib import BLACK_CHESS, NOBODY_WIN, WHITE_CHESS, NOTHING, BLACK_WIN, WHITE_WIN, RIGHT_SLASH_WIN

chess_board = [
    [NOTHING, NOTHING, BLACK_CHESS, NOTHING, BLACK_CHESS, NOTHING],
    [NOTHING, NOTHING, BLACK_CHESS, BLACK_CHESS, NOTHING, NOTHING],
    [NOTHING, NOTHING, NOTHING, NOTHING, NOTHING, NOTHING],
    [NOTHING, BLACK_CHESS, NOTHING, WHITE_CHESS, NOTHING, NOTHING],
    [NOTHING, NOTHING, BLACK_CHESS, NOTHING, WHITE_CHESS, WHITE_CHESS],           
    [BLACK_CHESS, NOTHING, WHITE_CHESS, WHITE_CHESS, WHITE_CHESS, NOTHING]
]

assert fivechesslib.check_win(chess_board) == [WHITE_WIN, RIGHT_SLASH_WIN]
print('pass!')