#ifndef _HUFFMAN_COMPRESSOR_H_
#define _HUFFMAN_COMPRESSOR_H_

#include <string>
#include <vector>

#include "HuffmanTree.h"

using std::vector;
using std::string;

typedef unsigned char byte;

class HuffmanCompressor {
	public:
		HuffmanCompressor();
		EncodeHeader(HuffmanTree tree); // encode a tree into a file header
		DecodeHeader(vector<byte> header); // decode a header to build its huffman tree 
		write(string filename); // encode new file
		read(string filename); // decode a file

	private:
		vector<byte> header;
		HuffmanTree tree;
		vector<byte> fileContent;
};

#endif
