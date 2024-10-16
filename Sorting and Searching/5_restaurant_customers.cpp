#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>

using namespace std;

int main(){
    int n, a, b;
    cin >> n;

    priority_queue< vector<int> , vector< vector<int> > , greater< vector<int> > > pq; // min heap
    for(int i=0 ; i<n ; i++){
        cin >> a >> b;

        pq.push({a, 0});
        pq.push({b, 1});
    }

    int max_count = INT_MIN;
    int count = 0;

    // event based algorithm which works in O(n)
    while(!pq.empty()){
        vector<int> top = pq.top();
        pq.pop();

        if(top[1] == 0){
            count++;

            max_count = max(max_count, count);
        }
        else{
            count--;
        }
    }

    cout << max_count << endl;

    return 0;
}