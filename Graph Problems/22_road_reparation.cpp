/*
    Road Reparation
    -> Basically find the MST for the given cities and roads
    -> Implement Kruskal's Algorithm using DSU (path compression and union by rank optimizations)
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int find_set(int u, vector<int>& parents){
    if(u == parents[u]){
        return u;
    }

    // recursive path compression is used
    parents[u] = find_set(parents[u], parents);

    return parents[u];
}

void union_sets(int u, int v, vector<int>& parents, vector<int>& ranks){
    // union by rank is used
    // set with smaller rank is merged into the set with greater rank
    if(u != v){
        if(ranks[u] <= ranks[v]){
            ranks[v] += ranks[u];
            parents[u] = v;
        }
        else{
            ranks[u] += ranks[v];
            parents[v] = u;
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    vector< vector<int> > edges(m, vector<int>(3));
    for(int i=0 ; i<m ; i++){
        cin >> edges[i][1] >> edges[i][2] >> edges[i][0];
    }

    // sorting the edges is the bottle neck for this problem - O(ElogE)
    sort(edges.begin(), edges.begin()+m);

    // initialize the different sets
    vector<int> ranks(n+1, 1);
    vector<int> parents(n+1);
    for(int i=1 ; i<=n ; i++){
        parents[i] = i;
    }

    long long int min_cost = 0;
    int edges_added = 0;
    
    for(int i=0 ; i<m && edges_added<n-1 ; i++){
        vector<int> e = edges[i];

        // finding representatives for the sets in which the nodes are present
        int u = find_set(e[1], parents);
        int v = find_set(e[2], parents);
    
        if(u != v){
            // add the edge to the MST
            min_cost += e[0];
            edges_added++;

            union_sets(u, v, parents, ranks);
        }
    }

    if(edges_added != n-1){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        cout << min_cost << endl;
    }

    return 0;
}

