#include <stdio.h>
#include <stdlib.h>

#include "helper.h"

void initTree(Tree *root) {
	*root = NULL;
}

void insertTree(Tree *root, int data) {
	if (*root == NULL) {
		*root = (Tree)malloc(sizeof(Node));

		if (*root != NULL) {
			(*root)->data = data;
			(*root)->left = NULL;
			(*root)->right = NULL;
		}
	} else {
		insertTree((data < (*root)->data) ? &(*root)->left : &(*root)->right,
				   data);
	}
}

void removeTree(Tree *root, int data) {
	if (*root != NULL) {
		if (data < (*root)->data) {
			removeTree(&(*root)->left, data);
		} else if (data > (*root)->data) {
			removeTree(&(*root)->right, data);
		} else {
			if ((*root)->left == NULL && (*root)->right == NULL) {
				free(*root);
				*root = NULL;
			} else if ((*root)->left == NULL) {
				Tree temp = *root;
				*root = (*root)->right;
				free(temp);
			} else if ((*root)->right == NULL) {
				Tree temp = *root;
				*root = (*root)->left;
				free(temp);
			} else {
				Tree temp = (*root)->right;

				while (temp->left != NULL) {
					temp = temp->left;
				}

				(*root)->data = temp->data;
				removeTree(&(*root)->right, temp->data);
			}
		}
	}
}

void inorder(Tree root) {
	if (root != NULL) {
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}
