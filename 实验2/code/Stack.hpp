#include <iostream>
using namespace std;
struct node{
	char data;
	node* next;
	node(char d,node* n = NULL){
		data = d;
		next = n;
	}
};
class Stack{
	node* top;
	public:
		Stack(){
			top = NULL;
		}
		~Stack(){
			while(top!=NULL){
				node* temp =(*top).next;
				delete top;
				top = temp;
			}
		}
		void Push(char c){
			if(top == NULL){
				top = new node(c);
			}
			else{
				top = new node(c,top);
			}
		}
		void Pop(){
			if(top == NULL){
				return;
			}
			node* temp =(*top).next;
			delete top;
			top = temp;
		}
		char Top(){
			if(top == NULL)
				return 0;
			else
				return (*top).data;
		}
};
