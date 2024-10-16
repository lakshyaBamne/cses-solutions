#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

void bfs(int root, vector< vector<int> >& adj, vector<int>& color, vector<int>& parent){
    queue<int> processing;
    processing.push(root);
    color[root] = 1; // in queue

    while(!processing.empty()){
        int top = processing.front();
        processing.pop();

        color[top] = 2; // visited

        for(int j : adj[top]){
            if(color[j] == 11){
                // found solution
                parent[j] = top;
                
                // clear the queue and break from the loop to stop the bfs search
                processing = queue<int>();
                break;
            }
            else if(color[j] == 0){
                color[j] = 1; // in queue
                parent[j] = top;
                processing.push(j);
            }
        }
    }

}

vector<int> reconstructPath(vector<int>& parent, int start, int end){
    vector<int> path_nodes;
    
    int curr = end;
    while(curr != start){
        path_nodes.push_back(curr);
        curr = parent[curr];
    }
    path_nodes.push_back(start);

    reverse(path_nodes.begin(), path_nodes.end());

    return path_nodes;
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
    color[1] = 10; // start
    color[n] = 11; // end

    vector<int> parent(n+1, -1);

    // run bfs
    bfs(1, adj, color, parent);

    if(parent[n] == -1){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        vector<int> path_nodes = reconstructPath(parent, 1, n);
        cout << path_nodes.size() << endl;
        for(auto i : path_nodes){
            cout << i << " ";
        }
        cout << endl;
    }


    return 0;
}