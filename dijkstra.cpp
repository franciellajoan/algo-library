#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#define endl '\n'
#define INF 1000000000
#define F first
#define S second
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
vii adj[1000];

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int V, E, x, u, v, w, S; cin>>V>>E>>S;
	for(x=0; x<E; x++){
		cin>>u>>v>>w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	//setting starting distance
	vector<int> dist(V+1, INF); dist[S]=0;
	//arranging weights in ascending order
	priority_queue<ii, vii, greater<ii> > pq; pq.push({0, S});
	while(!pq.empty()){
		int u=pq.top().S, d=pq.top().F; pq.pop();
		//if the weight is greater than the recorded distance
		if(d>dist[u]) continue;
		for(auto cur:adj[u]){
			//if current distance is greater than u's recorded distance
			//plus the current weight
			if(dist[cur.F]>dist[u]+cur.S){
				dist[cur.F]=dist[u]+cur.S;
				pq.push({dist[cur.F], cur.F});
			}
		}
	}
	for(auto x:dist) cout<<x<<endl;
}