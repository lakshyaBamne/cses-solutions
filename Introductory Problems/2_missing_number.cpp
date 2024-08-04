#include<iostream>

using namespace std;

#define ull unsigned long long int

int main(){
    ull n;
    cin >> n;

    ull total = n*(n+1)/2;
 
    ull sums = 0;
    ull temp;

    while(n > 1){
        cin >> temp;
        sums += temp;

        n--;
    }

    cout << total - sums << endl;

    return 0;
}