#include <stdio.h>
#include <stdlib.h>

#include "Huffman.h"

/* Constant definitions */
#define MIN_ARG_COUNT 2

/* Error definitions */
#define ARG_COUNT_ERROR 1;

int main(int argc, char** argv){
	char *outputFilename;
	if (argc != MIN_ARG_COUNT){
		printf("Usage: %s <input filename>\n", argv[0]);
		return ARG_COUNT_ERROR;
	}
	
	char *inputFilename = argv[1];

	if (argc == MIN_ARG_COUNT + 1){
		strncpy(outputFilename, inputFilename, strlen(inputFilename));
	}
	else{
		outputFilename = malloc(sizeof(char)*strlen(inputFilename)+5);
		strncpy(outputFilename, inputFilename, strlen(inputFilename));
		strcat(outputFilename, ".out");
	}

	initialHuffmanTree = parseFile(filename);
	huffmanTree = reduceTree(initialHuffmanTree);
	writeOutput(inputFilename, outputFilename, huffmanTree);

	free(outputFilename);
	del_tree(huffmanTree);
	return 0;
}
