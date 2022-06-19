#include <bits/stdc++.h>
using namespace std;

#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cout << name << " = " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " = " << arg1 << " | ";
    __f(comma + 1, args...);
}


template <typename Tp>
void print(Tp arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << '\n';
}

template <typename Tp>
void print(stack<Tp> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << '\n';
}

template <class Tp, class Tp2>
void print(umap<Tp, Tp2> a)
{
    for (auto &i : a)
    {
        cout << i.first << " " << i.second << '\n';
    }
    cout << '\n';
}

template <typename Tp>
void print(Tp &a)
{
    for (auto &ith : a)
        cout << ith << " ";
    cout << '\n';
}
