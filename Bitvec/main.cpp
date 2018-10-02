#include <iostream>
#include <cmath>
using namespace std;

class Bitvec{
private:
    uint32_t size; // The number of bits
    uint64_t* bits; // used to store the bits as a vector of 64-bit
    uint32_t words; // how many words(64-bit computer: 1 word = 64 bits) are needed
public:
    Bitvec(uint32_t size, bool b):  //even 1 bit, it also occupies a unit
            size(size), words((size+63)/64), bits(new uint64_t[words]){
        uint64_t val = b ? 0xFFFFFFFFFFFFFFFF : 0;  //if b=true, val=0xfff..    else val=0
        for(int i=0; i<words; i++) // 会多赋值，但最后check的时候只检查到size即可
            bits[i] = val;  // bit[i] has 0~63 bits
    }

    ~Bitvec() { delete [] bits; }
    Bitvec(const Bitvec& orig) = delete;
    Bitvec& operator = (const Bitvec& orig) = delete;

    /*
     *  0000000001
     *  0000001000      << pos (eg. 3)
     *  xxxxxxyxxx      or operation
     *  xxxxxx1xxx
     */
    void set(uint32_t i){      // set bit[i]（第i位） to 1
        //bits[i/64] |= i << (i%64);    // priority:  '<<'  >  '|='
        bits[i >> 6] |= 1L << (i & 0x3F);
    }

    void clear(uint32_t i){    // set this bit[i]（第i位） to 0
        //bits[i/64] &= ~(i << (i%64));
        bits[i >> 6] &= ~(1L << (i & 0x3F));
    }

    bool test(uint32_t i) {   // the boolean value of 第i位
        return  (bits[i >> 6]  &  1L << (i & 0x3F)) != 0 ;
    }
};

int main() {
    Bitvec a(35, true);
    for(int i=0; i<35; i++)
        cout <<i<<':'<<a.test(i) << ' ';
    cout <<'\n';
    a.clear(33);
    //cout << a << '\n';
    for(int i=0; i<35; i++)
        cout <<i<<':'<<a.test(i) << ' ';

    // for size > 32, there comes a error

}
