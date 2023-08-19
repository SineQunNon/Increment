#include<iostream>
using namespace std;

int factorialRecursive(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorialRecursive(n - 1);
}

int main(){
    int n;
    cin >> n;

    int repeat = factorialRecursive(n) / (factorialRecursive(6) * factorialRecursive(n - 6));
    cout << repeat << endl; ///

    

    return 0;
}