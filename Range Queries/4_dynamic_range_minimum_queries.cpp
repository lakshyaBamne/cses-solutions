#include<iostream>
#include<vector>
#include<climits>
#include<cmath>

using namespace std;

using ll = long long;

#include<iostream>
#include<vector>
#include<cmath>
#include<map>
#include<climits>

using namespace std;

int INF = 1e9;

class SegementTree{
public:
    int n;
    vector<int> t;

    SegementTree(vector<int>& nums){
        n = nums.size();
        t.resize(4*n, INF);

        build_segment_tree(nums, 0, 0, n-1);
    }

    // recursive function to build the classic segment tree
    void build_segment_tree(vector<int>& nums, int ti, int tl, int tr){
        if(tl == tr){
            t[ti] = nums[tl];
        }
        else{
            int tm = tl + (int)((tr-tl)/2);

            build_segment_tree(nums, ti*2+1, tl, tm);
            build_segment_tree(nums, ti*2+2, tm+1, tr);

            t[ti] = merge(ti*2+1, ti*2+2);
        }
    }

    // we update this merge function to get the segment tree for different problems and types of queries
    int merge(int tleft, int tright){
        return min(t[tleft], t[tright]);
    }

    // range queries
    int query(int l, int r, int ti, int tl, int tr){
        if(l==tl && r==tr){
            return t[ti];
        }
        else{
            int tm = tl + (int)((tr-tl)/2);

            // case-1 : r <= tm (entire query is on the left subproblem)
            if(r <= tm){
                return query(l, r, ti*2+1, tl, tm);
            }

            // case-2 : l >= tm+1 (entire query is on the right subproblem)
            if(l >= tm+1){
                return query(l, r, ti*2+2, tm+1, tr);
            }

            // case-3 : l>=tm && tm<r (query must be divided into two and them merged later)
            return min(query(l, tm, ti*2+1, tl, tm), query(tm+1, r, ti*2+2, tm+1, tr));
        }
    }

    int update(int k, int num, int ti, int tl, int tr){
        if(tl == tr){
            return t[ti] = num;
        }
        else{
            int tm = tl + (int)((tr-tl)/2);

            if(k <= tm){
                // query lies in the left subproblem
                t[ti] = min(t[ti*2+2], update(k, num, ti*2+1, tl, tm));
            }
            else{
                // query lies in the right subproblem
                t[ti] = min(t[ti*2+1], update(k, num, ti*2+2, tm+1, tr));
            }

            return t[ti];
        }
    }
};

int main(){
    int n, q;
    cin >> n >> q;

    vector<int> nums(n);
    for(int i=0 ; i<n ; i++){
        cin >> nums[i];
    }

    SegementTree st(nums);

    for(int i=0 ; i<q ; i++){
        int a, b, c;
        cin >> a >> b >> c;

        if(a == 1){
            // point update queries
            st.update(b-1, c, 0, 0, n-1);
        }
        else{
            // range queries
            cout << st.query(b-1, c-1, 0, 0, n-1) << endl;
        }
    }

    return 0;
}