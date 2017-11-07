#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Tree {
	public:
		Tree();
		char val;
		size_t freq;

		Tree* lhs;
		Tree* rhs;
		string code;
};
Tree::Tree(){
	val = '\0';
	freq = 0;
	lhs = nullptr;
	rhs = nullptr;
	code = "";
}

void insertChar(vector<Tree>& freqs, char c){
	if (freqs.size() == 0){
		Tree t;
		t.val = c;
		t.freq = 1;
		freqs.push_back(t);
	}

	bool in_freqs = false;
	size_t pos;
	for(size_t i=0; i < freqs.size(); i++){
		if (freqs[i].val == c){
			in_freqs = true;
			pos = i;
		}
	}
	//sorted insertion in vector, bigger first
	Tree t;
	if (in_freqs){
		t = freqs[pos];
		t.freq++;
		freqs.erase(freqs.begin()+pos);
	}
	else{
		t.val = c;
		t.freq = 1;
	}
	for (size_t i = 0; i < freqs.size(); i++){	
		if (freqs[i].freq < t.freq){
			freqs.insert(freqs.begin()+i, t);
			return;
		}
	}
	//no frequency less than the current one, so we push
	//current node to the end of the tree
	freqs.push_back(t);
}

Tree buildTree(const vector<Tree>& tr){
	vector<Tree> v = tr;
	while(v.size() > 2){
		Tree t;
		Tree right = v[v.size()-1];
		v.pop_back();
		Tree left = v[v.size()-1];
		v.pop_back();
		t.rhs = new Tree;
			t.rhs->val = right.val;
			t.rhs->freq = right.freq;
		t.lhs = new Tree;
			t.lhs->val = left.val;
			t.lhs->freq = left.freq;
		t.freq = right.freq + left.freq;
		if(v.size() == 0){
			v.push_back(t);
		}
		else{
			for(size_t i = 0; i < v.size(); i++){
				if(v[i].freq < t.freq){
					v.insert(v.begin()+i, t);
				}
			}
		}
	}
	return v[0];
}

void addCodesToTree(Tree &t, map<char, string>& codes, string acc=""){
	if (t.lhs == nullptr && t.rhs == nullptr){
		t.code = acc;
		char c = t.val;
		string cd = t.code;
		codes.insert( std::make_pair(c, cd) );
		return;
	}
	if(t.lhs != nullptr)
		addCodesToTree(*(t.lhs), codes, acc+"0");
	if(t.rhs != nullptr)
		addCodesToTree(*(t.rhs), codes, acc+"1");
}

int main(int argc, char** argv){

	std::fstream ifile("infile.txt");
	char tmp;
	vector<Tree> freqs;
	while(!ifile.eof() && ifile.read(&tmp, 1)){
		insertChar(freqs, tmp);
	}
	std::cout << std::endl;
	//done building vector, now we will build the tree
	Tree tr = buildTree(freqs);
	map<char, string> codes;
	addCodesToTree(tr, codes);
	//buildHeader(tr, codes);
	

	return 0;
}
