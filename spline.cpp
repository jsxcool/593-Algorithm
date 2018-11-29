#include<iostream>
using namespace std;

class TriDiagonalMatrix{
private:
	int width;
	double** val;
public:
	// v1 is m[0][0], v2 is m[0][1]
	TriDiagonalMatrix(int d, double v1, double v2): width(d){
		val = new double*[width];  
		for(int i=0; i<width; i++)
			val[i] = new double[width];
		
		val[0][0] = v1, val[0][1] = v2;
		for(int i=1; i<width-1; i++){ // O(3n-2) = O(n)
			val[i][i-1] = v2;
			val[i][i] = v1*2;
			val[i][i+1] = v2;
		}
		val[width-1][width-1] = v2, val[width-1][width-2] = v1;
	}
	
	friend ostream& operator << (ostream& s, const TriDiagonalMatrix& m){
		for(int i=0; i<m.width; i++){  
			for(int j=0; j<m.width; j++){
				if(abs(i-j)<=1)
					s << m.val[i][j] << '\t';
				else 
					s << 0 << '\t' ;
			}
			s << '\n';
		}
		return s;
	}
};


int main(){
	TriDiagonalMatrix tdm(6, 2, 1);
	cout << tdm << '\n';
}
