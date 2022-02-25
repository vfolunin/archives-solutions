#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int passwordCount;
    cin >> passwordCount;

    vector<double> probs(passwordCount);
    for (double &prob : probs) {
        string password;
        cin >> password >> prob;
    }

    sort(probs.rbegin(), probs.rend());

    double res = 0;
    for (int i = 0; i < probs.size(); i++)
        res += probs[i] * (i + 1);

    cout << fixed << res;
}