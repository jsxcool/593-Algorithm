#include<iostream>
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

// test whether n is prime in k-time tests 
bool millerRabin(int n, int k){
	// d should be d*(2^r) = n-1 with d is odd
	int d = n-1, r=0;
	while(d%2==0){
		d /= 2;
		r++;
		}
	for(int i=0; i<k; i++){
		int a = rand()%(n-4) + 2;  //[2, n-2]
		int x = powerMod(a, d, n);  // x = a^d % n
		if(x==1 || x==n-1)
			continue;
		while(r != 1){
			x = x*x % n;
			if(x==1)
				return false;
			if(x == n-1)
				return true; //actually break and go to for loop
		}
		return false;
	}
}

int main(){
	cout << millerRabin(777, 10)<<'\n';
}
