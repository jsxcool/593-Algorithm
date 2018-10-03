#include<iostream>
#include<cmath>
using namespace std;

// Linear search : for i:0-->n,   O(n)   


// return the index of the target
// Binary search: only suitable for sorted array
// O(log n)
int searchBinary(int x[], int n, int target){  
	int l = 0, r = n-1;
	while(l <= r){
		int mid = (l+r)/2;
		if(x[mid] < target){
			l = mid + 1;
		}else if(x[mid] > target){
			r = mid - 1;
		}else{
			return mid;
		}
	}  
	return -1;   // can't find the target
}

// Golden Mean Search : fi = (sqrt(5) + 1) / 2 = 1.618
/*   1	 1   2   3   5   8   13  ....  fibonacci
*      1/1  2/1 3/2 5/3 8/5 13/8      ......    phi
*  used for finding the biggest elements in quadratic data (only have one peak) 
*/
const double phi = (sqrt(5) + 1) / 2 ;
int searchGoldenMean(int x[], int n){
    int l = 0, r = n-1;
    int s = int((r-l)/phi + 0.5);  // 4 eleminates, 5 becomes carry
    while(l < r){
        int a = r - s;   // a, b are the new interval boundaries
        int b = l + s;   // a < b
        if(x[a] < x[b] ){
            l = a;
            a = b;
            s = int((r-l)/phi + 0.5);
            b = l + s;
        }
        else{
            r = b;
            b = a;    
            s = int((r-l)/phi + 0.5);
            a = r - s;
        }
    }
    return l;
} 



int main(){
	int x[] = {1,2,3,4,5,6,7,11,15,19,26,39};
	int x2[] = {2,3,5,7,9,11,6,3,2,1};
	cout << searchBinary(x, 12, 39) << '\n';
	cout << searchGoldenMean(x2, 10)<<'\n';    // can NOT work !!!
}
