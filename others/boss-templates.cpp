/*
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template<class A1>void __f(const char*n,A1&&a1) {
cout<<n<<" = "<<a1<<'\n';}template<class A1,class
...As>void __f(const char*ns,A1&&a1, As&&...as) {
const char*comma=strchr(ns+1,','); cout.write(ns,
comma-ns)<<" = "<< a1<<" | ";__f(comma+1,as...);}
inline void first_io(){ios_base::sync_with_stdio(
false); cin.tie(NULL); } inline void  file_io() {
freopen (  "input.txt",  "r",  stdin);  freopen (
"output.txt","w",stdout);}vector<int>get_randoms(
int a, int f, int l){vector<int>t;srand(time(0));
for(int i=0;i<a;i++)t.push_back(f+((rand()%(l-f+1
))));return t;}template<typename Tp>void print(Tp
arr[],int n) {for(int i=0;i<n;i++)cout<<arr[i] <<
" ";cout<<'\n';}template<typename Tp> void print(
const Tp&a){for(const auto &ith:a)cout<<ith<<" ";
cout <<'\n';} template <class Tp, class Tp2> void
print(umap<Tp,Tp2> a){ for(auto &i : a) { cout <<
i.first << " " << i.second << '\n';}cout <<'\n';}
*/


#include <bits/stdc++.h>
using namespace std;
/// Typedef
typedef long long           LL;
typedef vector<int>         vi;
typedef pair<int,int>       pii;

#define pb                  push_back
#define ppb                 pop_back
#define MP                  make_pair
#define ff                  first
#define ss                  second
#define sf                  scanf
#define pf                  printf
#define SQR(x)              ((x)*(x))
#define loop(i, y)          for(int i=0; i<int(y); i++)
#define FOR(i, x, y)        for(int i=int(x); i<=int(y); i++)
#define ROF(i, x, y)        for(int i=int(x); i>=int(y); i--)
#define all(c)              c.begin(), c.end()
#define sz(c)               int(c.size())
#define clr(x, y)           memset(x, y, sizeof(x))
#define si(x)               scanf("%d", &x)
#define sii(x, y)           scanf("%d %d", &x, &y)
#define siii(x, y, z)       scanf("%d %d %d", &x, &y, &z)
#define sl(x)               scanf("%lld", &x)
#define sll(x, y)           scanf("%lld %lld", &x, &y)
#define slll(x, y, z)       scanf("%lld %lld %lld", &x, &y, &z)

#ifdef VAMP
     #define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template < typename Arg1 >
    void __f(const char* name, Arg1&& arg1){
        cout << name << " = " << arg1 << std::endl;
    }
    template < typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names+1, ',');
        cout.write(names, comma - names) << " = " << arg1 <<" | ";
        __f(comma+1, args...);
    }
#else
    #define debug(...)
#endif
///******************************************START******************************************

// mt19937_64                  rng(chrono::steady_clock::now().time_since_epoch().count());
// #define new_ran(a, b)       uniform_int_distribution<LL> (a, b)(rng)
// #define ran_shuffle(x)      shuffle(x.begin(), x.end(), rng)
template <class T, class L> inline T bigMod(T p,T e,L M){ LL ret = 1%M; for(; e > 0; e >>= 1){ if(e & 1) ret = (ret * p) % M; p = ((LL)p * p) % M; } return (L) ret;}

/// Constants
#define MAX                 5003
#define MOD                 1000000007
#define eps                 1e-9
#define INF                 0x3f3f3f3f3f3f3f3f // 4,557,430,888,798,830,399
#define inf                 0x3f3f3f3f // 1,061,109,567
#define PI                  acos(-1.0)  // 3.1415926535897932
#define VT                  int

char s1[MAX], s2[MAX];
int nxt1[MAX][26], nxt2[MAX][26];
int DP[MAX][MAX];
int n, m;

int solve(int pos1, int pos2){
    int &ret = DP[pos1][pos2];
    if(~ret) return ret;
    ret = 0;
    FOR(i, 0, 25){
        int nx1 = nxt1[pos1+1][i];
        int nx2 = nxt2[pos2+1][i];

        if(nx1>0 and nx2>0){
            // debug(i, pos1, pos2, nx1, nx2);
            ret = max(ret, solve(nx1, nx2) + 4 - (nx1 - pos1) - (nx2 - pos2));
        }
    }
    return ret;
}

int main(){
    #ifdef VAMP
        clock_t tStart = clock();
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    clr(DP, -1);
    sii(n, m);
    sf("%s %s", s1, s2);

    FOR(i, 0, 25) nxt1[n][i] = -1, nxt2[m][i] = -1;
    ROF(i, n-1, 0){
        FOR(j, 0, 25) nxt1[i][j] = nxt1[i+1][j];
        nxt1[i][s1[i]-'a'] = i;
    }
    ROF(i, m-1, 0){
        FOR(j, 0, 25) nxt2[i][j] = nxt2[i+1][j];
        nxt2[i][s2[i]-'a'] = i;
    }

    int res = 0;
    FOR(i, 0, n-1) FOR(j, 0, m-1){
        if(s1[i] == s2[j]){
            auto now = 2 + solve(i, j);
            // debug(i, j, now);
            res = max(res, now);
        }
    }
    printf("%d\n", res);

    #ifdef VAMP
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif
    return 0;
}