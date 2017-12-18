#include "Huffman.h"
#include <stdlib.h>

tree* alloc_tree(int frequency, char symbol, char* value, tree* leftChild, tree* rightChild){
	tree* t = malloc(sizeof(tree));
	t->frequency = frequency;
	t->leftChild = leftChild;
	t->rightChild = rightChild;

	t->symbol = malloc(strlen(symbol)+1);
	strncpy(t->symbol, symbol, strlen(symbol));

	t->value = malloc(strlen(value)+1);
	strncpy(t->value, value, strlen(value));

	return t;
}

void del_tree(tree* tree){
	if (tree->leftChild != NULL){
		del_tree(tree->leftChild);
	}
	if (tree->rightChild != NULL){
		del_tree(tree->rightChild);
	}
	free(t->value);
	free(t->symbol);
	free(tree);
}

char findSymbol(char symbol, tree* t){
	char s[2] = {symbol, '\0'};
	if (t == NULL)
		return NULL;

	if (strcmp(t->symbol, s) == 0){
		return t->value;
	}

	if (strstr(t->leftChild, symbol)){
		return findSymbol(symbol, t->leftChild);
	}
	if (strstr(t->rightChild, symbol)){
		return findSymbol(symbol, t->rightChild);
	}
	return NULL;
}
