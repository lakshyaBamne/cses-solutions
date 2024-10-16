/*
    Topics: Recursive dfs on graph, counting connected components
*/

#include<iostream>
#include<vector>

using namespace std;

void dfs(int root, vector< vector<int> >& adj, vector<int>& colors){
    colors[root] = 1; // visited

    for(int j : adj[root]){
        if(colors[j] == 0){
            dfs(j, adj, colors);
        }
    }

    colors[root] = 2; // entire connected component explored
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
 
    vector<int> colors(n+1, 0);
    vector<int> cities;

    int connected_components = 0;
    for(int i=1 ; i<=n ; i++){
        if(colors[i] == 0){
            // new component found
            connected_components++;
            cities.push_back(i);

            dfs(i, adj, colors);
        }
    }

    cout << connected_components - 1 << endl;
    for(int i=0 ; i<cities.size()-1 ; i++){
        cout << cities[i] << " " << cities[i+1] << endl;
    }

    return 0;
}