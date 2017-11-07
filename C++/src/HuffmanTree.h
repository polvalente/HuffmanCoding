#ifndef _HUFFMAN_TREE_H
#define _HUFFMAN_TREE_H

#include <vector>
#include <string>
#include <map>

using std::vector;
using std::string;

typedef unsigned char byte;

class HuffmanTree {
	public:
		Tree();
		byte value;
		size_t frequency;
		string code;

		Tree *lhs, *rhs;

		void insertByte(vector<HuffmanTree>& frequencies, byte b);

		void buildTree(const vector<Tree>& tree);

		void addCodesToTree(HuffmanTree &t, map<byte, string>& codes, string acc="");

		const map<byte, string>& getCodes(){return codes;}

	private:
		HuffmanTree hTree;
		map<byte, string>& codes;
};

#endif
