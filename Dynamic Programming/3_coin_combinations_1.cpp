#include<iostream>
#include<vector>

using namespace std;

int main(){
    int m = 1E9 + 7;

    int N, A;
    cin >> N >> A;

    vector<int> coins(N);
    for(int i=0 ; i<N ; i++){
        cin >> coins[i];
    }

    vector<int> dp(A+1, 1);
    int dpval;

    for(int i=1 ; i<=A ; i++){
        dpval = 0;
        for(int j=0 ; j<N ; j++){
            if(i-coins[j] >= 0){
                dpval = (dpval + dp[i-coins[j]])%m;
            }
        }

        dp[i] = dpval;
    }

    cout << dp[A] << endl;

    return 0;
}