#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

vector<ll> v, q1, q2;

void merge(ll s1s, ll s1e, ll s2s, ll s2e){
	ll x, i1=0, i2=0;
	//clear array from previous stuff
	q1.clear(); q2.clear();
	for(x=s1s; x<=s1e; x++) q1.push_back(v[x]);
	for(x=s2s; x<=s2e; x++) q2.push_back(v[x]);
	x=s1s;
	//using vectors instead of queues because they're too slow
	while(i1<q1.size() && i2<q2.size()){
		if(q1[i1]<=q2[i2]){
			v[x]=q1[i1];
			i1++;
		}
		else{
			v[x]=q2[i2];
			i2++;
		}
		x++;
	}
	while(i1<q1.size()){
		v[x]=q1[i1];
		i1++;
		x++;
	}
	while(i2<q2.size()){
		v[x]=q2[i2];
		i2++;
		x++;
	}
}

void sort(ll l, ll r){
	if(l==r) return;
	ll m=(l+r)/2;
	//divide & conquer
	sort(l, m);
	sort(m+1, r);
	//combine
	merge(l, m, m+1, r);
}

int main(){
	ll n, x, y, temp; cin>>n;
	for(x=0; x<n; x++){
		cin>>temp;
		v.push_back(temp);
	}
	sort(0, n-1);
	for(auto x:v) cout<<x<<" ";
}