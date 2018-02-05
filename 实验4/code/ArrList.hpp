#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 10000;
class ArrList{
	public:
		ArrList(){
			memset(arr,0,sizeof(arr));
			length = 0;
		}
		//插入
		void Insert(char c ,int ind){
			if(ind>length || ind<0)
				return;
			if(length >= maxn)
				return;
			for(int i=length-1;i>=ind;i--){
				arr[i+1] = arr[i];
			}
			arr[ind] = c;
			length++;
		}
		//移除
		void Remove(int ind){
			if(ind>=length || ind<0)
				return;
			if(length >= maxn)
				return;
			for(int i=ind;i<length;i++){
				arr[i] = arr[i+1];
			}
			length--;
		}
		//得到值
		char Get(int ind){
			if(ind>=length || ind<0)
				return 0;
			return arr[ind];
		}
		int Length(){
			return length;
		}
	private:
		//数组数据结构
		char arr[maxn];
		int length;	
};
