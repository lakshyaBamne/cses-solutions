#include<iostream>
#include<vector>
#include<cmath>
#include<map>
#include<climits>

using namespace std;

class SquareRootDecomposition{
public:
    int n;
    int block_size;
    int num_blocks;

    vector<int> arr;
    vector<int> blocks;

    SquareRootDecomposition(vector<int>& nums){
        n = nums.size();
        block_size = (int)ceil(sqrt(n));
        num_blocks = (int)ceil(n/block_size) + 1;

        arr = nums;

        for(int i=0 ; i<num_blocks ; i++){
            int start = block_size*i;
            int end = min(n-1, start+block_size-1);

            int block_val = INT_MAX;
            for(int j=start ; j<=end ; j++){
                block_val = min(block_val, arr[j]);
            }

            blocks.push_back(block_val);
        }
    }

    int query(int l, int r){
        // first find to which blocks do l and r belong
        int lblock = l/block_size;
        int rblock = r/block_size;

        int query_ans = INT_MAX;

        if(lblock == rblock){
            for(int i=l ; i<=r ; i++){
                query_ans = min(query_ans, arr[i]);
            }
        }
        else{
            int lstart = block_size*lblock;
            int lend = min(n-1, lstart+block_size-1);

            for(int i=l ; i<=lend ; i++){
                query_ans = min(query_ans, arr[i]);
            }

            int rstart = block_size*rblock;
            int rend = min(n-1, rstart+block_size-1);

            for(int i=rstart ; i<=r ; i++){
                query_ans = min(query_ans, arr[i]);
            }

            for(int i=lblock+1 ; i<rblock ; i++){
                query_ans = min(query_ans, blocks[i]);
            }
        }

        return query_ans;
    }

};