import math

G = {
    'a':{'b':12, 'd':5},
    'b':{'d':2, 'c':1},
    'c':{'e':5},
    'd':{'c':13, 'b':6, 'e':2},
    'e':{'c':3, 'a':5}
}

input_vertex = input("Enter the starting vertex: ")

def Prims(G , start):
    min_spanning = {}
    min_spanning[start] = {'cost': 0, 'parent': None}
    visited = []
    visited.append(start)
    while len(visited) < len(G):
        min_edge_value = math.inf
        min_node = None 
        for everyNode in visited:
            for chimeki in G[everyNode]:
                if chimeki not in visited and G[everyNode][chimeki] < min_edge_value:
                    min_edge_value = G[everyNode][chimeki]
                    min_node = chimeki
                    realParent = everyNode
                    
        visited.append(min_node)
        min_spanning[min_node] = {'cost': min_edge_value, 'parent': realParent}
        
    return min_spanning

result = Prims(G, input_vertex)

def print_result(result):
    totalCost = 0
    print("Minimum Spanning Tree:")
    for node in result:
        parent = result[node]['parent']
        cost = result[node]['cost']
        totalCost += cost
        if parent is not None:
            print(f"Parent is {parent} , Node is {node} , Cost is {cost}")
    print("minimum spanning tree total cost is " , totalCost)
    
print_result(result)