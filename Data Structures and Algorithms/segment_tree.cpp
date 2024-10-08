#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

class SegmentTree{
public:
    vector<int> t;
    int n;

private:

    // recursive function to build the segment tree according to a given problem
    void buildSegmentTree(vector<int>& A, int root, int tl, int tr){
        if(tl == tr){
            t[root] = A[tl];
        }
        else{
            int tm = tl + (int)((tr-tl)/2);

            buildSegmentTree(A, 2*root+1, tl, tm);
            buildSegmentTree(A, 2*root+2, tm+1, tr);

            t[root] = merge(2*root+1, 2*root+2);
        }
    }

    // modify this merge function to get segment tree for different purposes
    int merge(int left_child, int right_child){
        return t[left_child]+t[right_child];
    }

    // Recursive function to answer queries on the segment tree
    int answerQueries(int root, int tl, int tr, int ql, int qr){
        if(ql==tl && qr==tr){
            return t[root];
        }
        else{
            int tm = tl + (int)((tr-tl)/2);

            if(tm < ql){
                // entire query lies on the right sub tree
                return answerQueries(2*root+2, tm+1, tr, ql, qr);
            }
            else if(tm >= qr){
                // entire query lies on the left sub tree
                return answerQueries(2*root+1, tl, tm, ql, qr);
            }
            else{
                // query must be divided into two
                return answerQueries(2*root+1, tl, tm, ql, tm) + answerQueries(2*root+2, tm+1, tr, tm+1, qr);
            }

        }
    }

    // Recursive function to make updations to the segment tree
    void updateTree(int root, int tl, int tr, int i, int new_val){
        if(tl==tr && tl==i){
            t[root] = new_val;
        }
        else{
            int tm = tl + (int)((tr-tl)/2);

            if(i <= tm){
                updateTree(2*root+1, tl, tm, i, new_val);
            }
            else{
                updateTree(2*root+2, tm+1, tr, i, new_val);
            }

            // merge again
            t[root] = merge(2*root+1, 2*root+2);
        }
    }

public:

    SegmentTree(vector<int>& A){
        n = A.size();
        t.resize(4*n, INT_MIN);

        buildSegmentTree(A, 0, 0, n-1);
    }

    // Function to answer queries on the array in a given range in O(logN)
    int query(int left, int right){
        return answerQueries(0, 0, n-1, left, right);
    }

    // Recursive function to update an element on the underlying query and also update the tree
    void update(int i, int new_val){
        updateTree(0, 0, n-1, i, new_val);
    }

};