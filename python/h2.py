import copy

pacman_x, pacman_y = list(map(int, input().split()))
food_x, food_y = list(map(int, input().split()))
n, m = list(map(int, input().split()))
grid = []
queue = []
answer_routes = None

for i in range(0, n):
    grid.append(list(map(str, input())))

directions = [[-1, 0], [0, -1], [0, 1], [1, 0]]

queue.append([pacman_x, pacman_y, []])
while len(queue) > 0:
    x, y, r = queue.pop(0)
    routes = copy.deepcopy(r)
    routes.append([x, y])

    #ljknsagja;sgj

    if x == food_x and y == food_y:
        if answer_routes == None:
            answer_routes = routes
            break 

    possible_moves = []
    for direction in directions:
        next_x, next_y = x + direction[0], y + direction[1]
        if next_x < 0 or next_x >= n or next_y < 0 and next_y >= n:
            continue 



