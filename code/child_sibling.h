//
// Created by Pioooooo on 2020/11/12.
//

#ifndef TMP__CHILD_SIBLING_H_
#define TMP__CHILD_SIBLING_H_

#include <functional>

const int n = 10;
int m;

struct Node {
	int c = -1, s, w;
} tree[n];

void add_edge(int p, int c, int w) {
	tree[c].s = tree[p].c;
	tree[p].c = c;
	tree[c].w = w;
}

void traverse_outedges(int u, std::function<void(int)> foo) {
	for (int v = tree[u].c; ~v; v = tree[v].s) {
		foo(v);
	}
}

#endif //TMP__CHILD_SIBLING_H_
