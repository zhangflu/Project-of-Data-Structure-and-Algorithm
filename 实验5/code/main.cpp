#include "binaryTree.hpp"
using namespace std;
int main(){
	tree t;
	showfunc();
	int op = get_option();
	system("cls");
	while(op != 7){
		if(op == 1){
			cout<<"输入的是字符串，比较为字符串比较\n插入方法为比节点数据小向左边寻找，否则向右边寻找，直到找到空指针\n";
			string input = get_string();
			if(input != "")
				t.insert(input);
		}
		else if(op == 2){
			t.interchange();
		}
		else if(op >= 3 && op <= 5){
			t.display(op - 3);
			cout<<endl;
		}
		else if(op == 6){
			t.clear();
		}
		else{
			cout << "======输入不合法======\n";
			system("pause");
			system("cls");
			continue;
		}
		cout<<"操作成功\n";
		system("pause");
		system("cls");
		showfunc();
		op = get_option();
		system("cls");
	}
	cout<<"谢谢！\n"; 
	system("pause");
	return 0;
}
//	t.insert("3");
//	t.insert("1");
//	t.insert("5");
//	t.insert("6");
//	t.insert("4");
//	t.interchange();
//	t.display(1);
//	t.clear();
//	t.display(1);
