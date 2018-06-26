#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

#define F first
#define S second
typedef long long ll;
typedef pair<ll, ll> p;
typedef pair<ll, p> pp;
typedef vector<pp> vpp;

ll arr[3000+1];
ll ans=0;

//some comparison for the problem you solved
bool comp(pp a, pp b){
    if(a.F==b.F){
        return (a.F+a.S.F+a.S.S)<(b.F+b.S.F+b.S.S);
    }
    return a.F<b.F;
}

//oof, union find alert
ll fRoot(ll x){
    while(x!=arr[x]){
        arr[x]=arr[arr[x]];
        x=arr[x];
    }
    return x;
}

//ahaha walang by rank na union saddd
void check(ll a, ll b, ll w){
    if(fRoot(a)!=fRoot(b)){
        ans+=w;
        arr[fRoot(b)]=fRoot(a);
    }
}

int main(){
    ll n, e, x; cin>>n>>e;
    vpp stuff;
    pp temp;
    for(x=1; x<=n; x++) arr[x]=x;
    while(e--){
        cin>>temp.S.F>>temp.S.S>>temp.F;
        stuff.push_back(temp);
    }
    //set by ascending weights
    sort(stuff.begin(), stuff.end(), comp);
    for(auto x:stuff) check(x.S.F, x.S.S, x.F);
    cout<<ans;
}