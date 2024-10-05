#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, x;
    cin >> n >> x;

    vector< vector<int> > books(n, vector<int>(2));
    
    // input
    for(int i=0 ; i<n ; i++){
        cin >> books[i][0];
    }
    for(int i=0 ; i<n ; i++){
        cin >> books[i][1];
    }

    // dp table
    vector< vector<int> > dp(n, vector<int>(x+1, 0));

    // base case -> when we only have the last book to pick
    for(int j=1 ; j<=x ; j++){
        if(j-books[n-1][0] >= 0){
            dp[n-1][j] = books[n-1][1];
        }
    }

    int take, skip; // temporary variables used in dp calculation

    for(int i=n-2 ; i>=0 ; i--){
        for(int j=1 ; j<=x ; j++){
            // taking the book i
            if(j-books[i][0] >= 0){
                take = books[i][1] + dp[i+1][j-books[i][0]];
            }
            else{
                take = 0;
            }

            // skipping the book i
            skip = dp[i+1][j];

            dp[i][j] = max(take, skip);
        }
    }

    cout << dp[0][x] << endl;

    return 0;
}