#include<iostream>
#include<vector>
#include<climits>

using namespace std;

// just returns the digits in the reverse order because the order matters less
vector<int> getDigits(int n){
    vector<int> digits;
    while(n != 0){
        digits.push_back(n%10);
        n /= 10;
    }

    return digits;
}

int main(){
    int n;
    cin >> n;

    vector<int> dp(n+1, 1);
    dp[0] = 0; // base case
    int min_val;

    for(int i=10 ; i<=n ; i++){
        // first find the digits in the current i
        vector<int> digits = getDigits(i);
        
        min_val = INT_MAX;
        for(auto d : digits){
            if(d != 0){
                min_val = min(min_val, dp[i-d]);
            }
        }

        dp[i] = 1 + min_val;

    }

    cout << dp[n] << endl;

    return 0;
}