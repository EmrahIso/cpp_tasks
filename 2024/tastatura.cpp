#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 1. Učitavamo broj zamjena karaktera
    ll broj_zamjena;
    cin >> broj_zamjena;

    // 2. Kreiramo mapu koja čuva trenutnu "pravilan" zamjenu za svaki karakter
    map<char, char> tastatura;

    // 3. Procesiramo svaku zamjenu
    for(int i = 0; i < broj_zamjena; i++) {
        char slovo1, slovo2;
        cin >> slovo1 >> slovo2;

        // 3.1. Provjeravamo da li su karakteri već imali prethodnu zamjenu
        // Ako imaju, koristimo tu vrijednost, inače ostavljamo originalni karakter
        char trenutna_vrijednost_slovo1 = tastatura.count(slovo1) ? tastatura[slovo1] : slovo1;
        char trenutna_vrijednost_slovo2 = tastatura.count(slovo2) ? tastatura[slovo2] : slovo2;

        // 3.2. Zamjenjujemo mjesta u mapi
        // Ovo omogućava da se prethodne zamjene propagiraju na nove karaktere
        tastatura[slovo1] = trenutna_vrijednost_slovo2;
        tastatura[slovo2] = trenutna_vrijednost_slovo1;
    }

    // 4. Učitavamo riječ koju želimo dekodirati
    string rijec;
    cin >> rijec;

    // 5. Prolazimo kroz svaki karakter u riječi
    for(char slovo : rijec) {
        // 5.1. Ako je slovo zamijenjeno u mapi, ispisujemo njegovu zamjenu
        if(tastatura.count(slovo))
            cout << tastatura[slovo];
        else
            // 5.2. Ako nije zamijenjeno, ispisujemo originalni karakter
            cout << slovo;
    }

    cout << "\n"; // 6. Novi red na kraju

    return 0;
}
