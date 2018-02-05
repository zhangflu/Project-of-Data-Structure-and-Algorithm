#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 10000;
class Queue{
	char arr[maxn];
	int head;
	int tail;
	public:
		Queue(){
			head = 0;
			tail = 0;
			memset(arr,0,sizeof(arr));
		}
		void Push(char c){
			if(head-tail == 1 || head == 0 && tail == maxn-1)
				return;
			arr[tail] = c;
			tail++;
			if(tail>=maxn)
				tail = 0;
		}
		void Pop(){
			if(head == tail)
				return;
			head++;
			if(head>=maxn)
				head = 0;
		}
		char Front(){
			if(head == tail)
				return 0;
			return arr[head];
		} 
		char Back(){
			if(head == tail)
				return 0;
			//cout<<tail<<endl;
			int ttail = tail-1;
			if(ttail >= 0)
				return arr[ttail];
			return arr[maxn-1];
		} 
};
