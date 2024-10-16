#include<iostream>
#include<vector>
#include<cmath>
#include<climits>

using namespace std;

using ll = long long;

class SegmentTree{
public:
    ll n;
    vector<ll> t;

    SegmentTree(vector<ll>& nums){
        n = nums.size();
        t.resize(4*n);

        build_segment_tree(nums, 0, 0, n-1);
    }

    void build_segment_tree(vector<ll>& nums, ll ti, ll tl, ll tr){
        if(tl == tr){
            t[ti] = nums[tl];
        }
        else{
            ll tm = tl + (ll)((tr-tl)/2);

            build_segment_tree(nums, ti*2+1, tl, tm);
            build_segment_tree(nums, ti*2+2, tm+1, tr);
        
            t[ti] = t[ti*2+1]+t[ti*2+2];
        }
    }

    // range queries
    ll query(ll l, ll r, ll ti, ll tl, ll tr){
        if(l==tl && r==tr){
            return t[ti];
        }
        else{
            ll tm = tl + (ll)((tr-tl)/2);

            if(r <= tm){
                // entire query lies on the left subproblem
                return query(l, r, ti*2+1, tl, tm);
            }
            else if(l >= tm+1){
                // entire query lies on the right subproblem
                return query(l, r, ti*2+2, tm+1, tr);
            }
            else{
                // divide query into two subproblems and answer each 
                return query(l, tm, ti*2+1, tl, tm) + query(tm+1, r, ti*2+2, tm+1, tr);
            }
        }
    }

    // point update query
    ll update(ll k, ll num, ll ti, ll tl, ll tr){
        if(tl == tr){
            return t[ti] = num;
        }
        else{
            ll tm = tl + (ll)((tr-tl)/2);

            if(k <= tm){
                t[ti] = t[ti*2+2] + update(k, num, ti*2+1, tl, tm);
            }
            else{
                t[ti] = t[ti*2+1] + update(k, num, ti*2+2, tm+1, tr);
            }

            return t[ti];
        }
    }

};

int main(){
    ll n, q;
    cin >> n >> q;

    vector<ll> nums(n);
    for(ll i=0 ; i<n ; i++){
        cin >> nums[i];
    }

    SegmentTree st(nums);

    for(ll i=0 ; i<q ; i++){
        ll a, b, c;
        cin >> a >> b >> c;

        if(a == 1){
            // point update query
            st.update(b-1, c, 0, 0, n-1);
        }
        else{
            // range query
            cout << st.query(b-1, c-1, 0, 0, n-1) << endl;
        }
    }

    return 0;
}
