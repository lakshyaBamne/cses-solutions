/*
    Kadane's Algorithm 
    -> To find the maximum sum subarray in O(n) time
*/

#include<iostream>
#include<vector>

using namespace std;

using ll = long long;

ll Kadane(vector<ll>& nums){
    ll max_sum = nums[0];
    ll curr_sum = nums[0];

    for(int i=1 ; i<nums.size() ; i++){
        if(curr_sum + nums[i] >= nums[i]){
            curr_sum += nums[i];
        }
        else{
            curr_sum = nums[i];
        }

        max_sum = max(max_sum, curr_sum);
    }

    return max_sum;
}

int main(){
    int n;
    cin >> n;

    vector<ll> nums(n);
    for(int i=0 ; i<n ; i++){
        cin >> nums[i];
    }

    cout << Kadane(nums) << endl;

    return 0;
}