##
## EPITECH PROJECT, 2020
## experiencePython
## File description:
## Djikstra
##

import sys
import heapq
from ..classes import Graph
from ..classes import Vertex
from ..error import DijkstraError


##
## shortest(v, path)
## Make shortest path from previous node
## params:
##      v: Vertex instance
##      path: list of nodes' id
## no return
##
def shortest(v, path):
    if v.previous:
        path.append(v.previous.get_id())
        shortest(v.previous, path)


##
## dijkstra(aGraph, start, target)
## take all Vertices from start to find the target in aGraph
## params:
##      aGraph: Graph instance used by algorithm
##      start: Vertex to begin with
##      taget: Vertex to find
## no return
##
def dijkstra(aGraph, start, target):
    start.set_distance(0)
    unvisited_queue = [(v.get_distance(),v) for v in aGraph]
    heapq.heapify(unvisited_queue)
    try:
        while len(unvisited_queue):
            uv = heapq.heappop(unvisited_queue)
            current = uv[1]
            current.set_visited()
            for next in current.adjacent:
                if next.visited:
                    continue
                new_dist = current.get_distance() + current.get_weight(next)
                if new_dist < next.get_distance():
                    next.set_distance(new_dist)
                    next.set_previous(current)
                    print(f'Update: current = {current.get_id()} | next = {next.get_id()} | new distance -> {next.get_distance()}')
                else:
                    print(f'No update: current = {current.get_id()} | next = {next.get_id()} | new distance -> {next.get_distance()}')
            while len(unvisited_queue):
                heapq.heappop(unvisited_queue)
            unvisited_queue = [(v.get_distance(),v) for v in aGraph if not v.visited]
            heapq.heapify(unvisited_queue)
    except Exception:
        raise DijkstraError