#include <string>
#include <vector>

#include "HuffmanTree.h"
#include "HuffmanCompressor.h"

using std::vector;
using std::string;

typedef unsigned char byte;

/*class HuffmanCompressor {
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
};*/

void HuffmanCompressor::EncodeHeader(HuffmanTree tree){
	map<byte, string>& codes = tree.getCodes();
	header = vector<byte>(4);
	uint32_t counter = 0;
	
	for(auto const& pair: codes){
		byte value = pair.first;
		string code = pair.second;
		
		/*Each pair of the map will take up:
		 * 1 byte for the byte value
		 * 4 bytes for the length of the code
		 * length bytes for the code
		 * */
		uint32_t length = code.length(); // length = length_3 length_2 length_1 length_0
		byte length_3 = static_cast<byte>((0xFF000000 & length) >> 24);
		byte length_2 = static_cast<byte>((0x00FF0000 & length) >> 16);
		byte length_1 = static_cast<byte>((0x0000FF00 & length) >> 8);
		byte length_0 = static_cast<byte>((0x000000FF & length));
		header.push_back(length_0);
		header.push_back(length_1);
		header.push_back(length_2);
		header.push_back(length_3);

		header.push_back(value);

		for (auto c: code){
			header.push_back(static_cast<byte>(c));
		}

		counter += (length + 1 + 4)* sizeof(byte); 
	}

		header[0] = static_cast<byte>((0xFF000000 & counter) >> 24);
		header[1] = static_cast<byte>((0x00FF0000 & counter) >> 16);
		header[2] = static_cast<byte>((0x0000FF00 & counter) >> 8);
		header[3] = static_cast<byte>((0x000000FF & counter)     );
}

void HuffmanCompressor::DecodeHeader(){
	uint32_t size = 0;
	uint32_t shift = 1; // 256 = 2 ˆ 8;

	for(int i = 3; i >= 0 ; i--){
		uint32_t current = header[i];
		size += current * shift;
		shift *= 256;
	}
	
	i = 4;
	map<byte, string> codes;
	while(i < size + 4){
		uint32_t code_length = 0;
		uint32_t shift = 1; // 256 = 2 ˆ 8;

		for(int c = 3;  c >= 0 ;c--){
			uint32_t current = header[i+c];
			code_length += current * shift;
			shift *= 256;
		}
		i+=4;
		byte value = header[i];
		string code = "";
		for(size_t c = 0; c < code_length; c++){
			code += vector[i+c];
		}
		i+=code_length;
		codes.insert( std::make_pair(value, code));
	}
}
