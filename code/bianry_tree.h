//
// Created by Pioooooo on 2020/11/12.
//

#ifndef TMP__BIANRY_TREE_H_
#define TMP__BIANRY_TREE_H_
#define TREE

const int n = 10;

struct Node {
	int c[2], w;
} tree[n] = {
	{{1, 2}, 1},	//		  0			|
	{{3, -1}, 1},	//		 / \		|
	{{6, 9}, 1},	//		1	2		|
	{{4, 5}, 1},   //	   /   / \		|
	{{-1, -1}, 1}, //	  3	  6	  9		|
	{{-1, -1}, 1}, //	 / \   \		|
	{{-1, 7}, 1},  //	4   5	7		|
	{{-1, 8}, 1},	//			 \		|
	{{-1, -1}, 1}, //			  8		|
	{{-1, -1}, 1}  //					|
};

#endif //TMP__BIANRY_TREE_H_
