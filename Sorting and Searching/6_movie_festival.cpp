/*
    The classic interval scheduling problem where each interval represents a task
    and every task has the same reward.

    A greedy approach for always taking the task whose 
    1) deadline is earliest
    2) start time is latest

    out of the remaining choices is the optimal in this case

    Reasoning -> Taking (say) the task with earliest deadline leaves us with more time to select 
    a larger number of jobs that come after the selected job
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector< vector<int> > t;
    for(int i=0 ; i<n ; i++){
        int a, b;
        cin >> a >> b;

        t.push_back({a, b});
    }

    sort(t.begin(), t.end());

    int barrier = t[n-1][0];
    int count = 1;
    
    for(int i=n-2 ; i>=0 ; i--){
        if(t[i][1] <= barrier){
            barrier = t[i][0];
            count++;
        }
    }
    
    cout << count << endl;

    return 0;
}