#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string niz;
    string eksplozija;

    cin >> niz;
    cin >> eksplozija;

    string rezultat;

    int k = eksplozija.size();

    for(char c : niz)
    {
        rezultat.push_back(c);

        if(rezultat.size() >= k)
        {
            bool ista = true;

            for(int i = 0; i < k; i++)
            {
                if(rezultat[rezultat.size() - k + i] != eksplozija[i])
                {
                    ista = false;
                    break;
                }
            }

            if(ista)
            {
                for(int i = 0; i < k; i++)
                    rezultat.pop_back();
            }
        }
    }

    if(rezultat.empty())
        cout << "FRULA\n";
    else
        cout << rezultat << "\n";
}
