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
		//����
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
		//�Ƴ�
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
		//�õ�ֵ
		char Get(int ind){
			if(ind>=length || ind<0)
				return 0;
			return arr[ind];
		}
		int Length(){
			return length;
		}
	private:
		//�������ݽṹ
		char arr[maxn];
		int length;	
};
