##
## EPITECH PROJECT, 2020
## experiencePython
## File description:
## main
##

import sys
from DijkstraModule import *

def main():
    g = classes.Graph.Graph()
    g.add_vertex('a')
    g.add_vertex('b')
    g.add_vertex('c')
    g.add_vertex('d')
    g.add_vertex('e')
    g.add_vertex('f')
    g.add_edge('a', 'b', 7)
    g.add_edge('a', 'c', 9)
    g.add_edge('a', 'f', 14)
    g.add_edge('b', 'c', 10)
    g.add_edge('b', 'd', 15)
    g.add_edge('c', 'd', 11)
    g.add_edge('c', 'f', 2)
    g.add_edge('d', 'e', 6)
    g.add_edge('e', 'f', 9)

    print('Graph data:')
    for v in g:
        for w in v.get_connections():
            vid = v.get_id()
            wid = w.get_id()
            print(f'({vid}, {wid}, {v.get_weight(w)})')
    try:
        algorithm.Dijkstra.dijkstra(g, g.get_vertex('a'), g.get_vertex('e'))
    except error.DijkstraError.DijkstraError:
        print("An error occured, abort program", file=sys.stderr)
        sys.exit(84)
    target = g.get_vertex('e')
    path = [target.get_id()]
    algorithm.Dijkstra.shortest(target, path)
    print(f'The shortest path : {path[::-1]}')
    sys.exit(0)

if __name__ == '__main__':
    main()