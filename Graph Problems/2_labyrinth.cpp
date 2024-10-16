/*
    Concept -> since we are dealing with unweighted graph in this problem
    BFS would always give the correct solution (i.e.) shortest path to destination
*/
#include<iostream>
#include<vector>
#include<utility>
#include<climits>
#include<string>
#include<queue>
#include<algorithm>

using namespace std;

string reconstructPath(vector< vector<int> >& parent, pair<int,int>& start, pair<int,int>& end){
    string path = "";
    pair<int,int> curr = end;
    while(curr != start){
        if(parent[curr.first][curr.second] == 1){
            path += "U";
            curr.first++;
        }
        else if(parent[curr.first][curr.second] == 2){
            path += "R";
            curr.second--;
        }
        else if(parent[curr.first][curr.second] == 3){
            path += "D";
            curr.first--;
        }
        else if(parent[curr.first][curr.second] == 4){
            path += "L";
            curr.second++;
        }
    }

    reverse(path.begin(), path.end());

    return path;
}

/*
    Since we need the shortest path, we should use BFS here
    In unweighted graphs, BFS is guaranteed to return the shortest path

    -> BFS cannot be done recursively in graphs and needs to be done iteratively using queue
*/
void bfs(pair<int,int>& root, vector< vector<int> >& grid, vector< vector<int> >& parent){
    int n = grid.size();
    int m = grid[0].size();

    queue< pair<int,int> > processing;
    processing.push(root);

    while(!processing.empty()){
        pair<int,int> top = processing.front();
        processing.pop();

        grid[top.first][top.second] = 2; // explored this node

        int r1, r2;

        // up
        r1 = top.first-1;
        r2 = top.second;
        if(r1 >= 0){
            if(grid[r1][r2] == 11){
                // found solution
                parent[r1][r2] = 1;
                break;
            }
            else if(grid[r1][r2]==0){
                parent[r1][r2] = 1;
                grid[r1][r2] = 1; // added to queue
                processing.push({r1,r2});
            }
        }

        // right
        r1 = top.first;
        r2 = top.second+1;
        if(r2 < m){
            if(grid[r1][r2] == 11){
                // found solution
                parent[r1][r2] = 2;
                break;
            }
            else if(grid[r1][r2]==0){
                parent[r1][r2] = 2;
                grid[r1][r2] = 1; // added to queue
                processing.push({r1,r2});
            }
        }

        // down
        r1 = top.first+1;
        r2 = top.second;
        if(r1 < n){
            if(grid[r1][r2] == 11){
                // found solution
                parent[r1][r2] = 3;
                break;
            }
            else if(grid[r1][r2]==0){
                parent[r1][r2] = 3;
                grid[r1][r2] = 1; // added to queue
                processing.push({r1,r2});
            }
        }

        // left
        r1 = top.first;
        r2 = top.second-1;
        if(r2 >= 0){
            if(grid[r1][r2] == 11){
                // found solution
                parent[r1][r2] = 4;
                break;
            }
            else if(grid[r1][r2]==0){
                parent[r1][r2] = 4;
                grid[r1][r2] = 1; // added to queue
                processing.push({r1,r2});
            }
        }

    }
}

int main(){
    int n, m;
    cin >> n >> m;

    pair<int,int> start, end;

    vector< vector<int> > grid(n, vector<int>(m, 0));
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            char val;
            cin >> val;

            if(val == 'A'){
                grid[i][j] = 10; // starting point

                start = {i,j};
            }
            else if(val == 'B'){
                grid[i][j] = 11; // ending point

                end = {i,j};
            }
            else if(val == '#'){
                grid[i][j] = 3; // wall
            }
        }
    }

    // parent vector for reconstructing the path from destination to source
    vector< vector<int> > parent(n, vector<int>(m, 0));

    // start bfs from the root
    bfs(start, grid, parent);

    if(parent[end.first][end.second] == 0){
        cout << "NO" << endl;
    }
    else{
        // reconstruct path
        cout << "YES" << endl;
        
        string path = reconstructPath(parent, start, end);
        cout << path.size() << endl;
        cout << path << endl;

    }

    return 0;
}

