#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<cmath>
using namespace std;

vector<string> load(const char* file){
	vector<string> words;
	ifstream f(file);
	string temp;
	while(!f.eof()){
		f >> temp;
		words.push_back(temp); 
	}
	f.close();
	return words;
}

class PerfectHash{
private:
	int capacity;
	string* data;
	void checkGrow(int sum){ 
		// give hash table more empty space; this is a prerequisite for O(1)
		if(sum >= capacity){  
			string* old = data;
			int oldlen = capacity;
			while(capacity <= sum)
				capacity *= 2;
			data = new string[capacity];
			for(int i=0; i<oldlen; i++){
				data[i] = old[i];
			}
			delete [] old;
		}
	}
public:
	PerfectHash(): capacity(10001) {
		data = new string[capacity]();
	}
	~PerfectHash() {
		delete [] data;
	}
	
	void add(string word){
		int basic = 2;
		int len = word.size();
		int sum = 0;
		for(int i=0; i<len; i++){
			int num = word[i] - 'a'; //a-0, b-1, c-2....
			sum += num*basic;
			basic *= 2; 
		}
		checkGrow(sum);
		data[sum] = word;
	}
	
	bool search(string word){
		int basic = 2;
		int len = word.size();
		int sum = 0;
		for(int i=0; i<len; i++){
			int num = word[i] - 'a'; //a-0, b-1, c-2....
			sum += num*basic;
			basic *= 2; 
		}
		if(data[sum] == word)
			return true;
		return false;
	}
	
};

void addToHash(string s, PerfectHash dict[26][26]){
	int index0 = s[0]-'a';   
	int index1 = s[1]-'a';
	if(s[2] == '\0')   // eg "aa" can't solve
		return ;
	string wordLeft = s.substr(2);
	dict[index0][index1].add(wordLeft);
}

void searchInHash(string s, PerfectHash dict[26][26]){
	int index0 = s[0] - 'a';
	int index1 = s[1] - 'a';
	if(s[2] == '\0')   // eg "aa" can't solve
		return ;
	string wordLeft = s.substr(2);
	if(dict[index0][index1].search(wordLeft))
		cout << s << " is found!\n";
	else
		cout << s << " is not found!\n";
}

int main(){
	PerfectHash dict[26][26];
	vector<string> dictionary;
	dictionary = load("dict.txt");
	int len = dictionary.size();
	for(int i=0; i<len; i++){  
		addToHash(dictionary[i], dict);
	}
	//addToHash("apple", dict);
	
	ifstream f("words.dat");
	string word;
	while(!f.eof()){
		f >> word;
		searchInHash(word, dict);
	}
	f.close();
}



