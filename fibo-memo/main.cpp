#include <iostream>
using namespace std;

int fibo(int n){
    static int memo[]={0};
    if(n==1 || n==2)
        return 1;
    if(memo[n] != 0)
        return memo[n];
    return memo[n] = fibo(n-1) + fibo(n-2);
}

int fibo2(int n){
    if(n==1 || n==2)
        return 1;
    return fibo(n-1) + fibo(n-2);
}

int main() {
    cout << fibo2(40);   // 1 1 2 3 5
}