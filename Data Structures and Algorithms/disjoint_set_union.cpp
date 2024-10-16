/*
    Disjoint Set Union (DSU) or Union Find Data Structure
    
    Provides three operations in O(1) average time
    -> make_set(v) : create a new set which contains the element v
    -> find_set(v) : returns the set representative/leader of the set to which element v exists
    -> union_sets(u, v) : combines the two sets which contain element u and v resepectively
*/
#include<iostream>
#include<vector>

using namespace std;

int parent[100000]; // parent array which stores all the dsu information
int tree_size[100000]; // used in the union by rank optimization

/*
    Naive Implementation of the DSU
*/
void make_set(int v){
    parent[v] = v;
    tree_size[v] = 1; // used in the union by rank optimization
}

// This naive implementation would take O(n) time in the worst case
int find_set(int v){
    if(parent[v] == v){
        return v;
    }

    return find_set(parent[v]);
}

void union_sets(int u, int v){
    u = find_set(u);
    v = find_set(v);

    if(u != v){
        parent[u] = v;
    }
}

/*
    Optimization-1 Path compression (speed up find_set)

    This optimization alone makes the queries to find_set(v) on average take O(logN)
*/
int find_set_pc(int v){
    if(parent[v] == v){
        return v;
    }

    // compress the path when you backtrack the recursion for all the nodes in the path
    // from v to the set representative, this makes queries in future very efficient
    return parent[v] = find_set_pc(parent[v]);
}

void union_sets_rank(int u, int v){
    u = find_set_pc(u);
    v = find_set_pc(v);

    if(u != v){
        // merge tree with lower rank to tree with higher rank
        if(tree_size[u] <= tree_size[v]){
            parent[u] = v;
            tree_size[v] += tree_size[u];
        }
        else{
            parent[v] = u;
            tree_size[u] += tree_size[v];
        }
    }
}



