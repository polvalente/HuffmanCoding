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

void sortTree(tree* t, int base_nodes){
	//placeholder sort, using bubble sort
	for(int i = 0; i < base_nodes-1; i++){
		for(int j = 0; j < base_nodes-1; j++){
			if(t[j] < t[j+1]){
				tree temp = t[j];
				t[j] = t[j+1];
				t[j+1] = temp;
			}
		}
	}
}

tree* reduceTree(tree* t, int base_nodes){
	sortTree(t, base_nodes); // sort with higher frequencies first
	while(base_nodes > 1){
	// merge last node into second to last
		tree new_node;
		new_node.frequency = t[base_nodes-2] + t[base_nodes-1];
		new_node.value = "";
		new_node.symbol = '\0';

		char *new_value = malloc(strlen(t[base_nodes-2].value) + 1);
		new_value[0] = '0';
		strcat(new_value, t[base_nodes-1].value);
		t[base_nodes-2].value = new_value;

		char *new_value = malloc(strlen(t[base_nodes-1].value) + 1);
		new_value[0] = '1';
		strcat(new_value, t[base_nodes-1].value);
		t[base_nodes-1].value = new_value;

		new_node.leftChild = t[base_nodes-2];
		new_node.rightChild = t[base_nodes-1];

	// decrement base_node count
	base_nodes--; // we do not lose the pointer to the last position, so this is ok

	// re-sort tree
	sortTree(t, base_nodes); // sort with higher frequencies first
	}

	return t;
}

tree* parseFile(input, int* base_nodes){
}
