#ifndef HELPER_H
#define HELPER_H

#define MAX 5
#define INFINITY 9999

typedef int Matrix[MAX][MAX];

typedef struct {
	int u;
	int w;
	int weight;
} Edge;

typedef struct node {
	Edge edge;
	struct node *next;
} EdgeNode;

EdgeNode *createEdgeNode(Matrix matrix);

void displayEdgeNode(EdgeNode *head);

#endif
