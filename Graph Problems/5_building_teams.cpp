/*
    Graph Bipartition Problem
    -> given a graph check if it is bipartitie
    -> if yes give a valid bipartition
*/
#include<iostream>
#include<vector>

using namespace std;

void dfs(int root, vector< vector<int> >& adj, vector<int>& color, bool& partition_possible){
    if(partition_possible){
        for(int i : adj[root]){
            if(color[i] == 0){
                color[i] = color[root]==1 ? 2 : 1;
                dfs(i, adj, color, partition_possible);
            }
            else if(color[i] == color[root]){
                partition_possible = false;
                break;
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    vector< vector<int> > adj(n+1, vector<int>(0));
    for(int i=0 ; i<m ; i++){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> color(n+1, 0);

    // start from any arbitrary root node to start the dfs
    bool partition_possible = true;

    for(int i=1 ; i<=n ; i++){
        if(color[i] == 0){
            // new connected component
            color[i] = 1;
            dfs(i, adj, color, partition_possible);
        }
    }

    if(partition_possible){
        for(int i=1 ; i<=n ; i++){
            cout << color[i] << " ";
        }
        cout << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}


