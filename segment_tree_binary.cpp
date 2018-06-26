#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

//Range Sum Query

struct segtree{
    int l, r, val;
    segtree *Left, *Right;
    segtree(vi &arr, int i, int j):l(i), r(j){
        if(l==r){
            this->val=arr[l];
            this->Left=this->Right=nullptr;
        }
        else{
            int mid=(l+r)/2;
            this->Left = new segtree(arr, l, mid);
            this->Right = new segtree(arr, mid+1, r);
            this->val = this->Left->val + this->Right->val;
        }
    }
    void update(int i, int _val){
        if(l==i && r==i) this->val=_val;
        else if(i<l || i>r){ /*make tanga lol*/ }
        else{
            this->Left->update(i, _val);
            this->Right->update(i, _val);
            this->val=this->Left->val+this->Right->val;
        }
    }
    int sum(int i, int j){
        if(l>j || r<i) return 0;
        if(i<=l && r<=j) return val;
        return this->Left->sum(i, j)+this->Right->sum(i, j);
    }
    void disp(){
        if(this->Left!=nullptr) this->Left->disp();
        if(this->Right!=nullptr) this->Right->disp();
    }
};

int main(){
    int n, m, x, temp, k, i, j; cin>>n>>m;
    vi arr;
    for(x=0; x<n; x++){
        cin>>temp;
        arr.push_back(temp);
    }
    segtree *st=new segtree(arr, 0, n-1);
    st->disp();
    while(m--){
        cin>>k>>i>>j;
        if(k==1) cout<<st->sum(i-1, j-1)<<endl;
        else st->update(i-1, j);
    }
}