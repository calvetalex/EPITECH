##
## EPITECH PROJECT, 2020
## experiencePython
## File description:
## Graph
##

from .Vertex import Vertex

##
## class Graph
## A graph is just a list of Vertices
## variables:
##      vert_dict: vertices list
## functions:
##      add_vertex: add a vertex element to the list
##      get_vertex: return vertex asked for, if not found return None
##      add_edge: create new vertex to take care of (required to get all paths)
##      get_verticies: return vertices list
##

class Graph:
    def __init__(self):
        self.vert_dict = {}


    def __iter__(self):
        return iter(self.vert_dict.values())


    def __repr__(self):
        return "Graph()"


    def add_vertex(self, node):
        new_vertex = Vertex(node)
        self.vert_dict[node] = new_vertex
        return new_vertex


    def get_vertex(self, n):
        if n in self.vert_dict:
            return self.vert_dict[n]
        else:
            return None


    def add_edge(self, frm, to, cost = 0):
        if frm not in self.vert_dict:
            self.add_vertex(frm)
        if to not in self.vert_dict:
            self.add_vertex(to)
        self.vert_dict[frm].add_neighbor(self.vert_dict[to], cost)
        self.vert_dict[to].add_neighbor(self.vert_dict[frm], cost)


    def get_vertices(self):
        return self.vert_dict.keys()


    def set_previous(self, current):
        self.previous = current


    def get_previous(self, current):
        return self.previous