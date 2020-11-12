//
// Created by Pioooooo on 2020/11/12.
//

#ifndef TMP__ADJACENCY_LIST_H_
#define TMP__ADJACENCY_LIST_H_

#include <vector>
#include <functional>

const int n = 10;
int m;

struct Edge {
	int v, w;
};

std::vector<Edge> adj[n]; // pseudo

void add_edge(int u, int v, int w) {
	adj[u].push_back({v, w});
}

bool find_edge(int u, int v) {
	for (int i = 0; i < adj[u].size(); ++i) {
		if (adj[u][i].v == v) {
			return true;
		}
	}
	return false;
}

void traverse_outedges(int u, const std::function<void(int)> &foo) {
	for (int i = 0; i < adj[u].size(); i++) {
		foo(adj[u][i].v);
	}
}

#endif //TMP__ADJACENCY_LIST_H_
