#include<iostream>
#include<vector>

using namespace std;

/*
    Depth First Search
    -> recursively visit the connected component which contains the root node
    -> colors are used in different ways in different problems

    Time O(n+m) : every node is visited at most once
    Space O(n) : to store the color vector
*/
void dfs(int root, vector< vector<int> >& adj, vector<int>& color){
    color[root] = 1; // visited this node
    for(int j : adj[root]){
        if(color[j] == 0){
            dfs(j, adj, color);
        }
    }
    color[root] = 2; // explored the entire connected component of root
}

/*
    DFS Tree Building
    -> using recursive dfs and the parent array
    -> different tree is obtained when dfs is started from different nodes in the graph
*/
void dfsTree(int root, vector< vector<int> >& adj, vector<int>& color, vector<int>& parent){
    color[root] = 1; // visited this node
    for(int j : adj[root]){
        if(color[j] == 0){
            parent[j] = root;
            dfsTree(j, adj, color, parent);
        }
    }
    color[root] = 2; // explored the entire connected component of root
}

int main(){




    return 0;
}