# Kruskal's Algorithm

edges = [
    ('A', 'B', 1),
    ('B', 'C', 2),
    ('A', 'C', 3),
    ('B', 'D', 4),
    ('C', 'D', 5)
]

edges.sort(key=lambda x:x[2])  # lamda arguments:expression (shorthand function)

def Kruskal(edges):
    parent = {}
    nodes = []
    minspanningtree = []
    
    for start , end , weight in edges:
        if start not in nodes:
            nodes.append(start)
        if end not in nodes:
            nodes.append(end)

    for node in nodes:
        parent[node] = node   # initially chai every node aafnei parent hunxa. 
        
    def find_root(node):
        while (parent[node] != node):
            parent[node] = parent[parent[node]] # path compress gareko.
            node = parent[node]
        return node

    for start , end , weight in edges:
        rootOfstart = find_root(start)
        rootOfend = find_root(end)
        
        if rootOfstart != rootOfend: # if root same aayo vaney ta cycle form hunxa ni ta.  so aayena vaney chai aauta lai arkaako parent banaune k 
            parent[rootOfend] = rootOfstart  
            minspanningtree.append((start , end , weight))
    return minspanningtree




returned_mst = Kruskal(edges)

def display(min_span_tree):
    for start , end , weight in min_span_tree:
        print(f"Start from {start} --- weight is  {weight} --- end to {end} ")

display(returned_mst)