#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int subjectCount;
    if (!(cin >> subjectCount))
        return 0;

    double num = 0, den = 0;
    for (int i = 0; i < subjectCount; i++) {
        double mark, load;
        cin >> mark >> load;
        num += mark * load;
        den += load;
    }
    den *= 100;

    cout.precision(4);
    cout << fixed << num / den << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}