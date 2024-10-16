/*
    Cycle detection can be done using both BFS and DFS (consider only undirected graphs for now)

    DFS - save space but time is more
    -> search for cycles recursively along with tracking the length of the path 

    BFS - save time but space is more
    -> go level by level and after you reach the desired level check if the next neighbour is the root node
    which started the search
*/