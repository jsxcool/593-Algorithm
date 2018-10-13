#include<iostream>
#include<fstream>
#include<vector>
#include<climits>
using namespace std;

class Point {
public:
  double x,y;
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
	friend ostream& operator << (ostream& s, const GrowArray& g){
		for(int i=0; i<g.size; i++)
			s << g.p[i] <<' ';
		return s;
	}
};

class ConvexHull{
private:
	int size;  // suqre : size*size
	double minx, maxx, miny, maxy;
	vector<Point> data;
	GrowArray<Point>** arr;
public:
	ConvexHull(int size): size(size) {
		arr = new GrowArray<Point>*[size];
		for(int i=0; i<size; i++)
			arr[0] = new GrowArray<Point>[size];
	}
	~ConvexHull(){
		for(int i=0; i<size; i++)
			delete [] arr[i];
	}
	
	void read(const char* file){
		ifstream f(file, ifstream::in);
		double x, y;
		minx = INT_MAX;
		miny = INT_MAX;
		maxx = INT_MIN;
		maxy = INT_MIN;
		while(!f.eof()){
			f >> x >> y;
			cout << x << ' '<< y << '\n';
			data.push_back(Point(x, y));
			if(x > maxx) maxx = x;
			if(x < minx) minx = x;
			if(y > maxy) maxy = y;
			if(y < miny) miny = y;
		}
		f.close();
	}
	
	
	void printMinMax(){
		cout <<"min, max X: "<<minx << ' ' << maxx << '\n';
		cout <<"min, max Y: "<<miny << ' ' << maxy << '\n';
	}
	
};


int main(){
// for homework n=16
  ConvexHull ch(16); // create a 16x16 grid of GrowArray
  ch.read("convexhullpoints.dat");
  //ch.printAllListSizes(); // tell us how many are in each list
  ch.printMinMax(); // print minx, maxx, miny, maxy
  //ch.printPerimeterClockWiseOrder(); // p1,p2,p3,p4,p8,p12,p16..
  /*
example shown n=4
     -----------------------
     | p1 | p2  | p3  | p4 |
     |    |     |     |    |
     +----+-----+-----+----+
     | p5 | p6  | p7  | p8 |
     |    |     |     |    |
     +----+-----+-----+----+
     | p9 | p10 | p11 | p12|
     |    |     |     |    |
     +----+-----+-----+----+
     | p13| p14 | p15 | p16|
     |    |     |     |    |
     +----+-----+-----+----+
   */
   return 0;
}
