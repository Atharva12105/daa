#include<iostream>
using namespace std;

int fibRecursive(int n){
    if(n<=1) return n;

    return fibRecursive(n-1)+fibRecursive(n-2);
}

int fibNonRecursive(int n){
    if(n<=1) return n;
    int a=0,b=1,c;

    for(int i=2;i<=n;i++){
        c=a+b;
        a=b;
        b=c;
    }
    return b;
}

int main() {
    int n;

    cout << "Enter the number of terms: ";
    cin >> n;

    cout << "\nFibonacci Series (Non-Recursive): ";
    for (int i = 0; i < n; i++)
        cout << fibNonRecursive(i) << " ";

    cout << "\nFibonacci Series (Recursive): ";
    for (int i = 0; i < n; i++)
        cout << fibRecursive(i) << " ";

    return 0;
}