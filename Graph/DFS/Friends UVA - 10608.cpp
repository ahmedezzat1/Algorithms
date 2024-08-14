#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'
#define Endl '\n'
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define allof(x) x,x+(sizeof(x)/sizeof(x[0]))
#define loop(n)          for(int i = 0; i < (n); i++)
#define fast    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
double PI = 3.14159265359;
// bitwise functions ************************
#define pop_cnt(x) (__builtin_popcountll(x)) //num of ones int bits
#define LSB(x) (__builtin_ffsll(x) - 1)  \
        // int lowbit(int x){return x&(-x);}

#define MSB(x) (64 - __builtin_clzll(x) - 1)

//******************************************

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}

void file() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

#endif
}

#ifndef ONLINE_JUDGE


#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif


/**************** Solution start from here ***********************/
const int N = 30000+5;
int nodes, edges;
vector<vector<int>> adj(N);
vector<int> vis(N);
int cnt = 0;

void dfs(int node) {
    vis[node] = true;
    for (int neg  : adj[node]) {
        if (!vis[neg])
            dfs(neg);
    }
    cnt++;
}

void initial() {
    for (int i = 0; i < N; ++i) {
        adj[i].clear();
        vis[i] = 0;
    }
}

int main() {
    file();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> nodes >> edges;

        initial();

        vis.resize(nodes+1);
        adj.resize(nodes+1);
        for (int i = 0; i < edges; ++i) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int ans = 0;
        for (int i = 1; i <= nodes; ++i) {
            if (!vis[i]) {
                cnt=0;
                dfs(i);
                ans = max(ans, cnt);

            }
        }

        cout << ans<<endl;
    }
}
