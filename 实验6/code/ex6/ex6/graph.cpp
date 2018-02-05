#include "graph.hpp"
using namespace std;
const int inf = 100000;
graph::graph(int n)
{
	num = n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			adj_matrix[i][j] = 0;
		}
	}
}
bool operator < (const int_weight &a, const int_weight &b) {
	return a.no < b.no;
}
void graph::create_rem(int *f, int *t, int *w)
{
	int i = 0;
	while (f[i] != -1) {
		adj_matrix[f[i]][t[i]] = w[i];
		adj_form[f[i]].insert(int_weight(t[i], w[i]));
		i++;
	}
}

void graph::show_adj_matrix()
{
	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= num; j++) {
			cout << adj_matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void graph::show_adj_form()
{
	for (int i = 1; i <= num; i++) {
		cout << i << " : ";
		set <int_weight> ::iterator it;
		for (it = adj_form[i].begin(); it != adj_form[i].end(); it++) {
			cout << (*it).no << "(" << (*it).weight << ")" << " ";
		}
		cout << " ";
	}
}

void graph::dfs(int k, int n, int* r, int am[][maxn])
{
	if (r[k])
		return;
	r[k] = 1;
	cout << k << " ";
	for (int i = 1; i <= n; i++) {
		if (!r[i] && am[k][i]) {
			dfs(i, n, r, am);
		}
	}
}

void graph::DFS(int aim)
{
	int rem[maxn] = {};
	dfs(aim, num, rem, adj_matrix);
	cout << endl;
}

void graph::BFS(int aim)
{
	int rem[maxn] = {};
	queue <int> que;
	que.push(aim);
	int now = -1;
	rem[aim] = 1;
	while (!que.empty()) {
		now = que.front();
		que.pop();
		cout << now << " ";
		for (int i = 1; i <= num; i++) {
			if (!rem[i] && adj_matrix[now][i]) {
				que.push(i);
				rem[i] = 1;
			}
		}
	}
	cout << endl;
}
int pair_comp_func(pair <int, int> a, pair <int, int> b) {
	return a.second < b.second;
}
void graph::dijstra(int aim, int to){
	set <int> s;
	int dis[maxn] = {};
	for (int i = 1; i <= num; i++) {
		dis[i] = inf;
	}
	vector <int> road[maxn];
	road[aim].push_back(aim);
	dis[aim] = 0;
	int now = aim;
	while (s.size() < num) {
		for (int i = 1; i <= num; i++) {
			if (adj_matrix[now][i] && dis[now] + adj_matrix[now][i] < dis[i]) {
				dis[i] = adj_matrix[now][i] + dis[now];
				road[i] = road[now];
				road[i].push_back(i);
			}
		}
		s.insert(now);
		pair <int, int>  comper[maxn];
		for (int i = 0; i < num; i++) {
			comper[i].first = i + 1;
			comper[i].second = dis[i + 1];
		}
		sort(comper, comper + num, pair_comp_func);
		for (int i = 0; i < num; i++) {
			if (!s.count(comper[i].first)) {
				now = comper[i].first;
				break;
			}
		}
	}
	cout << "距离:" << dis[to] << endl;
	cout << "路径:" << endl;
	for (int i = 0; i < road[to].size(); i++) {
		if (i)
			cout << "->";
		cout << road[to][i];
	}
	cout << endl;
}
void showfunc() {
	cout << "*******************" << endl;
	cout << "*1.展示临接矩阵    *" << endl;
	cout << "*2.展示临接表      *" << endl;
	cout << "*3.进行深度优先搜索*" << endl;
	cout << "*4.进行宽度优先搜索*" << endl;
	cout << "*5.寻找最短路径    *" << endl;
	cout << "*6.退出           *" << endl;
	cout << "*******************" << endl;
	cout << "请输入指令\n";
}
int get_option() {
	cin.get();
	char taim[30];
	memset(taim, 0, sizeof(taim));
	cin.getline(taim, 30);
	if ((int)strlen(taim) == 0) {
		cout << "输入不合法\n";
		return -1;
	}
	for (int i = 0; i<(int)strlen(taim); i++)
		if (!isdigit(taim[i])) {
			cout << "输入不合法\n";
			return -1;
		}
	return atoi(taim);
}

