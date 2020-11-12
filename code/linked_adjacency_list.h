//
// Created by Pioooooo on 2020/11/12.
//

#ifndef TMP__LINKED_ADJACENCY_LIST_H_
#define TMP__LINKED_ADJACENCY_LIST_H_

#include <functional>

const int M = 30, n = 10;
int m;

struct Edge {
	int nxt, v, w;
} e[M]; //pseudo
int head[n]; // pseudo

void add_edge(int u, int v, int w) {
	e[m] = {head[u], v, w};
	head[u] = m++;
}

bool find_edge(int u, int v) {
	for (int i = head[u]; ~i; i = e[i].nxt) {  // ~i 表示 i != -1
		if (e[i].v == v) {
			return true;
		}
	}
	return false;
}

void traverse_outedges(int u, const std::function<void(int)> &foo) {
	for (int i = head[u]; ~i; i = e[i].nxt) {
		foo(e[i].v);
	}
}

#endif //TMP__LINKED_ADJACENCY_LIST_H_
