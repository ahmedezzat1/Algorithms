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
const int N = 1e5 + 5;
int nodes, edges;
bool vis[N];
vector<vector<int>> adj(N);

void dfs(int node, int parent) {
    vis[node] = true;
    for (int neg : adj[node]) {
        if (neg == parent)
            continue;
        if (vis[neg]) {
            NO;
            exit(0);
        }
        dfs(neg, node);
    }
}
//////////main//////////

int main() {
    file();
    fast
    int tc = 1;
    //cin >> tc;
    while (tc--) {
        cin >> nodes >> edges;
        for (int i = 0; i < edges; ++i) {
            int from, to;
            cin >> from >> to;
            adj[from].push_back(to);
            adj[to].push_back(from);
        }

        dfs(1 , -1);
        bool onecomponent = true;
        for (int i = 1; i <= nodes; ++i) {
            if (vis[i] == false)
                onecomponent = false;
        }

        if (onecomponent and edges == nodes - 1)
            YES;
        else
            NO;


    }
}
