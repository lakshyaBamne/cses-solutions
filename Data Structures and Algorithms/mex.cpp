/*
    Code to find the Prefix MEX of an array in O(N) time and O(N) space
    problem link -> https://atcoder.jp/contests/hhkb2020/tasks/hhkb2020_c
*/
#include<iostream>
#include<vector>

using namespace std;

vector<int> getMex(const vector<int>& A){
    int n = A.size();

    // MEX of an array of size K cannot exceed K
    vector<bool> track_mex(n+1, false);
    vector<int> prefix_mex;

    int mex = 0;

    for(int i=0 ; i<n ; i++){
        if(A[i]>=0 && A[i]<=n){
            track_mex[A[i]] = true;
        }

        // this loop can overall only have n iterations independent of the outer loop
        while(track_mex[mex]){
            mex++;
        }

        prefix_mex.push_back(mex);
    }

    return prefix_mex;
}

int main(){
    int n;
    cin >> n;

    vector<int> A(n);
    for(int i=0 ; i<n ; i++){
        cin >> A[i];
    }

    vector<int> prefix_mex = getMex(A);

    for(auto i : prefix_mex){
        cout << i << endl;
    }


    return 0;
}

