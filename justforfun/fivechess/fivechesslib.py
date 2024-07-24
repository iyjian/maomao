BLACK_WIN = 1
WHITE_WIN = 2
NOBODY_WIN = 0
BLACK_CHESS = 1
WHITE_CHESS = 2
NOTHING = 0

# [BLACK_CHESS, BLACK_CHESS, BLACK_CHESS, BLACK_CHESS, BLACK_CHESS, NOTHING, WHITE_CHESS, BLACK_CHESS, BLACK_CHESS, BLACK_CHESS]
def check_win_line(line):
  black_chess_continue_num = 0
  white_chess_continue_num = 0
  
  for l in line:
    if l == BLACK_CHESS:
      black_chess_continue_num += 1
      white_chess_continue_num = 0
    elif l == WHITE_CHESS:
      white_chess_continue_num += 1
      black_chess_continue_num = 0
    elif l == NOTHING:
      black_chess_continue_num = 0
      white_chess_continue_num = 0
    else:
      raise

    if black_chess_continue_num < 5 and white_chess_continue_num < 5:
      continue
    elif black_chess_continue_num == 5:
      return BLACK_WIN
    elif white_chess_continue_num == 5:
      return WHITE_WIN
    else:
      raise

  return NOBODY_WIN
