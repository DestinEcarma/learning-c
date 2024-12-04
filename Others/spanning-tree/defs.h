#ifndef HELPER_H
#define HELPER_H

#define MAX 6
#define INF 999

typedef int Vertex;
typedef Vertex Matrix[MAX][MAX];

typedef struct {
	Vertex u, v;
	int weight;
} Edge;

#endif
