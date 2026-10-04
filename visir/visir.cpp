#include <bits/stdc++.h>

using namespace std;

int solve(int N, vector<int>& D) {
    // Scrivi qui la tua soluzione.
    return 67;
}

// Warning! Non toccare questa parte di codice >>

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> D(N);
        for (int i = 0; i < N; i++)
            cin >> D[i];

        cout << solve(N, D) << '\n';
    }

    return 0;
}

// <<
