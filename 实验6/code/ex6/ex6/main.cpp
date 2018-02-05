#include "graph.hpp"
using namespace std;
int main() {
	int num = 0;
	int f[maxn] = {};
	int t[maxn] = {};
	int w[maxn] = {};
	cout << "请输入节点的数目" << endl;
	cin >> num;
	graph g = graph(num);
	cout << "请输入边：\n（格式：“弧尾标号 弧头标号 边的权重”）" << endl;
	cout << "标号从1开始，用“-1 -1 -1”作为输入结尾" << endl;
	int tf, tt, tw;
	cin >> tf >> tt >> tw;
	int count = 0;
	while (tf != -1) {
		f[count] = tf;
		t[count] = tt;
		w[count] = tw;
		cin >> tf >> tt >> tw;
		count++;
	}
	f[count] = -1;
	g.create_rem(f, t, w);
	system("cls");
	showfunc();
	int op;
	cin >> op;
	system("cls");
	while (op != 6) {
		if (op == 1) {
			cout << "临接矩阵:\n";
			g.show_adj_matrix();
		}
		else if (op == 2) {
			cout << "临接表:\n";
			g.show_adj_form();
		}
		else if (op == 3) {
			cout << "请输入起始点:\n";
			int t;
			cin >> t;
			if (t > 0)
			g.DFS(t);
		}
		else if (op == 4) {
			cout << "请输入起始点:\n";
			int t;
			cin >> t;
			if(t > 0)
			g.BFS(t);
		}
		else if (op == 5) {
			cout << "请输入起始点:\n";
			int fr;
			cin >> fr;
			cout << "请输入目标点:\n";
			int to;
			cin >> to;
			if (fr > 0 && to > 0) {
				g.dijstra(fr, to);
			}
		}
		else {
			cout << "没有对应的操作\n";
			system("pause");
			system("cls");
		}
		cout << "\n操作结束\n";
		system("pause");
		system("cls");
		showfunc();
		cin >> op;
		system("cls");
	}
	cout << "谢谢！\n";
	system("pause");
	return 0;
}
/*
graph g = graph(5);
int f[] = {1,1,1,2,3,4,4,-1};
int t[] = {2,4,5,3,5,3,5,0};
int w[] = {10,30,100,50,10,20,60,0};
g.create_rem(f, t, w);
//g.dijstra(1, 5);
g.BFS(1);
g.DFS(1);
*/