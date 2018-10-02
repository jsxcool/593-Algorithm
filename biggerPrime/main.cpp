#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Bitvec{
private:
    uint32_t size;  // The number of bits
    uint64_t* bits; // used to store the bits as a vector of 64-bit
    uint32_t words; // how many words(64-bit computer: 1 word = 64 bits) are needed
public:
    Bitvec(uint32_t size, bool b):
            size(size), words((size+63)/64), bits(new uint64_t[words]){
        uint64_t val = b ? 0xFFFFFFFFFFFFFFFF : 0;
        for(int i=0; i<words; i++)
            bits[i] = val;
    }

    ~Bitvec() { delete [] bits; }
    Bitvec(const Bitvec& orig) = delete;
    Bitvec& operator = (const Bitvec& orig) = delete;

    void setTrue(uint32_t i){
        bits[i >> 6] |=   1L << (i & 0x3F);
    }
    void setFalse(uint32_t i){
        bits[i >> 6] &=  ~(1L << (i & 0x3F));
    }
    bool test(uint32_t i) {
        return (bits[i >> 6] & 1L << (i & 0x3F)) != 0;
    }
};

vector<int> getPrimes(uint64_t num){  // Eratosthenes' sieve.
    vector<int> primes;
    Bitvec isPrime(num+1, true);  // num -- isPrime[num]

    for(int i=2; i<num+1; i+=2)
        isPrime.setFalse(i);
    isPrime.setTrue(2);
    // 0, 1 and all even are not prime, false

    for(int i=2; i<=sqrt(num); i++){
        if(isPrime.test(i)){
            for(int j=i*i; j<=num; j+=2*i)
                isPrime.setFalse(j);
        }
    }

    for(int i=2; i<=num; i++) {
        if (isPrime.test(i))
            primes.push_back(i);
    }
    return primes;
}

// this function works only if a > 2
int countPrime(uint64_t a, uint64_t b){
    vector<int> primes = getPrimes(int(sqrt(b)));
    int len = primes.size();

    Bitvec isPrime(b-a+1, true);   // a -- isPrime[0]

    for(uint64_t i=a; i<=b; i++){
        for(int j=0; j<len; j++){
            if(i % primes[j] == 0) {
                isPrime.setFalse(i-a);
                break;
            }
        }
    }

    int count = 0;
    for(int i=0; i<b-a+1; i++){
        if(isPrime.test(i) == true) {
            count++;
        }
    }
    return count;
}

int main() {
    cout << countPrime(2000000000000, 2000000100000);  //with bitvec, running about 4.5s
    // almost the same time with bool array: isPrime[i]
}

