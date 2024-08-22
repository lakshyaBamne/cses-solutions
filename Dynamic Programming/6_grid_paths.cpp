#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    int m = 1E9 + 7;

    vector< vector<int> > grid(n, vector<int>(n));
    string grid_row;

    for(int i=0 ; i<n ; i++){
        cin >> grid_row;

        for(int j=0 ; j<n ; j++){
            grid[i][j] = grid_row[j]=='*' ? -1 : 0;
        }
    }

    vector< vector<int> > dp(n, vector<int>(n));

    // base cases
    dp[0][0] = grid[0][0]==-1 ? 0 : 1;    
    for(int i=1 ; i<n ; i++){
        // 1st row
        if(dp[0][i-1]==0 || grid[0][i]==-1){
            dp[0][i] = 0;
        }
        else{
            dp[0][i] = 1;
        }

        // 1st column
        if(dp[i-1][0]==0 || grid[i][0]==-1){
            dp[i][0] = 0;
        }
        else{
            dp[i][0] = 1;
        }
    }

    for(int i=1 ; i<n ; i++){
        for(int j=1 ; j<n ; j++){
            if(grid[i][j] == -1){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = (dp[i-1][j]+dp[i][j-1])%m;
            }
        }
    }

    cout << dp[n-1][n-1] << endl;
    return 0;

}
