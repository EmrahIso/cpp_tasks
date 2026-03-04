#include <bits/stdc++.h>   // uključuje sve standardne C++ biblioteke
using namespace std;

// long long koristimo jer brojevi mogu biti veliki
using ll = long long;

int main() {
    ios::sync_with_stdio(false); // ubrzava cin/cout
    cin.tie(nullptr);

    ll nDuzinaNiza; // duzina niza
    cin >> nDuzinaNiza;

    vector<ll> niz(nDuzinaNiza); // vektor koji čuva sve brojeve
    for(int i = 0; i < nDuzinaNiza; i++) {
        cin >> niz[i]; // unos svih brojeva
    }

    // provjeravamo pravilo parnosti:
    // - neparni indexi (1,3,5,...) moraju biti neparni
    // - parni indexi (2,4,6,...) moraju biti parni
    for(int i = 1; i <= nDuzinaNiza; i++) {
        if(i % 2 == 0) {
            // trenutno smo na PARNOJ poziciji (2,4,...)
            if(niz[i - 1] % 2 != 0) { // broj na toj poziciji nije paran
                cout << "Portal ostaje zatvoren" << '\n';
                break; // odmah izlazimo jer pravilo nije zadovoljeno
            }
        } else {
            // trenutno smo na NEPARNOJ poziciji (1,3,...)
            if(niz[i - 1] % 2 == 0) { // broj na toj poziciji nije neparan
                cout << "Portal ostaje zatvoren" << '\n';
                break; // odmah izlazimo
            }
        }

        // ako smo stigli do kraja i pravilo je zadovoljeno za sve elemente
        if(i == nDuzinaNiza) {
            cout << "Portal se otvara" << '\n';
        }
    }

    return 0;
}

/*
Objašnjenje rješenja:

1. Učitavamo dužinu niza i same brojeve.
2. Iteriramo kroz niz koristeći 1-based indeks (i = 1 ... nDuzinaNiza) zbog lakšeg
   prepoznavanja parnih/neparnih pozicija (1. pozicija = neparna, 2. pozicija = parna, itd.)
3. Za svaku poziciju provjeravamo:
   - Ako je parna pozicija → broj mora biti paran
   - Ako je neparna pozicija → broj mora biti neparan
4. Ako bilo koji broj ne zadovoljava pravilo, ispisujemo "Portal ostaje zatvoren" i prekidamo
5. Ako smo prošli sve elemente, ispisujemo "Portal se otvara"
*/
