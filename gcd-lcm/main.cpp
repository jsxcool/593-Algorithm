#include <iostream>
using namespace std;
//great common divisor: gcd

/* Euclid gcd
 * gcd(a, b) = gcd(b, a mod b)
 * until gcd(a, 0)     gcd = a
 */
int gcd(int a, int b){   // O(log(a+b))
    if(b==0)
        return a;
    else
        return gcd(b, a%b);
}


int gcd_brute(int a, int b){   // O(min(a,b))
    int m = min(a,b);
    for(int i=m; i>1; i--){
        if(a%i==0 && b%i==0)
            return i;
    }
    return 1;
}


//lowest common multiple
int lcm(int a, int b){
    return a*b/gcd(a,b);
}


int main() {
    cout << gcd(312316, 35524) << '\n';
    //cout << lcm(16, 24);
}
