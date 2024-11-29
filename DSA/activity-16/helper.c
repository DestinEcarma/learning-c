#include <stdio.h>
#include <stdlib.h>

#include "helper.h"

EdgeNode *createEdgeNode(Matrix matrix) {
	EdgeNode *head = NULL;

	for (int u = 1; u < MAX; u++) {
		for (int w = 0; w < u; w++) {
			int weight = matrix[u][w];

			if (weight < INFINITY) {
				EdgeNode **trav = &head;

				while (*trav != NULL && (*trav)->edge.weight < weight) {
					trav = &(*trav)->next;
				}

				EdgeNode *newNode = (EdgeNode *)malloc(sizeof(EdgeNode));

				if (newNode != NULL) {
					newNode->edge = (Edge){u, w, weight};
					newNode->next = *trav;

					*trav = newNode;
				}
			}
		}
	}

	return head;
}

void displayEdgeNode(EdgeNode *head) {
	while (head != NULL) {
		printf("(%d, %d, %d)", head->edge.u, head->edge.w, head->edge.weight);
		head = head->next;

		if (head != NULL) {
			printf(" -> ");
		}
	}

	printf("\n");
}
