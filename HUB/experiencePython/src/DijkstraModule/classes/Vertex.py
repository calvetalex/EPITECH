##
## EPITECH PROJECT, 2020
## experiencePython
## File description:
## Vertex
##

from sys import maxsize

##
## class Vertex
## represents each vertex in the graph. It will keep the total cost from the start node to each destination in a distance variable
## variables:
##      self.adjacent: list of adjacent nodes
##      self.distance: cost from the start node to the destination. default: maxsize (maximum value possible)
##      self.visited: boolean to keep in mind which node is already used
##      self.previous: node at the previous state
## functions;
##      add_neighbor: add a node to the adjency list
##      get_connections: return the adjency list
##      get_id: return current node id
##      get_weight: get cost for going to another node
##      get_distance: return the current value of the distance variable
##      set_distance: update the value of the distance variable
##      set_previous: update the previous node id
##      set_visited: update node status
##

class Vertex:
    def __init__(self, node):
        self.id = node
        self.adjacent = {}
        self.distance = maxsize
        self.visited = False
        self.previous = None


    def __lt__(self, other):
        return (self.distance, self.previous) < (other.distance, other.previous)


    def __lt__(self, other):
        return (self.distance, self.previous) > (other.distance, other.previous)


    def __repr__(self):
        return "Vertex()"


    def __str__(self):
        return str(self.id) + ' neighbors: ' + str([x.id for x in self.adjacent])


    def add_neighbor(self, neighbor, weight=0):
        self.adjacent[neighbor] = weight


    def get_connections(self):
        return self.adjacent.keys()


    def get_id(self):
        return self.id


    def get_weight(self, neighbor):
        return self.adjacent[neighbor]


    def set_distance(self, dist):
        self.distance = dist


    def get_distance(self):
        return self.distance


    def set_previous(self, prev):
        self.previous = prev


    def set_visited(self):
        self.visited = True