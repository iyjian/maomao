import mazelib

# print(lib.maze)
# print(maze)
# print(maze_arry[0][0])

start_point = [0, 0]
end_point = [4, 5]

path = []

current_point = start_point
loops = 0

while current_point != end_point:

    tried_directions = 0
    for direction in range(1, 5):
        next_point = mazelib.go_direction(current_point, direction)
        if next_point != [-1, -1] and not mazelib.is_tried(current_point, direction) and next_point not in path:
            # print('next_point', next_point, direction)
            mazelib.mark_as_tried(current_point, direction)
            current_point = next_point
            path.append(next_point)
            print('go', next_point)
            break
        tried_directions += 1
    
    if tried_directions == 4:
        # if we tried all directions, but no valid direction
        pop_point = path.pop()
        current_point = path[len(path) -1]
        print('back', pop_point)

    # if loops > 20:
    #     break

    loops += 1
    
print(path)