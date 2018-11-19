#include<iostream>
#include<vector>
#include<fstream>
#include<string>
using namespace std;

string load(const char* file){
	ifstream f(file);
	string output, temp;
	int i=0;
	while(!f.eof()){
		f >> temp;
		output += (" "+temp);
		i++;
		if(i>10)
			break;
	}
	return output;
}

int main(){
	string dictionary = load("dict.txt");
	cout << dictionary << '\n';
} 
