#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Ukupno minuta u jednom danu
    ll ukupnoMinutaUDanu = 24 * 60; // 1440

    // Broj termina koji su zauzeti
    ll brojTermina;

    // Svaki termin ima: startSat, startMinuta, krajSat, krajMinuta
    vector<vector<ll>> termini;

    cin >> brojTermina;

    // Učitavanje svih termina
    for (int i = 0; i < brojTermina; i++) {
        vector<ll> jedanTermin;

        for (int j = 0; j < 4; j++) {
            ll vrijednost;
            cin >> vrijednost;
            jedanTermin.push_back(vrijednost);
        }

        termini.push_back(jedanTermin);
    }

    // Prolazimo kroz sve termine i računamo koliko vremena zauzimaju
    for (int i = 0; i < termini.size(); i++) {

        ll startSat = termini[i][0];
        ll startMinuta = termini[i][1];
        ll krajSat = termini[i][2];
        ll krajMinuta = termini[i][3];

        // Računanje trajanja termina u minutama
        // prvo razlika sati -> pretvori u minute
        // zatim oduzmi početne minute i dodaj završne
        ll trajanjeTermina = ((krajSat - startSat) * 60) - startMinuta + krajMinuta;

        // Oduzimamo zauzeto vrijeme od ukupnog vremena u danu
        ukupnoMinutaUDanu -= trajanjeTermina;
    }

    // Ispis koliko minuta je ostalo slobodno u danu
    cout << ukupnoMinutaUDanu << "\n";

    return 0;
}
