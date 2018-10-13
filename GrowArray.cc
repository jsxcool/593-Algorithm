#include<iostream>
using namespace std;

class Point{
public:
	double x, y;
	Point(double x=0, double y=0) : x(x), y(y) {}
	friend ostream& operator << (ostream& s, const Point& p){
		s << "(" << p.x << ", " << p.y << ") ";
		return s; 
	}
};

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
	void insertStart(T v) {
		checkGrow();
		for(int i=size; i>0; i--)
			p[i] = p[i-1];
		p[0] = v;
		size++;
	}

	void insert(int pos, T v) {
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
	
	int getSize() const {
		return size;
	}
	
	friend ostream& operator << (ostream& s, const GrowArray& g){
		for(int i=0; i<g.size; i++)
			s << g.p[i] <<' ';
		return s;
	}
	
};


int main() {
	GrowArray<Point> b;
	for (int i = 0; i < 10; i++)
		b.insertEnd(Point(i,i));
	for (int i = 0; i < 10; i++)
		b.insertStart(Point(i,i));
	cout << b << '\n';
	for (int i = 0; i < 10; i++)
		b.removeStart();
	b.removeEnd();
	cout << b << '\n';
	cout << b.getSize() << '\n';

}


