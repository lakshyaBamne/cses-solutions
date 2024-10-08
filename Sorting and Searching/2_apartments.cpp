#include<iostream>
#include<queue>
#include<utility>

using namespace std;

using ll = long long;

int main(){
    int n, m, k;
    cin >> n >> m >> k;

    int count = 0;
    ll num;

    priority_queue< pair<ll,ll> , vector< pair<ll,ll> > , greater< pair<ll,ll> > > a;
    priority_queue< ll, vector<ll> , greater<ll> > b;

    for(int i=0 ; i<n ; i++){
        cin >> num;
        a.push({num-k,num+k});
    }

    for(int i=0 ; i<m ; i++){
        cin >> num;
        b.push(num);
    }

    while(a.size()>0 && b.size()>0){
        pair<ll,ll> atop = a.top();
        ll btop = b.top();

        if(btop>=atop.first && btop<=atop.second){
            count++;
            a.pop();
            b.pop();
        }
        else if(btop<atop.first){
            b.pop();
        }
        else if(btop>atop.second){
            a.pop();
        }
    }

    cout << count << endl;

    return 0;
}