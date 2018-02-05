#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;
struct node;
class tree{
public:
	tree();
	~tree();
	void insert(string in);
	void interchange();
	void display(int op);
	void clear();
	static void del(node* root);
	static void chag(node** root);
	static void pre(node* root);
	static void mid(node* root);
	static void bac(node* root);
private:
	node* root;
};
void showfunc();
string get_string();
double get_num();
int get_option();
#endif
