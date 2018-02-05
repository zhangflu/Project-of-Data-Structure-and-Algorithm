#ifndef ADDRESSLIST_HPP
#define ADDRESSLIST_HPP
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;
const int maxn = 105;
const int HashModer = 10;
struct student{
    string name, sex, id, phone;
    student(string tn, string ts, string tid, string tp){
        name = tn;
        sex = ts;
        id = tid;
        phone = tp;
    }
    student(){
        name = "";
        sex = "";
        id = "";
        phone = "";
    }
};
class addressList{
    private:
    int studentNum;
    vector <student> hashList[HashModer];
    int indexCounter(string);
    public:
    addressList(student*, int);
    void displayHashList();
    void findEle(string);
    void insertEle(string, string, string, string);
    void deleteEle(string);
};
void showfunc();
string getString();
#endif