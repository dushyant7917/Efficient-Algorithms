#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>b;x--)
#define pii pair<ll,ll>
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define inf 2e9
#define N 100001
#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)
#define SZ(s) ((ll)s.size())
#define MS(x,v) memset(x,v,sizeof(x))

const ll LIMIT=21;
ll n,l,t;
ll par[N][LIMIT];
ll in_tm[N], out_tm[N];
vector<ll> adj[N];

void init(){
    // use this in case of multiple test cases
    fr(i,0,n+1){
        adj[i].clear();
        in_tm[i]=out_tm[i]=0;
        fr(j,0,l+1) par[i][j]=-1;
    }
}

bool is_ancestor(ll u, ll v){
    // check if node 'v' is ancestor of node 'u'
    return in_tm[v]<=in_tm[u] and out_tm[v]>=out_tm[u];
}

void dfs(ll v,ll p){
    in_tm[v]=++t;
    
    par[v][0]=p;
    ll half_way_node;
    fr(i,1,l+1){
        // par[v][i] (lets call it 'x') will give us the node which
        // is 2^i levels above 'v'. 'x' must be 2^(i-1) levels above
        // some node (lets call it 'y') which is in half way between
        // 'v' and 'x' since 2^(i-1) + 2^(i-1) = 2^i. This half way
        // node 'y' is 2^(i-1) levels above node 'v'. So if we can
        // find half way node (which must be already computed by now),
        // we can use it to find par[v][i].
        half_way_node=par[v][i-1];
        par[v][i]=par[half_way_node][i-1];
    }


    ll u;
    fr(i,0,SZ(adj[v])){
        u=adj[v][i];
        if(u==p) continue;
        dfs(u, v);
    }

    out_tm[v]=++t;
}

ll lca(ll u, ll v){
    // lowest common ancestor in log(n) time
    if(is_ancestor(u,v)) return v;
    if(is_ancestor(v,u)) return u;
    rf(i,l,-1){
        if(!is_ancestor(v,par[u][i])){
            u=par[u][i];
        }
    }
    return par[u][0];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin>>t;

    ll m,x,y;
    while(t--){
        cin>>n>>m;
        l=ceil(log2(n));
        init();
        fr(i,0,m){
            cin>>x>>y;
            adj[x].PB(y);
            // adj[y].PB(x); un-comment this if edges are directed
        }
        dfs(1,1); // pass the root node
    }

    return 0;
}
