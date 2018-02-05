#include "Stack.hpp"
#include "Queue.hpp"
#include <cstdlib>
using namespace std;
int main(){
	int op =-1;
	cout<<"Please choose the structure you want to test:"<<endl;
	cout<<"0: stack  1: queue"<<endl;
	cin>>op;
	system("cls");
	if(op == 0){
		Stack s;
		op = -1;
		do{
			if(op == 1){
				cout<<"Please input a char:"<<endl;
				char c;
				cin>>c;
				s.Push(c);
				cout<<"Done"<<endl;
			}
			else if(op == 2){
				cout<<"Done"<<endl;
				s.Pop();
			}
			else if(op == 3){
				char c = s.Top();
				if(c == 0){
					cout<<"Stack is empty!"<<endl;
				}
				else{
					cout<<"The top char is:"<<c<<endl;
				}
			}
			if(op!=-1)
				system("pause");
			system("cls");
			cout<<"Please choose your operation:"<<endl;
			cout<<"0: exit  1: push a char  2:pop a char  3: get the top"<<endl;
			cin>>op;
		}
		while(op!=0);
	}
	else{
		Queue q;
		op = -1;
		do{
			if(op == 1){
				cout<<"Please input a char:"<<endl;
				char c;
				cin>>c;
				q.Push(c);
				cout<<"Done"<<endl;
			}
			else if(op == 2){
				cout<<"Done"<<endl;
				q.Pop();
			}
			else if(op == 3){
				char c = q.Front();
				if(c == 0){
					cout<<"Queue is empty!"<<endl;
				}
				else{
					cout<<"The front char is:"<<c<<endl;
				}
			}
			else if(op == 4){
				char c = q.Back();
				if(c == 0){
					cout<<"Queue is empty!"<<endl;
				}
				else{
					cout<<"The back char is:"<<c<<endl;
				}
			}
			if(op!=-1)
				system("pause");
			system("cls");
			cout<<"Please choose your operation:"<<endl;
			cout<<"0: exit  1: push a char  2:pop a char  3: get the front  4: get the back"<<endl;
			cin>>op;
		}
		while(op!=0);
	}
	system("cls");
	cout<<"Thank you!\n";
	return 0;
}

