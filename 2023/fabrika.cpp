#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // broj mašina i broj dana
    ll brojMasina;
    ll brojDana;

    cin >> brojMasina >> brojDana;

    // matrica podataka:
    // red = mašina
    // kolona = dan
    vector<vector<ll>> proizvodnja;

    // unos podataka za svaku mašinu
    for(ll i = 0; i < brojMasina; i++) {

        vector<ll> proizvodnjaMasine;

        for(ll j = 0; j < brojDana; j++) {

            ll kolicina;

            cin >> kolicina;

            // dodaj proizvodnju tog dana
            proizvodnjaMasine.push_back(kolicina);
        }

        // dodaj podatke za tu mašinu u glavnu matricu
        proizvodnja.push_back(proizvodnjaMasine);
    }

    // ovdje ćemo čuvati maksimalnu proizvodnju za svaki dan
    vector<ll> maksimumPoDanu;

    // prolazimo kroz svaki dan
    for(int dan = 0; dan < brojDana; dan++) {

        ll najveci = 0;

        // provjeravamo sve mašine za taj dan
        for(int masina = 0; masina < brojMasina; masina++) {

            if(proizvodnja[masina][dan] > najveci) {
                najveci = proizvodnja[masina][dan];
            }

        }

        // zapamtimo maksimalnu vrijednost za taj dan
        maksimumPoDanu.push_back(najveci);
    }

    // ispis rezultata
    for(ll vrijednost : maksimumPoDanu) {
        cout << vrijednost << " ";
    }

    return 0;
}
