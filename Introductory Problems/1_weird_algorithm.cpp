/*
    Main concepts to think about while coding the problem
    -> avoiding integer overflow (even from small initial input)
*/

#include<iostream>

using namespace std;

#define ull unsigned long long int

int main(){
    ull n;
    cin >> n;

    while(n != 1){
        cout << n << " ";

        // using the ternary operator for smaller code
        n = n%2==0 ? n/2 : 3*n+1;
    }

    cout << 1 << endl;

    return 0;
}