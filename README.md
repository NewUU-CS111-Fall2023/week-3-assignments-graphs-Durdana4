# Description of the project
In this assignment you will practive data types in C++ and Python. \
It is up to you to choose programming language for the task, however one PL **may not** cover more than 70% of all tasks.

You may use **google colab** for the assignment and export it as .py file, then put the file to **src\py** directory.

_Before submitting, make sure the code is running with no errors._

## Tasks:

### 1. Depth First Search or DFS for a Graph.
   Depth First Traversal (or DFS) for a graph is similar to Depth First Traversal of a tree.
   The only catch here is, that, unlike trees, graphs may contain cycles (a node may be visited twice).
   To avoid processing a node more than once, use a boolean visited array. A graph can have more than one DFS traversal.

### 2. Shortest path in a Binary Maze.
   Given an MxN matrix where each element can either be 0 or 1. 
   We need to find the shortest path between a given source cell to a destination cell.
   The path can only be created out of a cell if its value is 1.
### 3. Print all paths from a given source to a destination
   Given a directed graph, a source vertex ‘s’ and a destination vertex ‘d’,
   print all paths from given ‘s’ to ‘d’. Consider the following directed graph.
   Let the s be 2 and d be 3. There are 3 different paths from 2 to 3.
### 4. Find the number of islands using DFS
   Given a binary 2D matrix, find the number of islands.
   A group of connected 1s forms an island.
   For example, the below matrix contains 4 islands.
### 5. Find Shortest Paths from Source to all Vertices 
   Given a graph and a source vertex in the graph, 
   find the shortest paths from the source to all vertices in the given graph using Dijkstra’s Algorithm.






## Project structure
Design your project structure wisely, so that your source code do not overlap and conflict. \
Here is an example:

- `cpp` - c++ files header files (.cpp, .h files).
- `py` - python source code (.py)

```
MyProject
 ├── cpp
 │   ├── main.cpp
 │   └── fibboalgo.h
 └── py
     ├── main.py
     └── algo1.py
```
