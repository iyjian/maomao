BLACK_WIN = 1
WHITE_WIN = 2
NOBODY_WIN = 0
BLACK_CHESS = 1
WHITE_CHESS = 2
NOTHING = 0

# [BLACK_CHESS, BLACK_CHESS, BLACK_CHESS, BLACK_CHESS, BLACK_CHESS, NOTHING, WHITE_CHESS, BLACK_CHESS, BLACK_CHESS, BLACK_CHESS]
def __check_win_line__(line):
  # this is a private function, you don't have to use it 
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
      print('error : chess board is falty')
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


def __check_win_lying_flat__(chess_board):
  # this is a private function, you don't have to use it 
  for i in chess_board:
    if __check_win_line__(i) == NOBODY_WIN:
      continue
    elif __check_win_line__(i) == BLACK_WIN:
      return BLACK_WIN
    else:
      return WHITE_WIN
  return NOBODY_WIN

def __check_win_vertically__(chess_board):
  # this is a private function, you don't have to use it 
  chess_board_length = len(chess_board[1])
  vertical_chess_board = []
  for i in range(chess_board_length):
    vertical_chess_board.append([])
  for k in range(chess_board_length):
    for j in chess_board:
      vertical_chess_board[k].append(j[k])
  return __check_win_lying_flat__(vertical_chess_board)

def __check_win_left_slash__(chess_board):
  chess_board_len = len(chess_board)
  slash_numbers = 2 * chess_board_len - 1
