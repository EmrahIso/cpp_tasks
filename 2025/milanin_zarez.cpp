#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll broj_rijeci;

    cin >> broj_rijeci;

    vector<string> tekst;

    for(int i = 1; i <= broj_rijeci; i++) {
        string rijec;

        cin >> rijec;

        tekst.push_back(rijec);
    }

    string komanda;

    cin >> komanda;

    if(komanda == "ODUZETI") {
        for(int i = 2; i < tekst.size(); i++) {
            if(tekst[i] == "i" || tekst[i] == "ili") {
                ll duzina_rijeci_1 = tekst[i-1].size();
                ll duzina_rijeci_2 = tekst[i-2].size();

                if(tekst[i - 1][duzina_rijeci_1 - 1] == ',' && tekst[i - 2][duzina_rijeci_2 - 1] == ',') {
                    tekst[i - 1].pop_back();
                }
            }
        }
    } else if (komanda == "DODATI") {
        // kod ovdje
        for(int i = 2; i < tekst.size(); i++) {
            if(tekst[i] == "i" || tekst[i] == "ili") {
                ll duzina_rijeci_1 = tekst[i-1].size();
                ll duzina_rijeci_2 = tekst[i-2].size();

                if(tekst[i - 1][duzina_rijeci_1 - 1] != ',' && tekst[i - 2][duzina_rijeci_2 - 1] == ',') {
                    tekst[i - 1].push_back(',');
                }
            }
        }
    }

    for(int i = 0; i < tekst.size(); i++) {
        cout << tekst[i] << " ";
    }

    cout << "\n";

    return 0;
}
