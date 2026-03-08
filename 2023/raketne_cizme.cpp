#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    // Ubrzava ulaz/izlaz
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // Broj stepenica u nizu
    ll broj_stepenica;
    cin >> broj_stepenica;

    // Niz visina stepenica
    vector<ll> visine_stepenica(broj_stepenica);
    for(int i = 0; i < broj_stepenica; i++) {
        cin >> visine_stepenica[i];
    }

    // Niz za čuvanje visinskih razlika između uzastopnih stepenica
    vector<ll> visinske_razlike;
    for(int i = 1; i < broj_stepenica; i++) {
        ll razlika = visine_stepenica[i] - visine_stepenica[i - 1];
        visinske_razlike.push_back(razlika);
    }

    // Sortiramo razlike od najveće ka najmanjoj
    sort(visinske_razlike.rbegin(), visinske_razlike.rend());

    // Ispisujemo drugu po veličini visinsku razliku
    cout << visinske_razlike[1] << "\n";

    return 0;
}
