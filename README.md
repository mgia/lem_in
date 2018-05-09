# lem_in : Path-finding algorithm

### In this project, we implement a path-finding algorithm to guide ants through the ant farm.
### The 'ant farm' is an undirected graph, with vertexes as 'rooms' and egdes as 'links'.

## Solution

Our solution uses **Breadth-First Search (BFS)** to find the shortest paths from start room to end room. We then implement 'flood fill' to push as many ants into the farm as possible.

On each turn, every any is given a 'map' of the farm, as well as the path it should take. It will then determine whether to move (if the next room is empty), or to wait its turn (if the next room is full).

## Input
The program receives input in the following format:

    number_of_ants
    the_rooms
    the_links

The ant farm is defined as such:
  
    ##start
    1 23 3
    2 16 7
    #comment
    3 16 3
    4 16 5
    5 9 3
    6 1 5
    7 4 8 
    ##end
    0 9 5
    0-4
    0-6
    1-3
    4-3
    5-2
    3-5
    #another comment
    4-2
    2-1
    7-6
    7-2
    7-4
    6-5
    
Which corresponds to the following representation:

                     ______________
                  /                 \
          ______[5]----[3]----[1]   |
        /               |     /     |
       [6]-----[0]-----[4]   /      |
        \    _________/ |   /       |
         \ /           [2]/________/
         [7]_________ /

## Output
The program prints the moves. (e.g. L1-3 => Ant number 1 to room 3)
    
    L1-3 L2-2
    L1-1 L2-1 L3-3
    L3-1

## Score
100/100
