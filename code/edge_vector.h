//
// Created by Pioooooo on 2020/11/12.
//

#ifndef TMP__EDGE_VECTOR_H_
#define TMP__EDGE_VECTOR_H_

#include <algorithm>
#include <vector>
#include <functional>

const int M = 30, n = 10;
int m;

struct Edge {
	int u, v, w;
}; // pseudo

std::vector<Edge> e;

void add_edge(int u, int v, int w) {
	e.push_back({u, v, w});
}

bool find_edge(int u, int v) {
	return std::find_if(e.begin(), e.end(), [&](const Edge &i) -> bool {
		return i.u == u && i.v == v;
	}) != e.end();
}

void traverse_outedges(int u, const std::function<void(int)> &foo) {
	for (int i = 0; i < e.size(); i++) {
		if (e[i].u == u) {
			foo(e[i].v);
		}
	}
}

#endif //TMP__EDGE_VECTOR_H_
