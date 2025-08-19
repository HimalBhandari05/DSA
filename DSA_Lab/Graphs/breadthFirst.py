graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [],
    'E': ['F'],
    'F': []
}
def bft(graph , start):
    queue = []
    visited = []
    queue.append(start)
    while queue:
        visited_value = queue.pop(0)
        visited.append(visited_value)
        for adj_vert in graph[visited_value]:
            if adj_vert not in queue and adj_vert not in visited:
                queue.append(adj_vert)
        
    return visited
        
returned_list = bft(graph ,'A')
print(returned_list)