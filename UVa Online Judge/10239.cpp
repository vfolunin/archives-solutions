#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int bookCount;
    double caseWidth;
    cin >> bookCount >> caseWidth;

    if (!bookCount && !caseWidth)
        return 0;

    vector<pair<double, double>> books(bookCount);
    for (auto &[h, w] : books)
        cin >> h >> w;

    vector<double> caseHeight(bookCount + 1, 1e9);
    caseHeight[0] = 0;

    for (int i = 1; i <= bookCount; i++) {
        double maxHeight = 0, totalWidth = 0;

        for (int j = i; j > 0; j--) {
            maxHeight = max(maxHeight, books[j - 1].first);
            totalWidth += books[j - 1].second;

            if (totalWidth <= caseWidth + 1e-9)
                caseHeight[i] = min(caseHeight[i], caseHeight[j - 1] + maxHeight);
        }
    }

    cout.precision(4);
    cout << fixed << caseHeight.back() << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}