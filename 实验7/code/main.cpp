#include "addressList.hpp"
using namespace std;
int main(){
    ifstream in("data.txt", ios::in);
    //string name, sex, id, phone;
    student stuMsg[maxn];
    int stuNum = 0;
    while(in >> stuMsg[stuNum].name){
        in >> stuMsg[stuNum].sex >> stuMsg[stuNum].id >> stuMsg[stuNum].phone;
        stuNum++;
    }
    addressList a(stuMsg, stuNum);
    showfunc();
	string op;
	op = getString();
	system("cls");
    string temp;
	while (op != "5") {
		if (op == "1") {
			a.displayHashList();
		}
		else if (op == "2") {
			cout << "Please input the name you want to find: \n";
            a.findEle(getString());
		}
		else if (op == "3") {
            string tn, ts, tid, tp;
			cout << "Please input the name of element you want to insert: \n";
            tn = getString();
            cout << "Please input the sex of element you want to insert: \n";
            ts = getString();
            cout << "Please input the id of element you want to insert: \n";
            tid = getString();
            cout << "Please input the phone of element you want to insert: \n";
            tp = getString();
            a.insertEle(tn, ts, tid, tp);
		}
		else if (op == "4") {
			cout << "Please input the name of element you want to delete: \n";
            a.deleteEle(getString());
		}
		else {
			cout << "No such kind of operation!\n";
			system("pause");
			system("cls");
		}
		cout << "Operation has done\n";
		system("pause");
		system("cls");
		showfunc();
		op = getString();
		system("cls");
	}
	cout << "Thank you!\n";
	system("pause");
    return 0;
}