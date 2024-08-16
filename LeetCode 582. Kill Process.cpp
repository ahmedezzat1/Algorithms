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
const int dx[]{0, 1, 0, -1, -1, -1, 1, 1};
const int dy[]{1, 0, -1, 0, -1, 1, -1, 1};

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
vector<vector<int>> adj(N);
bool vis[N];
vector<int> ans;

void dfs(int node) {
    ans.push_back(node);
    vis[node] = true;
    for (int neg : adj[node])
        dfs(neg);

}

int main() {
    file();
    fast
    int t=1;
   // cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> pid(n), ppid(n);

        for (int i = 0; i < n; ++i) {
            cin >> pid[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> ppid[i];
        }

        for (int i = 0; i < n; ++i) {
            if (ppid[i] != 0)
                adj[ppid[i]].push_back(pid[i]);
        }

        int kill =0;
        cin>>kill;
        dfs(kill);
        output_vector(ans);
    }
}
