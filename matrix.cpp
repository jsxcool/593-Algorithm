/* In this file, we'll discuss the complex of initializing(assigning)
 * for different kinds of Matrixes . 
 */
#include<iostream>
using namespace std;

class Matrix{
private:
	int row, column;
	double** val;
public:
	Matrix(int r, int c, double v): row(r), column(c){
		val = new double*[row];  // O(1), just allocate memory
		for(int i=0; i<row; i++)
			val[i] = new double[column];
		for(int i=0; i<row; i++){  // brute force, O(r*c)
			for(int j=0; j<column; j++)
				val[i][j] = v;
		}
	}
	// O(left.row * right.column * left.column)
	friend Matrix operator * (const Matrix& left, const Matrix& right){
		if(left.column != right.row)
			return Matrix(1,1,0);  // error
		Matrix ret(left.row, right.column, 0);
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
				s << m.val[i][j] << ' ';
			s << '\n';
		}
		return s;
	}
};


// Lower/Upper Triangular Matrix: only fill(assign) half of the matrix,
// other parts are regarded as 0 
// complexity is the same as regular Matrix


// only fill the diagonal of the matrix (just consider row = column)
class DiagnolMatrix{
private:
	int width;
	double** val;
public:
	DiagnolMatrix(int d, double v): width(d){
		val = new double*[width];  
		for(int i=0; i<width; i++)
			val[i] = new double[width];
		for(int i=0; i<width; i++)  // O(n)
			val[i][i] = v;
	}
	
	// O(width)
	friend DiagnolMatrix operator * (const DiagnolMatrix& left, const DiagnolMatrix& right){
		if(left.width != right.width)
			return DiagnolMatrix(1, 0);  // error
		DiagnolMatrix ret(left.width, 0);	
		for(int i=0; i<left.width; i++)
			ret.val[i][i] = left.val[i][i] * right.val[i][i]; 
		return ret;
	}
	
	friend ostream& operator << (ostream& s, const DiagnolMatrix& m){
		for(int i=0; i<m.width; i++){  
			for(int j=0; j<m.width; j++){
				if(i==j)
					s << m.val[i][j] << '\t';
				else 
					s << 0 << '\t' ;
			}
			s << '\n';
		}
		return s;
	}
};


//fill three diagonals of the matrix (just consider row = column)
class TriDiagonalMatrix{
private:
	int width;
	double** val;
public:
	TriDiagonalMatrix(int d, double v): width(d){
		val = new double*[width];  
		for(int i=0; i<width; i++)
			val[i] = new double[width];
		
		val[0][0] = val[0][1] = v;
		for(int i=1; i<width-1; i++){ // O(3n-2) = O(n)
			val[i][i-1] = v;
			val[i][i] = v;
			val[i][i+1] = v;
		}
		val[width-1][width-1] = val[width-1][width-2] = v;
	}
};



int main(){
	Matrix a(2,2,6.6);
	DiagnolMatrix b(3, 8.8);
	TriDiagonalMatrix c(4, 9.9);
	Matrix d(2,3, 1.1);
	DiagnolMatrix e(3, 1.1);
	cout << b * e << '\n';	
}
