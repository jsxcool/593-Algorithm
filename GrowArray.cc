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
			capacity *= 2; 
			p = new int[capacity];
			for(int i=0; i<size; i++)
				p[i] = old[i];
			delete [] old;
		}
	}
	
public:
  GrowArray() { 
 	p = new int;
	capacity = 1;
    size = 0;
  }
  GrowArray(int initialSize): capacity(initialSize), size(0) {
  	p = new int[capacity];
  }
  ~GrowArray() { delete [] p; }
	
	void insertEnd(int v) { //O(1)
		checkGrow();
		p[size++] = v;   // ++ after assigning
	}
	void insertStart(int v) {
		checkGrow();
		for(int i=size; i>0; i--)
			p[i] = p[i-1];
		p[0] = v;
		size++;
	}

	void insert(int pos, int v) {
		checkGrow();
		for(int i=size; i>=pos; i--)
			p[i+1] = p[i];
		p[pos] = v;		
		size++; 
	}
	
	void removeStart() {
		for(int i=0; i<size-1; i++)
			p[i] = p[i+1];
		size--;
	}

	void removeEnd() {
		size--;
	}
	
	friend ostream& operator << (ostream& s, const GrowArray& g){
		for(int i=0; i<g.size; i++)
			s << g.p[i] <<' ';
		return s;
	}
	
};


int main() {
	GrowArray b;
	for (int i = 0; i < 10; i++)
		b.insertEnd(i);
	for (int i = 0; i < 10; i++)
		b.insertStart(i);
	cout << b << '\n';
	for (int i = 0; i < 10; i++)
		b.removeStart();
	b.removeEnd();
	cout << b << '\n';

}


