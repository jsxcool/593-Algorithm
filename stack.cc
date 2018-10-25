#include <iostream>
using namespace std;

class Stack{
private:
	int sp; //stack piont pointing the top of the stack(which is null after the last data)
	int* data;
public:
	Stack(int n): sp(0), data(new int[n]) {}
	
	void push(int v){
		data[sp++] = v;
	} 
	int pop(){   // return the last data and remove it
		return data[--sp];
	}
	
	bool isEmpty(){
		return sp==0;
	}
	
	friend ostream& operator << (ostream& s, const Stack& st){
		for(int i=0; i<st.sp; i++)
			s << st.data[i] << ' ';
		return s;
	}
};

int main(){
	Stack a(8);
	for(int i=0; i<5; i++)
		a.push(i);
	cout << a << '\n';
	cout << a.pop();
	cout << a << '\n';
}
