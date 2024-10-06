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

// DFS to find the distance of each node from the given root node
void getDistances(vector< vector<int> >& adj, int root, vector<int>& dist, int curr_dist, vector<bool>& visited){
    visited[root] = true;

    for(int j : adj[root]){
        if(!visited[j]){
            dist[j] = curr_dist+1;
            getDistances(adj, j, dist, curr_dist+1, visited);
        }
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
    visited = vector<bool>(n+1, false);

    int node_a = max_depth_from_root[1];
    int node_b = max_depth_from_a[1];
    
    // any node in the tree has maximum distance from either node a or node b
    vector<int> dist_a(n+1, 0);
    vector<int> dist_b(n+1, 0);
    
    getDistances(adj, node_a, dist_a, 0, visited);
    visited = vector<bool>(n+1, false);
    getDistances(adj, node_b, dist_b, 0, visited);

    for(int i=1 ; i<=n ; i++){
        cout << max(dist_a[i], dist_b[i]) << " ";
    }
    cout << endl;

    return 0;
}