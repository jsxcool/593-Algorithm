#include<iostream>
#include<random>
using namespace std;

// x^n % m
int powerMod(int x, int n, int m){ // O(logn)
	int ret = 1;
	while(n>0){
		if(n%2==1)
			ret *= x % m;
		x = x*x;
		n = n/2;
	}
	return ret;
}

/* Fermat: for every prime p, a^(p-1) % p == 1     (1<a<p)
 * i.e. If a^(p-1) % p != 1, p can't be prime; if ==1, may be prime 
*/
bool fermat(int n){
	for(int i=0; i<10; i++){    // test 10 times
		int a = rand()%(n-2) + 2;
		int reminder = powerMod(a, n-1, n);
		if(reminder != 1)
			return false;
		}
	cout << "probably ";
	return true;
}

int main(){
	cout << powerMod(7,2,5) << '\n';
	cout << fermat(999) << '\n';
}
