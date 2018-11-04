#include<iostream>
#include<stack>
using namespace std;

int main(){
	stack<int> nums;
	for(int i=0; i<10; i++)
		nums.push(i);
	//cout << nums[5] << '\n';  index access is not allowed
	cout << nums.top() << '\n';  // the element on the top of stack
	nums.pop();                  // pop out the top element
	cout << nums.top() << '\n';	 

}
