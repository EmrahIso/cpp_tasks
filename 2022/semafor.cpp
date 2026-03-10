#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // ulaz

    ll broj_redova;
    ll broj_kolona;

    cin >> broj_redova >> broj_kolona;

    vector<string> semafor;

    for(int i = 0; i < broj_redova; i++) {
        string unos;
        cin >> unos;

        semafor.push_back(unos);
    }

    vector<vector<string>> cifre = {
        {"***","*.*","*.*","*.*","***"}, //0
        {"..*",".**","*.*","..*","..*"}, //1
        {"***","..*","***","*..","***"}, //2
        {"***","..*","***","..*","***"}, //3
        {"*.*","*.*","***","..*","..*"}, //4
        {"***","*..","***","..*","***"}, //5
        {"***","*..","***","*.*","***"}, //6
        {"***","..*","..*","..*","..*"}, //7
        {"***","*.*","***","*.*","***"}, //8
        {"***","*.*","***","..*","***"}  //9
    };


    vector<int> rezultat(10, 0);


    for(int i = 0; i <= broj_redova - 5; i++) {
        for(int j = 0; j <= broj_kolona - 3; j++) {
            for(int c = 0; c <= 9; c++) {
                bool poklapanje = true;

                for(int r = 0; r < 5; r++) {
                    for(int k = 0; k < 3; k++) {
                        if(semafor[i+r][j+k] != cifre[c][r][k]) {
                            poklapanje = false;
                        }
                    }
                }

                if(poklapanje) {
                    rezultat[c]++;
                }
            }
        }
    }

    for(int i = 0; i< 10; i++) {
        cout << rezultat[i] << " ";
    }

    return 0;
}
