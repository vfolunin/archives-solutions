#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int volunteerCount, cardCount;
    if (!(cin >> volunteerCount >> cardCount))
        return 0;

    vector<int> returned(volunteerCount);
    for (int i = 0; i < cardCount; i++) {
        int card;
        cin >> card;
        returned[card - 1] = 1;
    }

    vector<int> missing;
    for (int i = 0; i < volunteerCount; i++)
        if (!returned[i])
            missing.push_back(i);
    
    if (missing.empty()) {
        cout << "*\n";
    } else {
        for (int card : missing)
            cout << card + 1 << " ";
        cout << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}