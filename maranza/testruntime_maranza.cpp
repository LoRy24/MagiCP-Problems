#include <bits/stdc++.h>
using namespace std;

struct Test {
    int K;
    vector<int> M;
};

vector<int> randomValues(int n, int minValue, int maxValue, mt19937_64 &rng) {
    vector<int> values(n);
    uniform_int_distribution<int> dist(minValue, maxValue);

    for (int &x : values)
        x = dist(rng);

    return values;
}

void writeTests(const vector<Test> &tests) {
    // INPUT
    cout << tests.size() << '\n';

    for (const Test &test : tests) {
        int N = test.M.size();

        cout << N << ' ' << test.K << '\n';

        vector<int> answer;
        answer.reserve(N);

        for (int i = 0; i < N; i++) {
            if (i > 0)
                cout << ' ';

            cout << test.M[i];

            if (test.M[i] >= test.K)
                answer.push_back(i);
        }

        cout << '\n';

        // OUTPUT CORRETTO
        cerr << answer.size() << '\n';

        for (int i = 0; i < (int)answer.size(); i++) {
            if (i > 0)
                cerr << ' ';

            cerr << answer[i];
        }

        cerr << '\n';
    }
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Evita che stderr venga flushato ad ogni scrittura.
    cerr.tie(nullptr);
    cerr << nounitbuf;

    if (argc != 2)
        return 1;

    int testId = stoi(argv[1]);

    // Seed fisso: gli stessi test vengono sempre rigenerati uguali.
    mt19937_64 rng(0xC0FFEEULL + 1000003ULL * testId);

    vector<Test> tests;

    switch (testId) {

        // ---------------------------------------------------------
        // TASK 1 - Esempio 1
        // ---------------------------------------------------------
        case 1: {
            tests.push_back({
                2,
                {3, 1, 0, 4, 2}
            });

            break;
        }

        // ---------------------------------------------------------
        // TASK 2 - Esempio 2
        // ---------------------------------------------------------
        case 2: {
            tests.push_back({
                1,
                {1, 1, 1}
            });

            break;
        }

        // ---------------------------------------------------------
        // TASK 3 - K = 0, casi piccoli
        // ---------------------------------------------------------
        case 3: {
            tests.push_back({
                0,
                {0}
            });

            tests.push_back({
                0,
                {0, 1, 2, 3, 1000000000, 0, 5, 0}
            });

            tests.push_back({
                0,
                randomValues(1000, 0, 1000000000, rng)
            });

            break;
        }

        // ---------------------------------------------------------
        // TASK 4 - K = 0, N massimo
        // ---------------------------------------------------------
        case 4: {
            tests.push_back({
                0,
                randomValues(1000000, 0, 1000000000, rng)
            });

            break;
        }

        // ---------------------------------------------------------
        // TASK 5 - N <= 1000, casi limite
        // ---------------------------------------------------------
        case 5: {
            // Un solo elemento, esattamente K.
            tests.push_back({
                1000000000,
                {1000000000}
            });

            // Un solo elemento, sotto K.
            tests.push_back({
                1000000000,
                {999999999}
            });

            // Valori sotto, uguali e sopra K.
            tests.push_back({
                5,
                {4, 5, 6, 5, 0, 1000000000}
            });

            // Nessuna classe valida.
            vector<int> none(1000);

            for (int i = 0; i < 1000; i++)
                none[i] = i;

            tests.push_back({
                1000000000,
                none
            });

            // Tutte le classi valide.
            tests.push_back({
                0,
                randomValues(1000, 0, 1000000000, rng)
            });

            break;
        }

        // ---------------------------------------------------------
        // TASK 6 - N <= 1000, test più corposi
        // ---------------------------------------------------------
        case 6: {
            // Distribuzione casuale.
            tests.push_back({
                500000000,
                randomValues(1000, 0, 1000000000, rng)
            });

            // Tutti esattamente uguali a K.
            tests.push_back({
                123456789,
                vector<int>(1000, 123456789)
            });

            // Tutti appena sotto K.
            tests.push_back({
                1000000000,
                vector<int>(1000, 999999999)
            });

            // Alternanza K-1, K, K+1.
            vector<int> aroundK(1000);

            for (int i = 0; i < 1000; i++) {
                if (i % 3 == 0)
                    aroundK[i] = 99;
                else if (i % 3 == 1)
                    aroundK[i] = 100;
                else
                    aroundK[i] = 101;
            }

            tests.push_back({
                100,
                aroundK
            });

            break;
        }

        // ---------------------------------------------------------
        // TASK 7 - N massimo, valori casuali
        // ---------------------------------------------------------
        case 7: {
            tests.push_back({
                500000000,
                randomValues(1000000, 0, 1000000000, rng)
            });

            break;
        }

        // ---------------------------------------------------------
        // TASK 8 - N massimo, valori intorno a K
        // ---------------------------------------------------------
        case 8: {
            const int N = 1000000;
            const int K = 500000000;

            vector<int> values(N);

            for (int i = 0; i < N; i++) {
                switch (i % 5) {
                    case 0:
                        values[i] = K - 1;
                        break;

                    case 1:
                        values[i] = K;
                        break;

                    case 2:
                        values[i] = K + 1;
                        break;

                    case 3:
                        values[i] = 0;
                        break;

                    case 4:
                        values[i] = 1000000000;
                        break;
                }
            }

            tests.push_back({
                K,
                values
            });

            break;
        }

        // ---------------------------------------------------------
        // TASK 9 - K al valore massimo
        // Serve soprattutto a controllare >= invece di >
        // ---------------------------------------------------------
        case 9: {
            const int N = 1000000;
            const int K = 1000000000;

            vector<int> values(N, 999999999);

            for (int i = 0; i < N; i += 997)
                values[i] = 1000000000;

            values[N - 1] = 1000000000;

            tests.push_back({
                K,
                values
            });

            break;
        }

        // ---------------------------------------------------------
        // TASK 10 - Più test nello stesso input
        // Totale circa 1.000.000 di elementi.
        // ---------------------------------------------------------
        case 10: {
            vector<int> first(333333);

            for (int i = 0; i < (int)first.size(); i++)
                first[i] = i % 2;

            tests.push_back({
                1,
                first
            });

            // Tutti uguali al valore massimo di K.
            tests.push_back({
                1000000000,
                vector<int>(333333, 1000000000)
            });

            vector<int> third =
                randomValues(333334, 0, 1000000000, rng);

            // Inseriamo anche molti valori esattamente uguali a K.
            for (int i = 0; i < (int)third.size(); i += 100)
                third[i] = 123456789;

            tests.push_back({
                123456789,
                third
            });

            break;
        }

        default:
            return 1;
    }

    writeTests(tests);

    return 0;
}