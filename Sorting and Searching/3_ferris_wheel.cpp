#include<iostream>
#include<map>
#include<queue>

using namespace std;

int main(){
    int n, x, num;
    cin >> n >> x;

    int count = 0;

    priority_queue<int> pq;
    priority_queue<int> wts;

    for(int i=0 ; i<n ; i++){
        cin >> num;
        wts.push(num);
    }

    while(wts.size() > 0){
        int wt = wts.top();
        wts.pop();

        if(pq.size() > 0){
            int max_space = pq.top();
            
            if(wt <= max_space){
                pq.pop();
            }
            else{
                count++;
                pq.push(x-wt);
            }
        }
        else{
            count++;
            pq.push(x-wt);
        }
    }

    cout << count << endl;

    return 0;
}