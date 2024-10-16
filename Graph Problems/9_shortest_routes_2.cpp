/*
    All source shortest path - Floyd warshall algorithm
    NOTE -> the graph should not contain any negative weight cycle to get correct result

    Time: O(n^3)
    Space: O(n^2)

    -> Can also be used to detect a negative weight cycle in the graph
*/
#include<iostream>
#include<vector>
#include<utility>

using namespace std;

using ll = long long;

/*
    Floyd warshall using adjacency list assuming there is maximum 1 edge between any two nodes
*/
vector< vector<ll> > floydWarshall(vector< vector< pair<ll,ll> > >& adj){
    int n = adj.size()-1;
    
    vector< vector<ll> > dp(n+1, vector<ll>(n+1, 1e18));

    // initialize
    for(int i=1 ; i<=n ; i++){
        // distance of the node from itself - used in negative cycle detection
        dp[i][i] = 0;

        // adjacent nodes
        for(pair<ll,ll> node : adj[i]){
            dp[i][node.first] = node.second;
        }
    }

    // dp table calculation
    for(int k=1 ; k<=n ; k++){
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=n ; j++){
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
            }
        }
    }

    return dp;
}

/*
    Floyd warshall using adjacency matrix
*/
vector< vector<ll> > floydWarshall(vector< vector<ll> >& mat){
    int n = mat.size()-1;
    
    vector< vector<ll> > dp(n+1, vector<ll>(n+1, 1e18));

    // initialize
    for(int i=1 ; i<=n ; i++){
        // distance of the node from itself - used in negative cycle detection
        dp[i][i] = 0;

        // adjacent nodes
        for(int j=i+1 ; j<=n ; j++){
            dp[i][j] = mat[i][j];
            dp[j][i] = mat[j][i];
        }
    }

    // dp table calculation
    for(int k=1 ; k<=n ; k++){
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=n ; j++){
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
            }
        }
    }

    return dp;
}

int main(){
    ll n, m, q;
    cin >> n >> m >> q;

    vector< vector<ll> > mat(n+1, vector<ll>(n+1, 1e18)); // adjacency matrix
    for(int i=0 ; i<m ; i++){
        ll a, b, c;
        cin >> a >> b >> c;

        // if there are multiple edges between two nodes, consider the one with the minimum weight
        mat[a][b] = min(mat[a][b], c);
        mat[b][a] = min(mat[b][a], c);
    } 

    // vector< vector<ll> > dp = floydWarshall(adj);
    vector< vector<ll> > dp = floydWarshall(mat);

    for(int i=0 ; i<q ; i++){
        int a, b;
        cin >> a >> b;

        if(dp[a][b] >= 1e18){
            cout << "-1" << endl;
        }
        else{
            cout << dp[a][b] << endl;
        }
    }

}

