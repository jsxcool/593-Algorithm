#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main(){
// for temporary variables, they are existing in cache. After running the program, they will be erased automatically.
	int a[2000000]; 
	for(int i=0; i<2000000; i++)
		a[i] = i;
	cout << sizeof(a) << '\n';  // 8M 
	// can NOT bigger than 8M, cache is SMALL!!!
	
	
	int* aa = new int[1000000000];  // 4G
	for(int i=0; i<1000000000; i++)
		aa[i] = i;
	cout << aa[11111] << '\n';
	delete [] aa;
	// can be as high as 4G by allocating memory, even 8G, depends on your memory 
}

