#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, q;
    cin >> n >> q;

    vector<int> prefix_xor;
    prefix_xor.push_back(0);
    for(int i=1 ; i<=n ; i++){
        int num;
        cin >> num;
        
        prefix_xor.push_back(prefix_xor[i-1]^num);
    }

    for(int i=0 ; i<q ; i++){
        int a, b;
        cin >> a >> b;  

        // NOTE : XOR is it's own inverse operation
        int query_ans = prefix_xor[b]^prefix_xor[a-1];
        cout << query_ans << endl;
    }


    return 0;
}