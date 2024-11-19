#ifndef HELPER_H
#define HELPER_H

#include <stdbool.h>

typedef struct node {
	int data;
	struct node *left;
	struct node *right;
} Node, *Tree;

void initTree(Tree *root);
void insertTree(Tree *root, int data);
void removeTree(Tree *root, int data);

bool contains(Tree *root, int data);

void inorder(Tree root);

#endif
