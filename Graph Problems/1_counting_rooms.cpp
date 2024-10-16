/*
    Concept -> count the number of connected components

    Time: O(n+m) as all the empty cells are visited at most once
    Space: O(n+m) for recursion
*/

#include<iostream>
#include<vector>
#include<utility>

using namespace std;

/*
    Recursive dfs on a rectangular grid where cells can be walls or paths
*/
void dfs(pair<int,int> root, vector< vector<int> >& grid){
    // grid dimensions
    int n = grid.size();
    int m = grid[0].size();

    grid[root.first][root.second] = 1; // visited this node

    int r1, r2;
    
    // up
    r1 = root.first-1;
    r2 = root.second;

    if(r1 >= 0){
        if(grid[r1][r2] == 0){
            dfs({r1,r2}, grid);
        }
    }

    // right
    r1 = root.first;
    r2 = root.second+1;

    if(r2 < m){
        if(grid[r1][r2] == 0){
            dfs({r1,r2}, grid);
        }
    }

    // down
    r1 = root.first+1;
    r2 = root.second;

    if(r1 < n){
        if(grid[r1][r2] == 0){
            dfs({r1,r2}, grid);
        }
    }

    // left
    r1 = root.first;
    r2 = root.second-1;

    if(r2 >= 0){
        if(grid[r1][r2] == 0){
            dfs({r1,r2}, grid);
        }
    }


    grid[root.first][root.second] = 2; // connected component has been visited
}

int main(){
    int n, m;
    cin >> n >> m;
    char layout;

    vector< vector<int> > grid(n, vector<int>(m, 0));
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cin >> layout;

            if(layout == '#'){
                grid[i][j] = 3; // wall
            }
        }
    }

    int count_rooms = 0;

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(grid[i][j]==0){
                count_rooms++;
                dfs({i,j}, grid);
            }
        }
    }

    cout << count_rooms << endl;

    return 0;
}