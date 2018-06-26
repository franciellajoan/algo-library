#include <iostream>
#include <vector>
#include <queue>
#define F first
#define S second
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<int> vis;
vii adj[3001];
//ordering weights in ascending order
priority_queue<ii, vii, greater<ii> > pq;


//gets all unvisited nodes of v and adding them to the pq
void prims(int v){
    vis[v]=1;
    for(int x=0; x<(int)adj[v].size(); x++){
        ii e=adj[v][x];
        if(!vis[e.S]) pq.push({e.F, e.S});
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, u, v, w, s, ans=0; cin>>n>>m;
    while(m--){
        cin>>u>>v>>w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    cin>>s;
    vis.assign(n, 0);
    prims(s);
    while(!pq.empty()){
        ii e=pq.top(); pq.pop();
        //greedy thing that gets the minimum edge and adds to the tree
        if(!vis[e.S]){
            ans+=e.F, prims(e.S);
            cout<<e.S<<" "<<e.F<<" "<<ans<<endl;
        }
    }
    cout<<ans;
}