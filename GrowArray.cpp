#include<iostream>
using namespace std;

class GrowArray {
private:
	int capacity; // the size of the block of memory
	int size;     // how many are used
	int* p;       // pointer to the block
	void checkGrow() { // 
		if(size == capacity){
			int* old = p;
			capacity *= 2 + 1;   // in case of capacity = 0
			p = new int[capacity];
			for(int i=0; i<size; i++)
				p[i] = old[i];
		}
	}
	
public:
  GrowArray() { 
  	p = nullptr;
    capacity = 0;
    size = 0;
  }
  GrowArray(int initialSize): capacity(initialSize), size(0), p(nullptr) {
  	p = new int[capacity];
  }
  ~GrowArray() { delete [] p; }
	
	void insertEnd(int v) { //O(1)
		checkGrow();
		p[size++] = v;   // ++ after assigning
	}
	void insertStart(int v) {
	}
	void insert(int pos, int v) {
	}
	void removeStart() {
	}

	void removeEnd() {
	}
	friend ostream& operator <<(ostream& s, const GrowArray& b) {
		for (int i = 0; i < b.size; i++)
			s << b.p[i] << ' ';
		return s;
	}
};


int main() {
	GrowArray b;
	for (int i = 0; i < 10; i++)
		b.insertEnd(i);
	/*for (int i = 0; i < 10; i++)
		b.insertStart(i);
	cout << b << '\n';
	for (int i = 0; i < 10; i++)
		b.removeStart();
	b.removeEnd();*/
	cout << b << '\n';
	
}
