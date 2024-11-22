#include "helper.h"

int main() {
	Tree root;

	initTree(&root);

	insertTree(&root, 10);
	insertTree(&root, 12);
	insertTree(&root, 7);
	insertTree(&root, 8);
	insertTree(&root, 4);
	insertTree(&root, 3);

	inorder(root);

	return 0;
}
