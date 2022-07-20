#include <bits/stdc++.h>
using namespace std;

template <typename T>
istream &operator>>(istream &istream, vector<T> &v)
{
    int len = v.size();
    for (int i = 0; i < len; i++)
        cin >> v[i];
    return istream;
}
template <typename T>
ostream &operator<<(ostream &ostream, const set<T> &s)
{
    for (auto ith : s)
        cout << ith << " ";
    return ostream;
}
template <typename T>
ostream &operator<<(ostream &ostream, const vector<T> &v)
{
    for (auto ith : v)
        cout << ith << " ";
    return ostream;
}
template <typename T, typename T2>
ostream &operator<<(ostream &ostream, const pair<T, T2> &p)
{
    return (ostream << p.first << " " << p.second);
}
template <typename T, typename T2>
ostream &operator<<(ostream &ostream, const map<T, T2> &mp)
{
    for (auto ith : mp)
        cout << ith << "\n";
    return ostream;
}

#define ed '\n'
#define gp ' '
#define lli long long int
#define vec vector
#define str string
#define all(x) x.begin(), x.end()

bool solve()
{

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int t;
    // cin >> t;
    // while (t--)
    // {
    //     solve();
    // }

    // solve();

    return 0;
}
// github.com/shihab4t (Shihab Mahamud)
// 