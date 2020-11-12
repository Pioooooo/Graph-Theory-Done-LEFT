//
// Created by Pioooooo on 2020/11/12.
//

#ifndef TMP__EDGE_ARRAY_H_
#define TMP__EDGE_ARRAY_H_

#include <algorithm>
#include <functional>

const int M = 30, n = 10;
int m;

struct Edge {
	int u, v, w;
} e[M]; // pseudo

void add_edge(int u, int v, int w) {
	e[m++] = {u, v, w}; // pseudo
}

bool find_edge(int u, int v) {
	return std::find_if(e, e + m, [&](const Edge &i) -> bool {
		return i.u == u && i.v == v;
	}) != e + m;
}

void traverse_outedges(int u, const std::function<void(int)> &foo) {
	for (int i = 0; i < m; i++) {
		if (e[i].u == u) {
			foo(e[i].v);
		}
	}
}

#endif //TMP__EDGE_ARRAY_H_
