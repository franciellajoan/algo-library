#include <iostream>
#include <vector>
using namespace std;

//Cumulative Frequency Table

class FenwickTree{
private: vector<int> tree;
public:
	FenwickTree(int n){tree.assign(n+1, 0);}
	int rsq(int x){
		int sum=0;
		for(; x; x-=(x&(-x))) sum+=tree[x];
		return sum;
	}
	int rsq(int x, int y){return rsq(y)-(x==1 ? 0 : rsq(x-1));}
	void adjust(int i, int j){
		for(; i<(int)tree.size(); i+=(i&(-i))) tree[i]+=j;
	}
};

int main(){
	FenwickTree ft(10);
	//n is number of elements, m is number of queries
	int n, m, x, i, j; cin>>n>>m;
	while(n--){
		cin>>x; ft.adjust(x, 1);
	}
	while(m--){
		cin>>x>>i>>j;
		if(x==1) cout<<ft.rsq(i, j)<<endl;
		else ft.adjust(i, j);
	}
}