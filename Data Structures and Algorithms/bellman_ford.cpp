/*
    Single source shortest path (with negative weight cycle) - Bellman Ford Algorithm
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

using ll = long long;

struct Edge{
    ll u, v, w;
};


int main(){
    ll INF = 1e18;

    ll n, m;
    cin >> n >> m;

    vector<Edge> edges;
    for(int i=0 ; i<m ; i++){
        Edge e;
        cin >> e.u >> e.v >> e.w;

        edges.push_back(e);
    }

    vector<ll> dist(n+1, -INF);
    vector<ll> parents(n+1, -1);
    
    // we want to find the shortest distance from source to destination
    // detect is there is a positive weight cycle on this specific path or not
    ll source = 1;
    ll dest = n;

    dist[source] = 0;

    ll phases = 0;

    while(phases<n){
        bool no_updates = true;

        for(Edge e : edges){
            if(e.u==dest){
                // once we reach the destination we do not go further from it
                continue;
            }

            if(dist[e.u] > -INF){
                // we can use the edge to optimize the answer for e.v
                if(dist[e.v] < dist[e.u]+e.w){
                    no_updates = false;
                    parents[e.v] = e.u;

                    dist[e.v] = dist[e.u] + e.w;
                }
            }
        }

        // early break condition if no changes occur after a phase of relaxation
        if(no_updates){
            break;
        }

        phases++; // completed a phase of relaxation
    }

    vector<ll> path;
    for(ll curr=dest ; curr!=-1 ; curr=parents[curr]){
        path.push_back(curr);
    }
    reverse(path.begin(), path.end());

    return 0;
}