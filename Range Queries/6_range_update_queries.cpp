#include<iostream>
#include<vector>

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
        
            t[ti] = t[ti*2+1] + t[ti*2+2];
        }
    }

    ll update(ll k, ll num, ll ti, ll tl, ll tr){
        if(tl == tr){
            return t[ti] = t[ti] + num;
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

    ll query(ll l, ll r, ll ti, ll tl, ll tr){
        if(l==tl && r==tr){
            return t[ti];
        }
        else{
            ll tm = tl + (ll)((tr-tl)/2);

            if(r <= tm){
                return query(l, r, ti*2+1, tl, tm);
            }
            else if(l >= tm+1){
                return query(l, r, ti*2+2, tm+1, tr);
            }
            else{
                return query(l, tm, ti*2+1, tl, tm) + query(tm+1, r, ti*2+2, tm+1, tr);
            }
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

    // the prefix sum difference array on which segment tree is build
    vector<ll> psum(n+1, 0);
    SegmentTree st(psum);

    for(ll i=0 ; i<q ; i++){
        ll a, b, c, d;
        cin >> a;

        if(a == 1){
            // range update query
            cin >> b >> c >> d;
            b--;
            c--;

            st.update(b, d, 0, 0, n);
            st.update(c+1, -d, 0, 0, n);
        }
        else{
            // point retrieval query
            cin >> b;
            b--;

            cout << nums[b] + st.query(0, b, 0, 0, n) << endl;
        }
    }

    return 0;
}



