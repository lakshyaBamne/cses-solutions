#include<iostream>
#include<vector>
#include<map>

using namespace std;

using ll = long long;

int main(){
    ll n, x;
    cin >> n >> x;

    map<ll,ll> mp;
    for(ll i=0 ; i<n ; i++){
        ll num;
        cin >> num;

        if(mp.find(num) != mp.end()){
            int first = mp[num]+1;
            int second = i+1;

            cout << first << " " << second << endl;
            return 0;
        }
        else{
            mp.insert({x-num, i});
        }
    }   

    cout << "IMPOSSIBLE" << endl;

    return 0;
}