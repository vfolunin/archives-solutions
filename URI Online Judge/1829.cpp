#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<double> prepare() {
    vector<double> logP(1e4 + 1);
    for (int i = 2; i < logP.size(); i++)
        logP[i] = logP[i - 1] + log(i);
    return logP;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int roundCount;
    cin >> roundCount;

    vector<string> roundWinner(roundCount);
    int scoreA = 0, scoreB = 0;

    for (int i = 0; i < roundCount; i++) {
        int a, p, b;
        char c;
        cin >> a >> c >> p >> b >> c;

        static vector<double> logP = prepare();

        double valueA = p * (logP[a] - logP[a - 1]);
        double valueB = logP[b];

        if (valueA > valueB) {
            roundWinner[i] = "Lucas";
            scoreA++;
        } else {
            roundWinner[i] = "Pedro";
            scoreB++;
        }
    }

    if (scoreA == scoreB)
        cout << "A competicao terminou empatada!\n";
    else
        cout << "Campeao: " << (scoreA > scoreB ? "Lucas" : "Pedro") << "!\n";
    for (int i = 0; i < roundCount; i++)
        cout << "Rodada #" << i + 1 << ": " << roundWinner[i] << " foi o vencedor\n";
}