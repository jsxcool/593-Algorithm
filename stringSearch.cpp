// designed for keyword search
#include<iostream>
#include<vector>
#include <algorithm>    // std::max
using namespace std;

// return all matched position
// O((len1-len2)*len2)   omega(len1-len2)
vector<int> naiveSearch(string container, string target){  
	vector<int> ret;
	int len1 = container.size();
	int len2 = target.size();
	for(int i=0; i<len1-len2+1; i++){
		for(int j=0; j<len2; j++){
			if(target[j] != container[i+j])
				break;
			if(j==len2-1)  // the last char hase been checked
				ret.push_back(i);
		}
	}
	return ret;
}

// 难点： charTable is for pattern，但我们需要用txt的值来对应charTable
// O((len1-len2)*len2)    omega(len1/len2)
vector<int> BoyerMoore(string txt, string pattern){
	vector<int> ret;
	int len1 = txt.size();
	int len2 = pattern.size();
	
	// this is for pattern
	int charTable[256];  // actually, this is for mapping char(last occurance) to its position
	// Initialize all occurrences as -1 
	for(int i=0; i<256; i++)
		charTable[i] = -1;
	// fill char's last occurance postion to the charTable 	
	for(int i=0; i<len2; i++)
		charTable[pattern[i]] = i;
	
	int p = 0; // p is the searching pointer (not the pointer type)
	while(p <= len1 - len2){
		int j = len2 - 1; // checking from back
		
		// Find the first mismatching char from back
		while(j>=0 && pattern[j] == txt[p+j])
			j--;
		
		if(j>0){
			// shift the pattern to let mismatched chars become aligned 
			p +=  (j - charTable[txt[j]]);
			// if txt[j] does NOT exist in pattern (charTable[txt[j]=-1]), shift the distance of len2
			// p += max(j - charTable[txt[j]], 1);  ??? 
		}
		
		else{ // match all chars
			ret.push_back(p);
			// let the next char in txt align with the same char in pattern
			p += (len2 - charTable[txt[p+len2]]);
			// for situation, "aaaaaaaa", "aa", just move 1 forward
		}
	
	}
	
	return ret;
}


int main(){
	string mystring = "aaaaaaaaaaaaaa";
	//vector<int> ret = naiveSearch(mystring, "fkd") ;
	vector<int> ret2 = BoyerMoore(mystring, "aaa") ;
	for(int i=0; i<ret2.size(); i++)
		cout << ret2[i] << ' ';
	cout << '\n';
}
