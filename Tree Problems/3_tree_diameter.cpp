#include<iostream>
#include<vector>

using namespace std;

vector<int> dfs(vector< vector<int> >& adj, int root, vector<bool>& visited){
    visited[root] = true;

    if(adj[root].size() == 0){
        return {0, root};
    }
    else{
        int max_depth = 0;
        int max_depth_node = root;

        for(int j : adj[root]){
            if(!visited[j]){
                vector<int> depth = dfs(adj, j, visited);

                if(1+depth[0]>max_depth){
                    max_depth = 1+depth[0];
                    max_depth_node = depth[1];
                }
            }
        }

        return {max_depth, max_depth_node};
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

    vector<int> max_depth_from_root = dfs(adj, 1, visited);

    visited = vector<bool>(n+1, false);

    vector<int> max_depth_from_a = dfs(adj, max_depth_from_root[1], visited);

    cout << max_depth_from_a[0] << endl;

    return 0;
}