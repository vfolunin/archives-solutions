#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int questionCount;
    double minProb;
    cin >> questionCount >> minProb;

    if (!questionCount)
        return 0;

    vector<double> expectedPrize(questionCount + 1);
    expectedPrize[questionCount] = 1LL << questionCount;
    for (int i = questionCount - 1; i >= 0; i--) {
        double prob = (1LL << i) / expectedPrize[i + 1];
        if (prob < minProb) {
            expectedPrize[i] = (minProb + 1) / 2 * expectedPrize[i + 1];
        } else {
            double leavePrize = 1LL << i;
            double guessPrize = (prob + 1) / 2 * expectedPrize[i + 1];
            expectedPrize[i] = leavePrize * (prob - minProb) / (1 - minProb) + guessPrize * (1 - prob) / (1 - minProb);
        }
    }

    cout.precision(3);
    cout << fixed << expectedPrize[0] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}