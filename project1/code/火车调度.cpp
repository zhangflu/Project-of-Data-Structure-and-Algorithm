#include <iostream>
#include <stack>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

int main() {
	const int maxn = 10000;
	int where[maxn];
	int now = 1, numOfStack = 0, step = 0;
	vector<stack<int>> buffer;
	set<int> emptyStack;
	memset(where, 0, sizeof(where));
	buffer.push_back(stack<int>());
	cout << "Please input the number of Orbit:" << endl;
	int n;
	cin >> n;
	cout << "Please input the index of Orbit in a line, separate them by space, from left to right:" << endl;
	for (int i = 1; i <= n; ++i) {
		int in;
		cin >> in;
		if (in == now) {	//入轨到出轨
			cout << "Train " << now << " : from Orbit to Derailment" << endl;
			++now;
			++step;
			while (where[now]) {
				int index = where[now];
				buffer[index].pop();
				if (buffer[index].empty())
					emptyStack.insert(index);
				else
				where[buffer[index].top()] = index;
				cout << "Train " << now << " : from Buffer " << index << " to Derailment" << endl;
				++now;
				++step;
			}
		}
		else {	//入栈
			bool flag = true;
			for (int j = in + 1; j <= n; ++j)	//寻找差最小的栈顶元素	
				if (where[j]) {
					int index = where[j];
					where[j] = 0;
					buffer[index].push(in);
					cout << "Train " << in << " : from Orbit to Buffer " << index << endl;
					where[in] = index;
					++step;
					flag = false;
					break;
				}
			if (flag) {
				if (!emptyStack.empty()) {	//判断用过的空栈
					int index = *(emptyStack.begin());
					emptyStack.erase(emptyStack.begin());
					buffer[index].push(in);
					cout << "Train " << in << " : from Orbit to Buffer " << index << endl;
					where[in] = index;
					++step;
				}
				else {	//新栈
					stack<int> create;
					create.push(in);
					buffer.push_back(create);
					cout << "Train " << in << " : from Orbit to Buffer " << ++numOfStack << endl;
					where[in] = numOfStack;
					++step;
				}
			}
		}
	}
	cout << endl << "Stacks Used: " << numOfStack << endl << "Total Steps: " << step << endl;
	system("pause");
	return 0;
}