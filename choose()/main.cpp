#include <iostream>
#include <numeric>
#include <random>
#include <iomanip>
using namespace std;

void divideCommon(double& a, double& b) {   //gcd(a,b)  in c++ std17
    int divisor = gcd(int(a), int(b));
    a /= divisor;
    b /= divisor;
}

double choose(int n, int r){
    double denominator=1, numerator = 1;
    for(int count = 1; r>0 ; r--, n--, count++){
        numerator *= r;
        denominator *= n;

        if(count%5 == 0)
            divideCommon(numerator, denominator);
    }

    return denominator/numerator;
}


int main() {
    int testCases[][3] = {
            {0, 0, 1},

            {1, 0, 1},
            {1, 1, 1},

            {2, 0, 1},
            {2, 1, 2},
            {2, 2, 1},

            {5, 0, 1},
            {5, 1, 5},
            {5, 2, 10},

            {6, 3, 20}
    };
    const int numTestCases = 10;

    for (int i = 0; i < numTestCases; i++) {
        int n = testCases[i][0];
        int r = testCases[i][1];
        int result = testCases[i][2];

        if (choose(n, r) != result) {
            cerr << "Failed test case: choose(" << n << ", " << r << ") = " << result << '\n';
        }
    }

    cout << "Large number tests\n";
    cout << setprecision(15);
    cout << choose(52, 6) << "\n";
    cout << choose(52, 26) << "\n";
    cout << choose(150, 5) << "\n";

    cout << choose(500, 250);
}