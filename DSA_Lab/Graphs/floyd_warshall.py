def floyd_warshall(matrix):
    dist = []
    for x in matrix:
        row = x[:]
        dist.append(row)

    V = len(matrix)
    for k in range(V):
        for i in range(V):
            for j in range(V):
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

    return dist            


def matrix():
    matrix = []
    for i in range(3):
        row = []
        for j in range(3):
            value = int(input(f"Enter the {i}th row and {j}th column\n"))
            row.append(value)
        matrix.append(row)

    return matrix


required_matrix = matrix()
print("Matrix before Floyd-Warshall:")
for row in required_matrix:
    print(row)

tree = floyd_warshall(required_matrix)
print("\nMatrix after Floyd-Warshall:")
for row in tree:
    print(row)



# list = [13,4,53,5,34,3,54,34]


# new_value = list[:]
# print(new_value)


# lists = [[1,2,3], [2,3,5] , [3,5,6]]

# actual_list = []
# for row in lists:
#     new_lists = row[:]
#     actual_list.append(new_lists)

# print(actual_list)

# # new_list = lists[:]

# # print(new_list)