#include<iostream>
#include<vector>

using namespace std;

int main(){
    int N, X;
    cin >> N >> X;

    vector<int> coins(N);
    for(int i=0 ; i<N ; i++){
        cin >> coins[i];
    }

    // bottom up DP approach works in O(N*X) time using O(X) space
    // -> think in terms of making an amount i using just one more coin added
    // to a previously made amount smaller than i (0, 1, 2, ... , i) 
    // using all the given coins    
    vector<int> dp(X+1, X+1);

    dp[0] = 0;
    for(int i=1 ; i<=X ; i++){
        for(int j=0 ; j<N ; j++){
            if(i - coins[j] >= 0){
                // the min number of coins required to make an amount=i
                // updated if we only use one more coin to make i from a previously made amount (using the provided coins)
                dp[i] = min(dp[i], 1+dp[i-coins[j]]);
            }
        }
    }

    if(dp[X] != X+1){
        cout << dp[X] << endl;
    }
    else{
        cout << -1 << endl;
    }

    return 0;

}