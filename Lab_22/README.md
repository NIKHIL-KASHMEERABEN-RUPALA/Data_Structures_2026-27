# Lab_22

-> Implementation goals
This lab implements a graph using the adjacency list representation, where every vertex maintains a linked list of its adjacent vertices (neighbors). This structure is memory-efficient for sparse graphs since it only stores edges that actually exist. On this graph, two fundamental traversal techniques are applied: Depth First Search (DFS), which explores as deep as possible along one path before backtracking (implemented using recursion), and Breadth First Search (BFS), which visits all neighbors level by level (implemented using a queue). A visited[] array is used in both to avoid revisiting vertices and prevent infinite loops. The program creates the graph, adds edges, prints the adjacency list, and displays the DFS and BFS traversal orders.

-> Aim
To create a graph, represent it using an adjacency list, and traverse it using DFS and BFS.
