#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class GrowArray {
private:
	int capacity; // the size of the block of memory
	int size;     // how many are used
	T* p;       // pointer to the block
	void checkGrow() { 
		if(size == capacity){
			T* old = p;
			capacity *= 2; 
			p = new T[capacity];
			for(int i=0; i<size; i++)
				p[i] = old[i];
			delete [] old;
		}
	}
public:
	GrowArray() : p(new T), capacity(1), size(0) {}
  	GrowArray(int initialSize): capacity(initialSize), size(0) {
  		p = new T[capacity];
  	}
  	~GrowArray() { delete [] p; }
  	
  	GrowArray(const GrowArray& orig) = delete;
  	GrowArray& operator = (const GrowArray& orig) = delete;
	
	void insertEnd(T v) { //O(1)
		checkGrow();
		p[size++] = v;   // ++ after assigning
	}
};

void test1(int n) {   
	GrowArray<int> a;
	for (int i = 0; i < n; i++)
		a.insertEnd(i);
}

void test2(int n) {     // pre-allocate memory
	GrowArray<int> a(n);
	for (int i = 0; i < n; i++)
		a.insertEnd(i);
}

void test3(int n) {
	vector<int> a;
	for (int i = 0; i < n; i++)
		a.push_back(i);
}

void test4(int n) {    // pre-allocate memory
	vector<int> a;
	a.reserve(n);
	for (int i = 0; i < n; i++)
		a.push_back(i);
}

int main(){
	const int n = 1000000000;  // 1 billion
	test4(n);  
// with MacPro 
// test1 17.468s.    test2 9.092s    test3 21.602s    test4  14.225 s
}