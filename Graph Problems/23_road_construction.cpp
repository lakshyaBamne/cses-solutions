/*
    Road construction
    -> Initially all the cities are in different sets
    -> as we add roads, the component sizes increase (only when union is done)
    -> after each iteration we want to keep track of the size of each component (and return the maximum)
    -> number of components
*/
#include<iostream>
#include<vector>

using namespace std;

int find_set(int u, vector<int>& parents){
    if(u == parents[u]){
        return u;
    }

    // recursive path compression is used
    parents[u] = find_set(parents[u], parents);

    return parents[u];
}

void union_sets(int u, int v, vector<int>& parents, vector<int>& ranks, int& largest_component_size, int& total_components){
    u = find_set(u, parents);
    v = find_set(v, parents);

    if(u != v){
        if(ranks[u] <= ranks[v]){
            parents[u] = v;
            ranks[v] += ranks[u];

            // the newly updated rank could be the largest component size
            largest_component_size = max(largest_component_size, ranks[v]);
        }
        else{
            parents[v] = u;
            ranks[u] += ranks[v];

            // the newly updated rank could be the largest component size
            largest_component_size = max(largest_component_size, ranks[u]);
        }

        // number of components also decreases
        total_components--;
    }
}

int main(){

    int n, m;
    cin >> n >> m;  

    // initialize n sets in the DSU
    vector<int> ranks(n+1, 1);
    vector<int> parents(n+1);
    for(int i=1 ; i<=n ; i++){
        parents[i] = i;
    }

    int total_components = n;
    int largest_component_size = 1;

    vector<int> edge(2);
    vector< vector<int> > output;

    for(int i=0 ; i<m ; i++){
        cin >> edge[0] >> edge[1];

        union_sets(edge[0], edge[1], parents, ranks, largest_component_size, total_components);

        // output
        output.push_back( {total_components,largest_component_size} );
    }

    for(auto i : output){
        cout << i[0] << " " << i[1] << endl;
    }

    return 0;
}

