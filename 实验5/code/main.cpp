#include "binaryTree.hpp"
using namespace std;
int main(){
	tree t;
	showfunc();
	int op = get_option();
	system("cls");
	while(op != 7){
		if(op == 1){
			cout<<"��������ַ������Ƚ�Ϊ�ַ����Ƚ�\n���뷽��Ϊ�Ƚڵ�����С�����Ѱ�ң��������ұ�Ѱ�ң�ֱ���ҵ���ָ��\n";
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
			cout << "======���벻�Ϸ�======\n";
			system("pause");
			system("cls");
			continue;
		}
		cout<<"�����ɹ�\n";
		system("pause");
		system("cls");
		showfunc();
		op = get_option();
		system("cls");
	}
	cout<<"лл��\n"; 
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
