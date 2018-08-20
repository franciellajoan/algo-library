#include <iostream>
#define ll long long
using namespace std;

ll arr[100001];

class segtree{
private:
    int l, r;
    ll sum, lazy;
    segtree *Left, *Right;
    void prop(){
        if(lazy==0) return;
        sum+=((r-l)+1)*lazy;
        if(l!=r) Left->lazy=lazy, Right->lazy=lazy;
        lazy=0;
    }

public:
    segtree(int i, int j):l(i), r(j), lazy(0){
        if(l==r){
            sum=arr[l];
            Left=Right=nullptr;
        }
        else{
            int mid=(l+r)/2;
            Left=new segtree(i, mid);
            Right=new segtree(mid+1, j);
            sum=Left->sum+Right->sum;
        }
    }
    void update(int i, int j, ll val){
        prop();
        if(i<=l && r<=j){
            lazy+=val;
            prop();
            return;
        }
        if(r<i || j<l) return;
        Left->update(i, j, val);
        Right->update(i, j, val);
        sum=Left->sum+Right->sum;
    }
    ll getSum(int i, int j){
        prop();
        if(i<=l && r<=j) return sum;
        if(r<i || j<l) return 0;
        return Left->getSum(i, j)+Right->getSum(i, j);
    }
};

int main(){
    int n, q, a, b, c, x; cin>>n;
    ll val;
    for(x=0; x<n; x++) cin>>arr[x];
    segtree *st=new segtree(0, n-1);
    cin>>q;
    while(q--){
        cin>>a;
        if(a==1){
            cin>>b>>c>>val;
            st->update(b, c, val);
        }
        else{
            cin>>b>>c;
            cout<<st->getSum(b, c)<<endl;
        }
    }
}