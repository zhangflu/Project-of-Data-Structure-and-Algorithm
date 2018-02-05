#pragma once
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <cstdlib>
using namespace std;
const int maxn = 100;
struct int_weight {
	int no;
	int weight;
	int_weight(int n, int w) {
		no = n;
		weight = w;
	}
};
class graph {
private:
	int num;
	int adj_matrix[maxn][maxn];
	set <int_weight> adj_form[maxn];
public:
	graph(int n);
	void create_rem(int* , int* , int* );
	void show_adj_form();
	void show_adj_matrix();
	static void dfs(int, int, int*, int m[][maxn]);
	void DFS(int);
	void BFS(int);
	void dijstra(int, int);
};
void showfunc();
int get_option();