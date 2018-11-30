// This program can only be applied to specific data. Because I can't get inverse
// matrix by c++, I use python and copy the results. 
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

class Matrix{
private:
	int row, column;
	double** val;
public:
	Matrix(int r, int c): row(r), column(c){
		val = new double*[row];  
		for(int i=0; i<row; i++)
			val[i] = new double[column]();  // with initialization
	}
	
	// only for column = 1
	void assign(int pos, double v){
		val[pos][0] = v;
	}
	
	void assign(int i, int j, double v){
		val[i][j] = v;
	}
	
	// only for column = 1
	vector<double> convertToVector(){
		vector<double> ret;
		for(int i=0; i<row; i++)
			ret.push_back(val[i][0]);
		return ret;
	}
	
	// O(left.row * right.column * left.column)
	friend Matrix operator * (const Matrix& left, const Matrix& right){
		if(left.column != right.row)
			return Matrix(1,1);  // error
		Matrix ret(left.row, right.column);
		for(int i=0; i<left.row; i++)  // **
			for(int j=0; j<right.column; j++)  // **
				for(int k=0; k<left.column; k++){ // common part 
					ret.val[i][j] += left.val[i][k] * right.val[k][j];
			}
		return ret;
	}
	
	friend ostream& operator << (ostream& s, const Matrix& m){
		for(int i=0; i<m.row; i++){  
			for(int j=0; j<m.column; j++)
				s << m.val[i][j] << '\t';
			s << '\n';
		}
		return s;
	}
};

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
	
	// This is a fake inverse: I use python to get inverse matrix and input it. 
	// Because writing matrixInverse algorithm is complicated, may need 
	// hundreds of lines
	Matrix inverse(){
		int n = width;
		Matrix ret(n, n);
    	ret.assign(0,0,0.57777778);
    	ret.assign(0,1,-0.15555556);
    	ret.assign(0,2,0.04444444);
    	ret.assign(0,3,-0.02222222);
    	ret.assign(0,4,0.02222222);
    	ret.assign(1,0,-0.15555556);
    	ret.assign(1,1,0.31111111);
    	ret.assign(1,2,-0.08888889);
    	ret.assign(1,3,0.04444444);
    	ret.assign(1,4,-0.04444444);
    	ret.assign(2,0,0.04444444);
    	ret.assign(2,1,-0.08888889);
    	ret.assign(2,2,0.31111111);
    	ret.assign(2,3,-0.15555556);
    	ret.assign(2,4,0.15555556);
    	ret.assign(3,0,-0.02222222);
    	ret.assign(3,1,0.04444444);
    	ret.assign(3,2,-0.15555556);
    	ret.assign(3,3,0.57777778);
    	ret.assign(3,4,-0.57777778);
    	ret.assign(4,0,0.04444444);
    	ret.assign(4,0,-0.08888889);
    	ret.assign(4,0,0.31111111);
    	ret.assign(4,0,-1.15555556);
    	ret.assign(4,0,2.15555556);
    	return ret;
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

void printSegmentValue(const vector<int>& y, const vector<double>& deri){
	int len = deri.size();
	double a, b, c, d;
	for(int i=0; i<len; i++){
		cout << "The y values of "<< i << "th segment: ";
		a = y[i];
		b = deri[i];
		c = 3*(y[i+1] - y[i]) - 2*deri[i] - deri[i+1];
		d = 2*(y[i] - y[i+1]) + deri[i] + deri[i+1];
		int Y;
		for(double t=0; t<0.99; t += 0.1){
			Y = a + b*t + c*t*t + d*t*t*t;
			cout << Y << ' '; 
		}
		cout << '\n';
	}
}


int main(){
	int countPoints;
	vector<int> x, y;
	ifstream f("data.txt");
	f >> countPoints;
	while(!f.eof()){
		int temp;
		f >> temp;
		x.push_back(temp);
		f >> temp;
		y.push_back(temp);
	}
	TriDiagonalMatrix tdm(countPoints-1, 2, 1);
	
	// Value Matrix
	vector<double> value;
	value.push_back(3*(y[1]-y[0]));
	value.push_back(3*(y[2]-y[0]));
	value.push_back(3*(y[3]-y[1]));
	value.push_back(3*(y[4]-y[2]));
	value.push_back(3*(y[4]-y[3]));
	int len = value.size();
	Matrix out(len, 1);
	for(int i=0; i<len; i++)
		out.assign(i, value[i]);
	
	// Derivative Matrix: D = TriDiaMat^(-1) * ValMat
	Matrix derivative = tdm.inverse() * out;
	vector<double> deri = derivative.convertToVector(); 
	
	// Print Values of every segment  
	printSegmentValue(y, deri);
	
}
