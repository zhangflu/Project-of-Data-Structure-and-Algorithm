#include "addressList.hpp"
using namespace std;
int addressList::indexCounter(string aim){
    int len = aim.length();
    int count = 0;
    for(int i = 0; i < len; i++){
        count += int(aim[i]);
    }
    return count % HashModer;
}
addressList::addressList(student* std , int num){
    studentNum = num;
    for(int i = 0; i < num; i++){
        insertEle(std[i].name, std[i].sex, std[i].id, std[i].phone);
    }
}
void addressList::displayHashList(){
    for(int i = 0; i < HashModer; i++){
        cout << "(" << i << ") ";
        if(!hashList[i].empty()){
            vector <student> :: iterator it;
            for(it = hashList[i].begin(); it != hashList[i].end(); it++){
                cout << " <- " << (*it).name;
            }
        }
        cout << " <- NULL\n";
    }
}
void addressList::findEle(string aim){
    int listind = indexCounter(aim);
    if(hashList[listind].empty()){
        cout << "Can not find!\n";
        cout << "After comparing " << 0 << " times\n";
    }
    else{
        vector <student> :: iterator it;
        int compareNum = 0;
        for(it = hashList[listind].begin(); it != hashList[listind].end(); it++){
            compareNum++;
            if((*it).name == aim){
                cout << "Success:\n";
                cout << "After comparing " << compareNum << " times\n";
                cout << "name: " << (*it).name <<endl;
                cout << "sex: " << (*it).sex <<endl;
                cout << "id: " << (*it).id <<endl;
                cout << "phone: " << (*it).phone <<endl;
                return;
            }
        }
        cout << "Can not find!\n";
        cout << "After comparing " << compareNum << " times\n";
    }
}
void addressList::insertEle(string tn, string ts, string tid, string tp){
    int ind = indexCounter(tn);
    student t = student(tn, ts, tid, tp);
    hashList[ind].push_back(t);
    studentNum++;
}
void addressList::deleteEle(string aim){
    int listind = indexCounter(aim);
    if(hashList[listind].empty()){
        cout << "Can not find this element!\n";
    }
    else{
        vector <student> :: iterator it;
        int compareNum = 0;
        for(it = hashList[listind].begin(); it != hashList[listind].end(); it++){
            compareNum++;
            if((*it).name == aim){
                cout << "Success!\n";
                hashList[listind].erase(it);
                studentNum++;
                return;
            }
        }
        cout << "Can not find this element!\n";
    }
}
void showfunc(){
    cout << "*********************" << endl;
	cout << "*1.show all element *" << endl;
	cout << "*2.find an element  *" << endl;
	cout << "*3.insert an element*" << endl;
	cout << "*4.delete an element*" << endl;
	cout << "*5.exit the program *" << endl;
	cout << "*********************" << endl;
	cout << "Please insert your operation:\n";
}
string tgetString(){
    string aim;
    getline(cin, aim);
    int len = aim.length();
    for(int i = 0; i < len; i++){
        if(aim[i] == ' ')
        //cout << aim[i] <<endl;
        return "-1";
    }
    return aim;
}
string getString(){
    string temp = tgetString();
    while(temp == "-1"){
        cout << "Please don't input space!\n";
        temp = tgetString();
    }
    return temp;
}