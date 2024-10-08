#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main(){
    int n, m, num;
    cin >> n >> m;

    multiset<int> tkts;
    for(int i=0 ; i<n ; i++){
        cin >> num;
        tkts.insert(num);
    }

    for(int i=0 ; i<m ; i++){
        cin >> num;

        auto it = tkts.upper_bound(num); // find the first element strictly greater than num

        if(it == tkts.begin()){
            // customer cannot afford any ticket
            cout << -1 << endl;
        }
        else{
            it--;
            cout << *it << endl;
            tkts.erase(it);
        }
    }


    return 0;
}