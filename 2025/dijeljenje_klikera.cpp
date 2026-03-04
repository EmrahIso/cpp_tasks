#include <bits/stdc++.h>   // uključuje sve standardne C++ biblioteke
using namespace std;

// long long koristimo jer ograničenje kaže:
// N može biti do 10^18 → int bi overflowao
using ll = long long;

int main() {
    // ubrzava cin/cout (standardna praksa na takmičenjima)
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // N  -> početni broj klikera
    // K  -> koliko klikera dajemo svakoj prijateljici
    // P  -> broj prijateljica
    ll nKlikeri;
    ll kBrojKlikeraPoPrijatelju;
    ll pPrijatelji;

    // unos podataka
    cin >> nKlikeri;
    cin >> kBrojKlikeraPoPrijatelju;
    cin >> pPrijatelji;

    /*
        Ideja:
        Za svaku prijateljicu:
        1. oduzmemo K klikera od trenutnog broja
        2. ispišemo koliko je ostalo

        Primjer:
        N=100, K=10, P=4

        iteracija 1 -> 90
        iteracija 2 -> 80
        iteracija 3 -> 70
        iteracija 4 -> 60
    */

    // radimo tačno P puta (simulacija dijeljenja)
    while (pPrijatelji > 0) {

        // Una daje K klikera jednoj prijateljici
        nKlikeri -= kBrojKlikeraPoPrijatelju;

        // ispisujemo koliko joj je ostalo nakon tog dijeljenja
        cout << nKlikeri << '\n';

        // jedna prijateljica je već dobila klikere → smanjujemo brojač
        pPrijatelji--;
    }

    // uspješan završetak programa
    return 0;
}
