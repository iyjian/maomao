from typing import List

maze = """001111
100101
100001
101101
001100
111111"""


def change_arr(maze) -> List[List[str]]:
    return [list(line)  for line in maze.split('\n')]

maze_arr = change_arr(maze)

maze_height = len(maze_arr)
maze_width = len(maze_arr[0])

point_statistic = {}

# direction can be 1(up),2(down),3(left),4(right)
# return the next pint, if there is no 
def go_direction(point, direction):
    [x, y] = point
    if direction == 3:
        y -= 1
        if y < 0 or maze_arr[x][y] == '1':
            return [-1, -1]
    elif direction == 4:
        y += 1
        if y > maze_height - 1 or maze_arr[x][y] == '1':
            return [-1, -1]
    elif direction == 1:
        x -= 1
        if x < 0 or maze_arr[x][y] == '1':
            return [-1, -1]
    elif direction == 2:
        x += 1
        if x > maze_width - 1 or maze_arr[x][y] == '1':
            return [-1, -1]
    return [x, y]

def mark_as_tried(point, direction):
    key = f'{point[0]}-{point[1]}'
    if key in point_statistic:
        point_statistic[key].append(direction)
    else:
        point_statistic[key] = [direction]

def is_tried(point, direction):
    key = f'{point[0]}-{point[1]}'
    if key not in point_statistic:
        return False
    else:
        return direction in point_statistic[key]