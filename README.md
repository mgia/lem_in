# lem_in : Path-finding algorithm

### In this project, we guide ants through the ant farm.
 The 'ant farm' is an undirected graph, with vertexes as 'rooms' and egdes as 'links'.

## Solution

Our solution uses **Breadth-First Search (BFS)** to find the shortest paths from start room to end room. We then implement 'flood fill' to push as many ants into the farm as possible.

On each turn, every ant is given a 'map' of the farm, as well as the path it should take. It will then determine whether to move (if the next room is empty), or to wait its turn (if the next room is full).

## Input
The program receives input in the following format:

    number_of_ants
    the_rooms
    the_links

After parsing, the ant farm will look as such:

                     ______________
                  /                 \
          ______[5]----[3]----[1]   |
        /               |     /     |
       [6]-----[0]-----[4]   /      |
        \    _________/ |   /       |
         \ /           [2]/________/
         [7]_________ /
       
       Start room: 4
       End room: 1
       Number of ants: 3

## Output
The program prints how the ants move:
    
    L1-3 L2-2 (Ant 1 to room 3, Ant 2 to room 2)
    L1-1 L2-1 L3-3 (Ant 1 to room 1, Ant 2 to room 1, Ant 3 to room 3)
    L3-1 (Ant 3 to room 1)

## Score
100/100
