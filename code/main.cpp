#include <iostream>
#include <queue>
#include <cstring>

#include "edge_array.h"
//#include "edge_vector.h"
//#include "adjacency_array.h"
//#include "adjacency_list.h"
//#include "linked_adjacency_list.h"
//#include "child_sibling.h"
//#include "bianry_tree.h"

#ifndef TREE
bool visited1[n] = {false};

void dfs1(int u) {
	visited1[u] = true;
	std::cout << '(' << u;
	traverse_outedges(u, [&](int v) -> void {
		if (visited1[v]) {
			return;
		}
		dfs1(v);
	});
	std::cout << ')';
}

bool visited2[n] = {false}; // pseudo

void dfs2(int u) {
	visited2[u] = true;
	std::cout << '(' << u;
	traverse_outedges(u, [&](int v) -> void {
		if (visited2[v]) {
			return;
		}
		dfs2(v);
	}); // lambda expression is constructed for every vertex, so the efficiency is extremely low
	std::cout << ')';
}
int distance[n] = {0};

bool visited3[n] = {false};

void bfs(int u) {
	memset(visited3, false, sizeof(visited3));
	std::queue<int> Q;
	Q.push(u);
	visited3[u] = true;
	distance[u] = 0;
	while (!Q.empty()) {
		u = Q.front();
		Q.pop();
		traverse_outedges(u, [&](int v) -> void {
			if (visited3[v]) {
				return;
			}
			Q.push(v);
			visited3[v] = true;
			distance[v] = distance[u] + 1;
		}); // lambda expression is constructed for every vertex, so the efficiency is extremely low
	}
}

int main() {
#ifdef TMP__LINKED_ADJACENCY_LIST_H_
	memset(head, -1, sizeof(head));
#endif
#ifndef TMP__CHILD_SIBLING_H_
	for (int i = 0; i < n; i++) {
		add_edge(i, (i + 1) % n, 1);
		add_edge((i + 1) % n, i, 1);
	} // example map ring
#else
	for (int i = 0; i < n - 1; i++) {
		add_edge(i, i + 1, 1);
	} // example tree chain
#endif
	std::cout << "dfs1: ";
	dfs1(0);
	std::cout << std::endl;

	std::cout << "dfs2: ";
	dfs2(5);
	std::cout << std::endl;

	std::cout << "connectivity1: ";
	for (int v:visited1) {
		std::cout << v << ' ';
	}
	std::cout << std::endl;

	std::cout << "connectivity2: ";
	for (int v:visited2) {
		std::cout << v << ' ';
	}
	std::cout << std::endl;

	memset(distance, -1, sizeof(distance));
	bfs(0);
	std::cout << "distance: ";
	for (int i : distance) {
		std::cout << i << ' ';
	}
	std::cout << std::endl;
}
#else
int pre_order[n], in_order[n], post_order[n], pre_cnt = 0, in_cnt = 0, post_cnt = 0;

void traverse(int r) {
	pre_order[pre_cnt++] = r;
	if (~tree[r].c[0]) {
		traverse(tree[r].c[0]);
	}
	in_order[in_cnt++] = r;
	if (~tree[r].c[1]) {
		traverse(tree[r].c[1]);
	}
	post_order[post_cnt++] = r;
}

int main() {
	traverse(0);

	std::cout << "Pre-order sequence:";
	for (int p:pre_order) {
		std::cout << p << ' ';
	}
	std::cout << std::endl;

	std::cout << "In-order sequence:";
	for (int i:in_order) {
		std::cout << i << ' ';
	}
	std::cout << std::endl;

	std::cout << "Post-order sequence:";
	for (int p:post_order) {
		std::cout << p << ' ';
	}
	std::cout << std::endl;
}
#endif