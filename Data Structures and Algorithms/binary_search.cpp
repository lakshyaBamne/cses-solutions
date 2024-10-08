#include<iostream>
#include<vector>

using namespace std;

/*
    Function which performs the following two functions
    -> if an element exists in sorted array A, it returns it's leftmost occurance
    -> if it does not exist in the array A, it returns it's insert position in the array;
*/
int binarySearch(vector<int>& A, int key){
    int n = A.size();

    if(key < A[0]){
        return -1; // smaller than all elements in the array
    }
    else if(key > A[n-1]){
        return n-1; // should be inserted after index n-1
    }

    int l = 0;
    int r = n-1;
    int m;

    while(l <= r){
        m = l + (int)((r-l)/2);

        if(A[m] == key){
            if(m-1 >= 0){
                if(A[m-1] != key){
                    return m;
                }
                else{
                    r = m-1;
                }
            }
            else{
                return m;
            }
        }
        else if(A[m] < key){
            l = m+1;
        }
        else if(A[m] > key){
            r = m-1;
        }
    }

    return m-1;
}

int findOccurances(vector<int>& A, int key){
    int pos = binarySearch(A, key);
    int posnext = binarySearch(A, key+1);

    if(pos == -1){
        return 0;
    }

    if(A[pos] == key){
        if(A[posnext] == key+1){
            return posnext-pos;
        }
        else{
            return posnext-pos+1;
        }
    }
    else{
        return 0;
    }
}