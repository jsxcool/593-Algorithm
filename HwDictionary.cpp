#include<iostream>
#include<vector>
#include<fstream>
#include<string>
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

class HashMap{
private:
	int capacity, size;
	string* data;
public:
	HashMap(int c): capacity(c), size(0) {
		data = new string[capacity];
	}
	~HashMap() { delete [] data; }
	
	void add(string word){
		int basic = 2;
		int len = word.size();
		int sum = 0;
		for(int i=0; i<len; i++){
			int num = word[i] - 'a'; //a-0, b-1, c-2....
			sum += num*basic;
			basic *= 2; 
		}
		int pos = sum % capacity;
		while(!data[pos].empty()){
			pos++;
			if(pos==capacity)
				pos = 0;
		}
		data[pos] = word;
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
		int pos = sum % capacity;
		int count = 0;
		while(count < capacity){
			if(data[pos]==word)
				return true;
			if(data[pos].empty())  // when adding, continuous even if collision
				return false;
			pos++;
			if(pos==capacity)
				pos = 0;
			count++;
		}
		return false;
	}
	
	friend ostream& operator << (ostream& s, HashMap hs){
		for(int i=0; i<hs.capacity; i++){
			if(!hs.data[i].empty())
				s << hs.data[i] << ' ';
		}
		return s;
	}
};

void addToHash(string s, HashMap** dict){
	int index0 = s[0]-'a';   
	int index1 = s[1]-'a';
	if(s[2] == '\0')   // eg "aa" can't solve
		return ;
	string wordLeft = s.substr(2);
	dict[index0][index1].add(wordLeft);
}

void searchInHash(string s, HashMap** dict){
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
	vector<string> dictionary;
	dictionary = load("dict.txt");
	
	HashMap** dict;  // 26*26 HashMaps
	dict = new HashMap*[26];
	for(int i=0; i<26; i++){
		dict[i] = new HashMap(305);
	}
	/*addToHash("aabc", dict);
	cout << dict[0][0] << '\n'; */
	int len = dictionary.size();
	for(int i=0; i<len; i++){
		addToHash(dictionary[i], dict);
	}
	
	/*ifstream f("words.dat");
	string word;
	while(!f.eof()){
		f >> word;
		searchInHash(word, dict);
		cout << word << ' ';
	}
	f.close();*/
	searchInHash("apple", dict);
	
}
