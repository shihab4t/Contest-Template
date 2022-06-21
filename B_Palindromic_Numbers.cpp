#include <bits/stdc++.h>
using namespace std;

#define ed '\n'
#define gp ' '
#define i64 long long int
#define str string
#define vec vector
#define all(x) x.begin(), x.end()

bool solve()
{
    int n;
    cin >> n;
    str num;
    cin >> num;

    int first = num[0] - '0';
    int key = 9;

    if (first != 9)
    {
        for (int i = 0; i < n; i++)
        {
            cout << '9' - num[i];
        }
        cout << ed;
    }
    else
    {
        str ans = "";
        int cary = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            int ss = (num[i] - '0') + cary;
            if (ss > 1)
            {
                ans += ((11 - ss) + '0');
                cary = 1;
            }
            else
            {
                ans += ((1 - ss) + '0');
                cary = 0;
            }
        }
        reverse(all(ans));
        cout << ans << ed;
    }

    return true;
}

bool test()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return true;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    test();

    return 0;
}
// Shihab Mahamud (github.com/shihab4t)
