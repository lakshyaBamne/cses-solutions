#include<iostream>
#include<vector>

using namespace std;

using ll = long long;

int main(){
    ll n, q;
    cin >> n >> q;

    vector<ll> nums(n+1, 0);
    for(ll i=1 ; i<=n ; i++){
        cin >> nums[i];
    }

    vector<ll> prefix_sum(n+1, 0);
    for(ll i=1 ; i<=n ; i++){
        prefix_sum[i] = prefix_sum[i-1] + nums[i];
    }

    ll l, r;
    for(ll i=0 ; i<q ; i++){
        cin >> l >> r;

        cout << prefix_sum[r] - prefix_sum[l-1] << endl;
    }

    return 0;
}