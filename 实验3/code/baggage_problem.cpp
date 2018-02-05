#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 10000;
int t = 0;
int n = 0;
int w[maxn] = {};
int p[maxn] = {};
bool used[maxn] = {};
set <vector <int> > all_ans;
void dfs(int pos,int tw){
	if(tw==t){
		vector <int> temp;
		for(int i=0;i<pos;i++){
			temp.push_back(p[i]);
		}
		sort(temp.begin(),temp.end());
		all_ans.insert(temp);
	}
	else{
		for(int i=pos;i<n;i++){
			if(used[i])
				break;
			p[pos] = w[i];
			used[i] = true;
			dfs(pos+1,tw+w[i]);
			used[i] = false;
		}
	}
}
int main(){
	cout<<"Please input the volumn of the baggage:";
	cin>>t;
	cout<<"Please input the num of items:";
	cin>>n;
	cout<<"Please input the volumn of the items:";
	for(int i=0;i<n;i++){
		cin>>w[i];
	}
	cout<<"All of the results:"<<endl;
	dfs(0,0);
	int count = 1;
	set <vector <int> > :: iterator it;
	for(it=all_ans.begin();it!=all_ans.end();it++){
		cout<<"Result"<<count++<<":{";
		int num = (*it).size();
		for(int i=0;i<num;i++){
			if(i!=0)
				cout<<",";
			cout<<(*it)[i];
		}
		cout<<"}"<<endl;
	}
	cout<<"The number of the results:"<<count-1<<endl;
	return 0;
}