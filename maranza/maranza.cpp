#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Numero di casi di test.
    int T;
    cin >> T;

    while (T--) {
        int N, K;

        cin >> N >> K;

        // M[i] contiene il numero di maranza della classe i.
        vector<int> M(N);

        for (int i = 0; i < N; i++) {
            cin >> M[i];
        }

        // Qui dovranno essere salvate le posizioni
        // delle classi che richiedono l'intervento.
        vector<int> risultato;

        // SCRIVI QUI IL TUO ALGORITMO

        // Stampa il numero di classi trovate.
        cout << risultato.size() << '\n';

        // Stampa le loro posizioni.
        for (int i = 0; i < (int)risultato.size(); i++) {
            if (i > 0)
                cout << ' ';

            cout << risultato[i];
        }

        cout << '\n';
    }

    return 0;
}