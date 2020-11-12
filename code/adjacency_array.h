//
// Created by Pioooooo on 2020/11/12.
//

#ifndef TMP__ADJACENCY_ARRAY_H_
#define TMP__ADJACENCY_ARRAY_H_

#include <functional>

const int n = 10;
int m;

int adj[n][n]; // pseudo

void add_edge(int u, int v, int w) {
	adj[u][v] = w;
}

bool find_edge(int u, int v) {
	return adj[u][v];
}

void traverse_outedges(int u, std::function<void(int)> foo) {
	for (int v = 0; v < n; v++) {
		if (adj[u][v]) {
			foo(v);
		}
	}
}

#endif //TMP__ADJACENCY_ARRAY_H_
