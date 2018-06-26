#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

//Range Minimum Query

class SegmentTree{
private:
	vi tree, arr; //the segtree and array, respectively
	int n, i, j, k; //size
	int left(int x){return x<<1;}		//for the indices
	int right(int x){return (x<<1)+1;}	//of the tree
	//build the tree
	void build(int x, int l, int r){
		if(l==r) tree[x]=l;
		else{
			build(left(x), l, (l+r)/2);	//build left portion
			build(right(x), ((l+r)/2)+1, r);	//build right portion
			int x1=tree[left(x)], x2=tree[right(x)];
			tree[x]=(arr[x1]>arr[x2] ? x2 : x1);
		}
	}
	//for the queries wahu
	int query(int x, int l, int r){
		//i and j are the ranges, l and r are the tree's current segment
		if(i>r || j<l) return -1;	//outside query range
		if(l>=i && r<=j) return tree[x]; //already inside query range
		int x1=query(left(x), l, (l+r)/2);	//look, somewhat same as above!
		int x2=query(right(x), ((l+r)/2)+1, r);	//this too
		if(x1==-1) return x2;	//if segment is outside query range
		if(x2==-1) return x1;	//same as above
		return (arr[x1]>arr[x2] ? x2 : x1);
	}
	//for updates!
	void update(int x, int l, int r){
		if(k>r || k<l) return;
		if(l==r) tree[x]=l;
		else{
			update(left(x), l, (l+r)/2);
			update(right(x), ((l+r)/2)+1, r);
			int x1=tree[left(x)], x2=tree[right(x)];
			tree[x]=(arr[x1]>arr[x2] ? x2 : x1);
		}
	}

public:
	SegmentTree(const vi &_arr){
		arr=_arr; n=(int)arr.size(); //create copy of the array
		tree.assign(4*n, 0); //large enough size for the tree
		build(1, 0, n-1); //build!
	}
	int query(int _i, int _j){
		i=_i, j=_j;	//i just made a global variable to make it easier
		return query(1, 0, n-1); //oof overloading from above
	}
	void update(int _k, int val){
		k=_k, arr[k]=val;
		update(1, 0, n-1);
	}
};

int main(){
	int n, m, i, j, temp, choice; cin>>n>>m;
	vi arr;
	while(n--){
		cin>>temp;
		arr.push_back(temp);
	}
	SegmentTree tree(arr);
	while(m--){
		cin>>choice>>i>>j;
		if(choice==1){
			cout<<tree.query(i-1, j-1)<<endl;
			//displays index on the basis of 0-based indexing
		}
		else tree.update(i-1, j);
	}
	return 0;
}