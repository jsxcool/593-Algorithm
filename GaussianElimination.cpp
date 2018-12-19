/* can be used to solve system of linear equations
(1)Swapping two rows, O(n)
(2)Multiplying a row by a nonzero number, 
(3)Adding a multiple of one row to another row. 
*/
#include <iostream>
using namespace std;

class Matrix{
private:
	int row, column;
	double** val;
public:
	Matrix(int r, int c): row(r), column(c){
		val = new double*[row];  // O(1), just allocate memory
		for(int i=0; i<row; i++)
			val[i] = new double[column];
	}
	
	void set(int i, int j, double v){
		val[i][j] = v;
	}
	
	// row-multiplication + back-substitution = O(n^3)
	// n(n-1) + (n-1)(n-2) + .... + 2*1 = O(n^3)
	void GaussianEliminationWithPartialPivot(){
	
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

int main() {
	
	
}
