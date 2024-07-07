#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int friendCount, purchaseCount;
    cin >> friendCount >> purchaseCount;

    if (!friendCount)
        return 0;

    vector<double> purchaseProb(friendCount);
    for (double &p : purchaseProb)
        cin >> p;

    string mask(friendCount, '0');
    fill(mask.begin(), mask.begin() + purchaseCount, '1');
    reverse(mask.begin(), mask.end());

    vector<double> resProb(friendCount);
    double totalProb = 0;
    do {
        double p = 1;
        for (int i = 0; i < friendCount; i++)
            p *= (mask[i] == '1' ? purchaseProb[i] : 1 - purchaseProb[i]);
        totalProb += p;
        for (int i = 0; i < friendCount; i++)
            if (mask[i] == '1')
                resProb[i] += p;
    } while (next_permutation(mask.begin(), mask.end()));

    cout << "Case " << test << ":\n";
    cout.precision(6);
    for (double p : resProb)
        cout << fixed << p / totalProb << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}