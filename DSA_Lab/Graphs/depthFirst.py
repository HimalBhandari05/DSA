graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [],
    'E': ['F'],
    'F': []
}
def dft(graph , start):
    stack = []
    visited = []
    stack.append(start)
    while stack:
        visited_value = stack.pop()
        visited.append(visited_value)
        for adj_vert in graph[visited_value]:
            if adj_vert not in stack and adj_vert not in visited:
                stack.append(adj_vert)
        
    return visited
            
        
returned_list = dft(graph ,'A')
print(returned_list)