/*
    Single source shortest path - Dijkstra's Algorithm
*/
#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<unordered_set>

using namespace std;

using ll = long long;

vector<ll> dijkstra(int source, vector< vector< pair<ll,ll> > >& adj){
    ll n = adj.size()-1;

    vector<ll> color(n+1, 0);
    vector<ll> distance(n+1, 1e18);
    distance[source] = 0;

    priority_queue< pair<ll,ll> , vector< pair<ll,ll> > , greater< pair<ll,ll> > > pq;
    pq.push({distance[source], source});

    while(!pq.empty()){
        pair<ll,ll> top = pq.top();
        pq.pop();

        if(color[top.second] == 0){
            color[top.second] = 1; // shortest distance to this node has been finalized

            for(pair<ll,ll> j : adj[top.second]){
                if(color[j.first] == 0){
                    if(distance[j.first] > top.first + j.second){
                        distance[j.first] = top.first + j.second;
                        pq.push({distance[j.first], j.first});
                    }
                }
            }
        }
    }

    return distance;
}

int main(){
    ll n, m;
    cin >> n >> m;

    vector< vector< pair<ll,ll> > > adj(n+1, vector< pair<ll,ll> >(0));
    for(ll i=0 ; i<m ; i++){
        ll a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({b, c});
    }

    // run the dijkstra algorithm
    vector<ll> distance = dijkstra(1, adj);

    for(int i=1 ; i<=n ; i++){
        cout << distance[i] << " ";
    }
    cout << endl;

    return 0;
}

