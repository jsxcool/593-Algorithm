#include<iostream>
using namespace std;

double INFINITY = 99999999;

class LowerMatrixGraph{
private:
	int V;   // number of vertice
	double** val;
public:
	LowerMatrixGraph(int v): V(v){
		val = new double*[V];
		for(int i=0; i<V; i++)   // space complexity O((n+1)*n/2)
			val[i] = new double[i+1];
		for(int i=0; i<V; i++)
			for(int j=0; j<=i; j++)
				val[i][j] = INFINITY;  // all are infinity
	}
	
	void setValue(int i, int j, double value){
		if(i==j)
			return;
		if(i<j){
			int temp = i;
			i = j;
			j =temp;
		}
		val[i][j] = value;
	}
	
	// print all egdes
	friend ostream& operator << (ostream& s, const LowerMatrixGraph& gf){
		for(int i=0; i<gf.V; i++)
			for(int j=0; j<=i; j++){
				if(gf.val[i][j] != INFINITY){
					i>j?  s << j << "-->" << i << ": " << gf.val[i][j] << '\n' :
					s << i << "-->" << j << ": " << gf.val[i][j] << '\n';
				}
			} 
		return s;	
	}
	
};


int main(){
	LowerMatrixGraph gf(4);
	gf.setValue(0,1,3);
	gf.setValue(1,2,2.5);
	gf.setValue(2,3,1.1);
	gf.setValue(3,0,1);
	cout << gf; 
}

