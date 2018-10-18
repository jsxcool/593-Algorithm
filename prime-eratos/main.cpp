#include <iostream>
#include <cmath>
using namespace std;

int countPrime(int64_t n){
    int count = 0;
    bool* isPrime = new bool[n+1];  // 0 -- isPrime[0]

    for(int i=2; i<n+1; i++)  // 0, 1 are not prime, are false
        isPrime[i] = true;

    for(int i=2; i<=n; i++){   // O(n)
        if(isPrime[i]){
            for(int j=2*i; j<=n; j+=i) // O(n)
                isPrime[j] = false;
        }
    }

    for(int i=0; i<=n; i++) {
        //cout << isPrime[i] << ' ';
        if (isPrime[i])
            count++;
    }
    delete [] isPrime;
    return count;
}

int countPrime2(int64_t n){
    int count = 1;
    bool* isPrime = new bool[n+1];
    isPrime[2] = true;
    for(int i=3; i<n+1; i+=2)  // 0, 1 and all even are not prime, false
        isPrime[i] = true;
    for(int i=2; i<=sqrt(n); i++){  // O(sqrt(n))
        if(isPrime[i]){
            for(int j=i*i; j<=n; j+=2*i)   // O(loglogn)
                isPrime[j] = false;
        }
    }

    for(int i=3; i<=n; i+=2) {
        if (isPrime[i]){
	    cout << i <<' ';        
	    count++;
		}
    }
    delete [] isPrime;
    return count;
}


int main() {

    //cout <<  countPrime(1000000000)<<'\n';
    cout << countPrime2(71) << '\n';

}

/* As for num=1000000000, countPrime needs 33s, countPrime2 need 12s
 *
 */
