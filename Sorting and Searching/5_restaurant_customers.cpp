#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n, a, b;
    cin >> n;

    vector< vector<int> > ivls;
    for(int i=0 ; i<n ; i++){
        cin >> a >> b;
        ivls.push_back({a,b});
    }

    sort(ivls.begin(), ivls.end());

    int max_count = 1;
    int count = 1;

    vector<int> last_interval = ivls[0];
    for(int i=1 ; i<n ; i++){

        if(ivls[i][0]>=last_interval[0] && ivls[i][0]<=last_interval[1]){
            // intersection
            count++;
            last_interval = {max(last_interval[0],ivls[i][0]),min(last_interval[1],ivls[i][1])};
        }
        else{
            max_count = max(max_count, count);
            count = 1;
            last_interval = ivls[i];
        }
    }

    max_count = max(max_count, count);

    cout << max_count << endl;

    return 0;
}