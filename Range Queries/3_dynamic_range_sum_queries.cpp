#include<iostream>
#include<vector>
#include<cmath>
#include<climits>

using namespace std;

using ll = long long;

int main(){
    ll n, q;
    cin >> n >> q;

    vector<ll> nums(n);
    for(ll i=0 ; i<n ; i++){
        cin >> nums[i];
    }

    // Preprocessing using square root decomposition
    ll block_size = (ll)ceil(sqrt(n));
    ll num_blocks = (ll)(n/block_size) + 1;

    vector<ll> blocks(num_blocks, 0);

    for(ll i=0 ; i<num_blocks ; i++){
        ll start = i*block_size;
        ll end = min(n-1, start+block_size-1);

        for(ll j=start ; j<=end ; j++){
            blocks[i] += nums[j];
        }
    }

    ll t, l, r;
    for(ll i=0 ; i<q ; i++){
        cin >> t >> l >> r;

        if(t == 1){
            l--;

            nums[l] = r;

            // recompute the block that contains index l
            ll b = (ll)(l/block_size);
            ll bstart = b*block_size;
            ll bend = min(n-1, bstart+block_size-1);

            blocks[b] = 0;
            for(ll j=bstart ; j<=bend ; j++){
                blocks[b] += nums[j];
            }
        }
        else{
            l--;
            r--;

            ll query_ans = 0;

            ll bleft = (ll)(l/block_size);
            ll bright = (ll)(r/block_size);
        
            ll lstart = bleft*block_size;
            ll lend = min(n-1, lstart+block_size-1);

            ll rstart = bright*block_size;
            ll rend = min(n-1, rstart+block_size-1);

            if(bleft == bright){
                for(ll j=l ; j<=r ; j++){
                    query_ans += nums[j];
                }
            }
            else{
                for(ll j=l ; j<=lend ; j++){
                    query_ans += nums[j];
                }

                for(ll j=rstart ; j<=r ; j++){
                    query_ans += nums[j];
                }

                for(ll j=bleft+1 ; j<bright ; j++){
                    query_ans += blocks[j];
                }
            }

            cout << query_ans << endl;
        }
    }

    return 0;
}