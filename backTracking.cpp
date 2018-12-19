/* Backtracking is to generate all different permutations.
   If there exists the same values in the array, there will be error.
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 4;
int x[N] = {1,2,3,4};

void print(){
	for(int i=0; i<N; i++)
		cout << x[i] << ' ';
	cout << '\n';
}

// O(2 * N!)
// backtracking: exchange each element to the end, then
// recurssively permuting the others
void generate1(int n){
	if(n==1)   // because the last swap is x[0]--x[1]
		print();
	for(int i=0; i<n; i++){
		swap(x[i], x[n-1]);
		generate1(n-1);
		swap(x[i], x[n-1]); // restore
	}
} 

// O(N!)
// heap's: where can we find the next element to put at the end ?
// if n is odd, put 0 to the end; if n is even, put i to the end.
void generate2(int n){
	if(n==1)   // because the last swap is x[0]--x[1]
		print();
	for(int i=0; i<n; i++){
		generate2(n-1);
		swap(x[n % 2 ? 0:i], x[n-1]);
	}
} 


int main() {
	generate1(N);
	cout << "************************************\n";
	generate2(N);
}
