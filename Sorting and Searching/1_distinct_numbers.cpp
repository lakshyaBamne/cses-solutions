#include<iostream>
#include<map> // using unordered map gives TLE for the last test case

using namespace std;

int main(){
    int n;
    cin >> n;

    int num;

    map<int,int> umap;
    for(int i=0 ; i<n ; i++){
        cin >> num;

        umap[num]++;
    }

    cout << umap.size() << endl;

    return 0;
}