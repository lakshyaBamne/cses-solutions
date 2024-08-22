#include<iostream>
#include<vector>

using namespace std;

int main(){
    int N, A;
    cin >> N >> A;

    int m = 1E9 + 7;

    vector<int> coins(N);
    for(int i=0 ; i<N ; i++){
        cin >> coins[i];
    }

    vector< vector<int> > dp(N, vector<int>(A+1, 0));

    // base cases
    for(int i=0 ; i<N ; i++){
        dp[i][0] = 1;
    }
    for(int j=1 ; j<=A ; j++){
        if(j-coins[N-1] >= 0){
            dp[N-1][j] = dp[N-1][j-coins[N-1]];
        }
    }

    int dpval;

    // calculation of the DP table

    for(int i=N-2 ; i>=0 ; i--){
        for(int j=1 ; j<=A ; j++){
            dpval = dp[i+1][j];
            if(j-coins[i] >= 0){
                dpval = (dpval + dp[i][j-coins[i]])%m;
            }

            dp[i][j] = dpval;
        }
    }

    cout << dp[0][A] << endl;

    return 0;
}