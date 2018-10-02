#include<iostream>
#include<algorithm>
using namespace std;

// return the index of the target
int searchBisection(int x[], int n, int target){  
	int l = 0, r = n-1;
	while(l < r){
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

int main(){
	int x[] = {1,2,3,4,5,6,7,11,15,19,26,39};
	cout << searchBisection(x, 12, 39) << '\n';
}
