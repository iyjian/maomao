BLACK_WIN = 1
WHITE_WIN = 2
NOBODY_WIN = 0
BLACK_CHESS = 1
WHITE_CHESS = 2
NOTHING = 0
LEFT_SLASH_WIN = 4
RIGHT_SLASH_WIN = 3
LYING_FLAT_WIN = 2
VERTICALLY_WIN = 1
IN_NO_WAY = 0


def __check_win_line__(line):
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
  for i in chess_board:
    if __check_win_line__(i) == NOBODY_WIN:
      continue
    elif __check_win_line__(i) == BLACK_WIN:
      return BLACK_WIN
    else:
      return WHITE_WIN
  return NOBODY_WIN

def __check_win_vertically__(chess_board):
  chess_board_length = len(chess_board)
  vertical_chess_board = []
  for i in range(chess_board_length):
    vertical_chess_board.append([])
  for k in range(chess_board_length):
    for j in chess_board:
      vertical_chess_board[k].append(j[k])
  return __check_win_lying_flat__(vertical_chess_board)

def __get_left_slash_coordinate_arr__(chess_board, slash_number):
  length_of_chess_board = len(chess_board)
  slash_array = []
  if slash_number <= length_of_chess_board - 1:
    for i in range(slash_number + 1):
      slash_array.append(chess_board[i][slash_number - i])
  elif slash_number > length_of_chess_board - 1:
    for i in range((slash_number - length_of_chess_board + 1), (- slash_number + 2 * length_of_chess_board + 2)):
      slash_array.append(chess_board[i][slash_number - i])
  else:
    print('error : slash_number is not right')
    raise
  return slash_array

def __get_left_slashes__(chess_board):
  length_of_chess_board = len(chess_board)
  slash_chess_board = []
  for slash_number in range(length_of_chess_board):
    slash_chess_board.append(__get_left_slash_coordinate_arr__(chess_board, slash_number))
  return slash_chess_board


def __check_win_left_slash__(chess_board):
  return __check_win_lying_flat__(__get_left_slashes__(chess_board))

def __get_right_slash_arr__(chess_board, slash_num):
  length_of_chess_board = len(chess_board)
  slash_line = []
  if slash_num <= length_of_chess_board - 1:
    for i in range(slash_num + 1):
      slash_line.append(chess_board[i][i + length_of_chess_board - 1 - slash_num])
    return slash_line
  elif slash_num > length_of_chess_board - 1:
    gap = slash_num + 1 - length_of_chess_board
    i = gap
    while i < length_of_chess_board:
      slash_line.append(chess_board[i][i + length_of_chess_board - 1 - slash_num])
      i += 1
    return slash_line
  
def __get_right_slashes__(chess_board):
  length_of_chess_board = len(chess_board)
  slash_chess_board = []
  for slash_number in range(length_of_chess_board):
    slash_chess_board.append(__get_right_slash_arr__(chess_board, slash_number))
  return slash_chess_board

def __check_win_right_slash__(chess_board):
  return __check_win_lying_flat__(__get_right_slashes__(chess_board))



def check_win(chess_board):
  # __check_win_lying_flat__(chess_board)
  # __check_win_vertically__(chess_board)
  # __check_win_left_slash__(chess_board)
  # __check_win_right_slash__(chess_board)
  lying_flat = [__check_win_lying_flat__(chess_board), LYING_FLAT_WIN]
  vertically = [__check_win_vertically__(chess_board), VERTICALLY_WIN]
  left_slash = [__check_win_left_slash__(chess_board), LEFT_SLASH_WIN]
  right_slash = [__check_win_right_slash__(chess_board), RIGHT_SLASH_WIN]
  for i in [lying_flat, vertically, left_slash, right_slash]:
    if i[0] != NOBODY_WIN:
      return i
  return[NOBODY_WIN, IN_NO_WAY]


