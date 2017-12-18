#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

typedef struct tree {
	int frequency;
	char value;
	char symbol;
	tree *leftChild;
	tree *rightChild;
} tree;

tree* alloc_tree(int frequency, char value, tree* leftChild, tree* rightChild);
void del_tree(tree* tree);

void writeOutput(char* input, char* output, tree* huffmanTree);

tree* parseFile(input);
tree* reduceTree(tree* tree);

char findSymbol(char symbol, tree* huffmanTree);

#endif
