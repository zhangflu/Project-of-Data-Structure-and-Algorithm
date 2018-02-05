#include <iostream>
#include <cstdlib>
#include "ArrList.hpp"
#include "NodeList.hpp"
using namespace std;
void state(){
	cout<<"Please input the operation you want:"<<endl;
	cout<<"1 insert; 2 remove; 3 get by index;4 quit"<<endl;
}
int main(){
	//说明
	cout<<"What kind of list do you want to test?"<<endl;
	cout<<"1 ArrList; 2 NodeList"<<endl;
	int op = 0;
	cin>>op;
	//各项操作的选择和执行
	if(op==1){
		ArrList t = ArrList();
		state();
		cin>>op;
		while(op!=0){
			if(op==1){
				cout<<"Please input the char you want to insert"<<endl;
				char c = 0;;
				cin>>c;
				cout<<"Please input the index"<<endl;
				int ind = 0;
				cin>>ind;
				t.Insert(c,ind);
			}
			else if(op==2){
				cout<<"Please input the index"<<endl;
				int ind = 0;
				cin>>ind;
				t.Remove(ind);
			}
			else if(op==3){
				cout<<"Please input the index"<<endl;
				int ind = 0;
				cin>>ind;
				char ans = t.Get(ind);
				if(ans == 0)
					cout<<"Invalid!"<<endl;
				else
					cout<<"The data here is "<<t.Get(ind)<<endl;
			}
			cout<<"done"<<endl;
			state();
			cin>>op;
		}
	}
	else if(op==2){
		NodeList t = NodeList();
		state();
		cin>>op;
		while(op!=0){
			if(op==1){
				cout<<"Please input the char you want to insert"<<endl;
				char c = 0;;
				cin>>c;
				cout<<"Please input the index"<<endl;
				int ind = 0;
				cin>>ind;
				t.Insert(c,ind);
			}
			else if(op==2){
				cout<<"Please input the index"<<endl;
				int ind = 0;
				cin>>ind;
				t.Remove(ind);
			}
			else if(op==3){
				cout<<"Please input the index"<<endl;
				int ind = 0;
				cin>>ind;
				char ans = t.Get(ind);
				if(ans == 0)
					cout<<"Invalid!"<<endl;
				else
					cout<<"The data here is "<<t.Get(ind)<<endl;
			}
			cout<<"done"<<endl;
			state();
			cin>>op;
		}
	}
	system("pause");
	return 0;
}
