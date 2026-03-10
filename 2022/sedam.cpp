#include <bits\stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string N;
    cin >> N;

    int mod = 0;

    for(char c: N) {
        mod = (mod * 10 + (c - '0')) % 7;
    }

    if(mod == 0) mod = 7;

    cout << mod;

    return 0;
}
