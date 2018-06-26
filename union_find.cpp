#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

class UnionFind{
private: vi arr, rank;
public:
	UnionFind(int n){
		rank.assign(n+1, 0);
		arr.assign(n+1, 0);
		for(int x=0; x<=n; x++) arr[x]=x;
	}
	int fRoot(int x){return (x==arr[x] ? x : arr[x]=fRoot(arr[x]));}
	void merge(int a, int b){
		int x=fRoot(a), y=fRoot(b);
		if(x!=y){
			if(rank[x]>rank[y]) arr[y]=x;
			else{
				arr[x]=y;
				if(rank[x]==rank[y]) rank[y]++;
			}
		}
	}
	void disp(){
		for(auto x:arr) cout<<x<<" "; cout<<endl;
		for(auto x:rank) cout<<x<<" "; cout<<endl;
	}
};

int main(){
	int n, m, i, j; cin>>n>>m;
	UnionFind uf(n);
	while(m--){
		cin>>i>>j;
		uf.merge(i, j);
	}
	uf.disp();
}