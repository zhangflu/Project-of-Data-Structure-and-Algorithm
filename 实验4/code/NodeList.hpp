#include <iostream>
#include <cstring>
using namespace std;
//��ʽ���ݽṹ
struct node{
	char data;
	node* next;
	node(char c, node* n){
		next = n;
		data = c;
	}
};
class NodeList{
public:
	NodeList(){
		head = NULL;
		length = 0;
	}
	~NodeList(){
		node* pos = head;
		while(pos!=NULL){
			node* temp = pos;
			pos = pos->next;
			delete temp;
		}
	}
	//����
	void Insert(char c ,int ind){
			if(ind>length || ind<0)
				return;
			if(length >= maxn)
				return;
			node** pos = &head;
			for(int i=0;i<ind;i++){
				pos = &((*pos)->next);
			}
			node* temp = (*pos);
			*pos = new node(c,temp);
			length++;
		}
	//�Ƴ�
		void Remove(int ind){
			if(ind>=length || ind<0)
				return;
			if(length >= maxn)
				return;
			node** pos = &head;
			for(int i=0;i<ind;i++){
				pos = &((*pos)->next);
			}
			node* temp = (*pos)->next;
			delete(*pos);
			*pos = temp;
			length--;
		}
		//�õ�ֵ
		char Get(int ind){
			if(ind>=length || ind<0)
				return 0;
			node* pos = head;
			for(int i=0;i<ind;i++){
				pos = pos->next;
			}
			return pos->data;
		}
		int Length(){
			return length;
		}
private:
	node * head;
	int length;
};
