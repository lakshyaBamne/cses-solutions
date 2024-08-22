/*
    The basic version of this problem is the step climbing problem in leetcode
    where we can only jump 1 or 2 steps, this problem just includes 6 steps

    and has a big input size so overflow needs to be considered
    -> how to deal with positive overflow as well as negative overflow is important
*/
#include<iostream>
#include<vector>
 
using namespace std;
 
#define ull unsigned long long int
 
int main(){
    ull m = 1E9 + 7;
    // int m = 1E9 + 7;
 
    // input
    int n;
    cin >> n;
 
    vector<ull> k = {1, 2, 4, 8, 16, 32, 63};
    ull last_sum = 63;
 
    if(n <= 7){
        cout << k[n-1] << endl;
        return 0;
    }
 
    int step = 8;
 
    while(step <= n){
        // recalculate the new value with the last 6 sums
        last_sum -= k[0];
        last_sum = (last_sum+m)%m; // since this subtraction can lead to negative number we should bring it up again

        last_sum = (last_sum + k[6])%m;
 
        for(int i=1 ; i<7 ; i++){
            k[i-1] = k[i];
        }
 
        k[6] = last_sum;
 
        step++;
    }

    cout << k[6]%m << endl;

    return 0;
}