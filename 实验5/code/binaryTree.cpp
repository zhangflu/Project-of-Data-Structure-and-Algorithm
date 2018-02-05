#include "binaryTree.hpp"
using namespace std;
const int MAXN = 30;
struct node{
	string data;
	node* left;
	node* right;
	node(string d, node* l = NULL, node* r = NULL){
		left = l;
		right = r;
		data = d;
	}
};
tree::tree(){
	root = NULL;
}
void tree::del(node* root){
	if(root != NULL){
		del(root->left);
		del(root->right);
		delete(root);
	}
}
tree::~tree(){
	del(root);
}
void tree::clear(){
	del(root);
	root = NULL;
}
void tree::insert(string in){
	node** now;
	now = &root;
	while(*now != NULL){
		if(in < (*now)->data){
			now = &((*now)->left);
		}
		else{
			now = &((*now)->right);
		}
	}
	*now = new node(in);
}
void tree::chag(node** root){
	if(*root != NULL){
		chag(&((*root)->left));
		chag(&((*root)->right));
		node* temp;
		temp = (*root)->right;
		(*root)->right = (*root)->left;
		(*root)->left = temp;
	}
}
void tree::interchange(){
	chag(&root);
}
void tree::pre(node* root){
	if(root != NULL){
		cout<<root->data;
		pre(root->left);
		pre(root->right);
	}
}
void tree::mid(node* root){
	if(root != NULL){
		mid(root->left);
		cout<<root->data;
		mid(root->right);
	}
}
void tree::bac(node* root){
	if(root != NULL){
		bac(root->left);
		bac(root->right);
		cout<<root->data;
	}
}
void tree::display(int op){
	if(root == NULL){
		cout<<"NULL";
	}
	if(op == 0){
		pre(root);
	}
	else if(op == 1){
		mid(root);
	}
	else if(op == 2){
		bac(root);
	}
}
void showfunc(){
	cout<<"���ܣ�\n";
	cout<<"1.����\n";
	cout<<"2.��ת\n";
	cout<<"3.ǰ�����\n";
	cout<<"4.�������\n";
	cout<<"5.�������\n";
	cout<<"6.�����\n";
	cout<<"7.�˳�\n";
	cout<<"������ָ�";
}

string get_string() {
	char taim[MAXN];
	memset(taim, 0, sizeof(taim));
	string aim;
	cin.getline(taim, MAXN);
	aim = taim;
	if (aim.size() > MAXN) {
		cout << "======���ȹ���======\n";
		return "";
	}
	if (aim.size() == 0) {
		cout << "======���벻��Ϊ��======\n";
		return "";
	}
	int len = aim.size();
	for (int i = 0; i < len; i++) {
		if (aim[i] == ' ') {
			cout << "======�����пո�======\n";
			return "";
		}
	}
	return aim;
}

double get_num() {
	char taim[MAXN];
	memset(taim, 0, sizeof(taim));
	string aim;
	cin.getline(taim, 30);
	aim = taim;
	if (aim.size() > 9) {
		cout << "======���ȹ���======";
		return -1;
	}
	int len = aim.size();
	for (int i = 0; i <len; i++) {
		if (!isdigit(aim[i]) && aim[i] != '.') {
			cout << "======����Ϊ����======\n";
			return -1;
		}
	}
	double res = atof(taim);
	return res;
}
int get_option() {
	char taim[MAXN];
	memset(taim, 0, sizeof(taim));
	cin.getline(taim, 30);
	if ((int)strlen(taim) == 0) {
		cout << "======���벻�Ϸ�======\n";
		return -1;
	}
	for(int i=0;i<(int)strlen(taim);i++)
	if (!isdigit(taim[i])) {
		cout << "======���벻�Ϸ�======\n";
		return -1;
	}
	return atoi(taim);
}

