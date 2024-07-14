import mazelib

def is_end_point(maze_arr, current_point):
    maze_height = len(maze_arr)
    maze_width = len(maze_arr[0])
    return ((maze_height or maze_width or 0) in current_point) or (current_point != [0, 0])
        
def escape_the_maze(start_point):
    path = []
    current_point = start_point
    loops = 0

    while is_end_point(mazelib.maze_arr, current_point, start_point) == True and loops != 0:
        tried_directions = 0
        for direction in range(1, 5):
            next_point = mazelib.go_direction(current_point, direction)

            if next_point != [-1, -1] and not mazelib.is_tried(current_point, direction) and next_point not in path:
                # print('next_point', next_point, direction)
                mazelib.mark_as_tried(current_point, direction)
                current_point = next_point
                path.append(next_point)
                break
            tried_directions += 1
        
        if tried_directions == 4:
            # if we tried all directions, but no valid direction
            path.pop()
            current_point = path[len(path) -1]
        loops += 1
    return path 

print(escape_the_maze([4, 0]))