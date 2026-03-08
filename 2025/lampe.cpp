#include <bits/stdc++.h>   // uključuje sve standardne C++ biblioteke
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // broj sijalica u nizu
    ll brojSijalica;
    cin >> brojSijalica;

    // željeni raspored sijalica (0 = ugašena, 1 = upaljena)
    vector<ll> zeljeniRaspored;

    for (int i = 0; i < brojSijalica; i++) {
        ll stanjeSijalice;
        cin >> stanjeSijalice;

        zeljeniRaspored.push_back(stanjeSijalice);
    }

    // minimalno vrijeme potrebno da dobijemo željeni raspored
    ll minimalnoVrijeme = brojSijalica;

    // broj sijalica koje trebaju biti upaljene
    ll brojUpaljenih = 0;

    for (int i = 0; i < brojSijalica; i++) {
        if (zeljeniRaspored[i] == 1) {
            brojUpaljenih++;
        }
    }

    // ako palimo svaku sijalicu posebno
    minimalnoVrijeme = brojUpaljenih;

    // probavamo sve prefiks intervale
    for (int desniKraj = 0; desniKraj < brojSijalica; desniKraj++) {

        vector<ll> trenutnoStanje;

        // početno stanje: sve ugašene
        for (int i = 0; i < brojSijalica; i++) {
            trenutnoStanje.push_back(0);
        }

        // upalimo interval [0, desniKraj]
        for (int i = 0; i <= desniKraj; i++) {
            trenutnoStanje[i] = 1;
        }

        ll trenutnoVrijeme = 0;

        // brojimo koliko se stanje razlikuje od željenog
        for (int i = 0; i < brojSijalica; i++) {
            if (trenutnoStanje[i] != zeljeniRaspored[i]) {
                trenutnoVrijeme++;
            }
        }

        minimalnoVrijeme = min(minimalnoVrijeme, trenutnoVrijeme);
    }

    cout << minimalnoVrijeme << "\n";

    return 0;
}
