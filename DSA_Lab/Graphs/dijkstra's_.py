G = {
    's':{'t':10, 'y':5},
    't':{'x':1, 'y':2},
    'x':{'z':4},
    'y':{'x':9, 'z':2, 't':3},
    'z':{'x':6, 's':7},
}
import math

def INITIALIZE_SINGLE_SOURCE(G,s):
    cost = dict()
    prev = dict()
    for vertex in G.keys():
        cost[vertex] = math.inf
        prev[vertex] = ""
    cost[s] = 0
    return cost , prev


def RELAX(G, u , v , cost , prev):
    if cost[v]>cost[u]+G[u][v]:
        cost[v] = cost[u] + G[u][v]
        prev[v] = u

    return cost , prev


from queue import PriorityQueue

def DJ(G , s):
    cost , prev = INITIALIZE_SINGLE_SOURCE(G , s)
    PQ = PriorityQueue()
    for vertex in G.keys():
        PQ.put((cost[vertex] , vertex))
    visited = []
    while(len(visited) != len(G.keys())):
        _ , currentVertex = PQ.get()
        visited.append(currentVertex)
        for chimeki in G[currentVertex].keys():
            if chimeki not in visited:
                cost, prev = RELAX(G , currentVertex, chimeki, cost, prev)
                PQ.put((cost[chimeki] , chimeki))
    return cost , prev



s = 's'
cost , prev = DJ(G , s)
print(cost)
print(prev)



def RECONSTRUCT_PATH(vertex , prev):
    path = vertex
    while prev[vertex] != "":
        path = prev[vertex] + '->' + path
        vertex = prev[vertex]
    return path

s = 's'
cost , prev = DJ(G , s)
for vertex in G.keys():
    print(f"The shortest path from {s} to {vertex} is {RECONSTRUCT_PATH(vertex , prev )}")
    print(f"Cost is {cost[vertex]}")