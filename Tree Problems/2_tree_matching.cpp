#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int dfs(vector< vector<int> >& adj, int root, unordered_set<int>& added, int& num_edges, vector<bool>& visited){
    visited[root] = true;

    if(adj[root].size()==0){
        if(!visited[root]){
            visited[root] = true;
        }

        return 1;
    }
    else{
        vector<int> status;
        for(int j : adj[root]){
            if(!visited[j]){
                status.push_back(dfs(adj, j, added, num_edges, visited));
            }
        }

        for(int k=0 ; k<status.size() ; k++){
            if(status[k]==1){
                added.insert(adj[root][k]);
                added.insert(root);

                num_edges++;

                return 0;
            }
        }

        return 1;
    }
}

int main(){
    int n;
    cin >> n;

    vector< vector<int> > adj(n+1, vector<int>(0));
    for(int i=0 ; i<n-1 ; i++){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visited(n+1, false);

    unordered_set<int> added;
    int num_edges = 0;
    dfs(adj, 1, added, num_edges, visited);

    cout << num_edges << endl;

    return 0;
}