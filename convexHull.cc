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
  	int getSize() { return size; }
  	
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
	
	void printMinMax(){
		if(size == 0){
			cout << 0 << ' ';
			return ;
		} 
		double minx, maxx, miny, maxy;
		minx = maxx = p[0].x;
		miny = maxy = p[0].y;
		for(int i=1; i<size; i++){
			if(p[i].x < minx)
				minx = p[i].x;
			if(p[i].x > maxx)
				maxx = p[i].x;
			if(p[i].y < miny)
				miny = p[i].y;
			if(p[i].y > maxy)
				maxy = p[i].y;
		}	
		cout << "minx:"<<minx<<"miny:"<<miny<<"maxx:"<<maxx<<"maxy:"<<maxy<<' ';
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
			arr[i] = new GrowArray<Point>[size];		
	}
	~ConvexHull(){
		for(int i=0; i<size; i++)
			delete [] arr[i];
		delete [] arr;
	}
	
	void read(const char* file){
		ifstream f(file, ifstream::in);
		minx = INT_MAX;
		miny = INT_MAX;
		maxx = INT_MIN;
		maxy = INT_MIN;
		double x=0, y=0;
		f >> x >> y;
		while(!f.eof()){    // last point read in twice, ????
			data.push_back(Point(x, y));
			if(x > maxx) maxx = x;
			if(x < minx) minx = x;
			if(y > maxy) maxy = y;
			if(y < miny) miny = y;
			f >> x >> y;
		}
		f.close();
		double unitX = (maxx - minx)/size;
		double unitY = (maxy - miny)/size;
		int len = data.size();
		for(int i=0; i<len; i++){
			//in case exceeding len for max - min
			int indexX = (data[i].x-minx-0.0001)/unitX;  
			int indexY = (maxy-data[i].y-0.0001)/unitY;
			arr[indexY][indexX].insertEnd(data[i]);
		}
	}
	
	void printMinMax(){
		cout <<"min, max X: "<<minx << ' ' << maxx << '\n';
		cout <<"min, max Y: "<<miny << ' ' << maxy << '\n';
	}
	
	void printAllListSizes(){
		for(int i=0; i<size; i++){
			for(int j=0; j<size; j++)
				cout << arr[i][j].getSize()<<' ';
			cout << '\n' ;
		}
	}
	
	void printPerimeterClockWiseOrder(){
		for(int j=0; j<size; j++)
			arr[0][j].printMinMax();
		cout << '\n';
		for(int i=1; i<size-1; i++){
			arr[i][0].printMinMax();
			cout <<string((size-2)*3, ' ');
			arr[i][15].printMinMax();
			cout <<'\n';
			}
		for(int j=0; j<size; j++)
			arr[15][j].printMinMax();
		cout << '\n';
	}
	
};


int main(){
// for homework n=16
  ConvexHull ch(16); // create a 16x16 grid of GrowArray
  ch.read("convexhullpoints.dat");
  ch.printAllListSizes(); // tell us how many are in each list
  ch.printMinMax(); // print minx, maxx, miny, maxy
  ch.printPerimeterClockWiseOrder(); // p1,p2,p3,p4,p8,p12,p16..
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
