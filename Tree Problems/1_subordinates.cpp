#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

// recursive dfs which also finds the number of nodes in every subtree (not counting the root itself)
int dfs(vector< vector<int> >& adj, int root, vector<int>& sub_count, vector<bool>& visited){
    visited[root] = true;

    for(int j : adj[root]){
        if(!visited[j]){
            sub_count[root] += 1 + dfs(adj, j, sub_count, visited);
        }
    }

    return sub_count[root];
}

int main(){
    int n;
    cin >> n;

    int parent;

    vector< vector<int> > adj(n+1, vector<int>(0));

    for(int i=2 ; i<=n ; i++){
        cin >> parent;
        adj[parent].push_back(i);
        adj[i].push_back(parent);
    }

    vector<bool> visited(n+1, false);

    // now perform recursive DFS on this adjacency list
    vector<int> sub_count(n+1, 0);    

    dfs(adj, 1, sub_count, visited);

    for(int i=1 ; i<=n ; i++){
        cout << sub_count[i] << " ";
    }    
    cout << endl;

    return 0;
}