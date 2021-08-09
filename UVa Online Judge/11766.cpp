#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int carCount;
    cin >> carCount;

    if (!carCount)
        return 0;

    vector<vector<int>> votes(carCount, vector<int>(carCount));
    for (int i = 0; i < carCount; i++) {
        int ahead, behind;
        cin >> ahead >> behind;

        if (ahead + behind < carCount) {
            int minPlace = ahead, maxPlace = carCount - 1 - behind;
            votes[minPlace][maxPlace] = min(votes[minPlace][maxPlace] + 1, maxPlace - minPlace + 1);
        }
    }

    vector<int> correctVotesTo(carCount);
    for (int maxPlace = 0; maxPlace < carCount; maxPlace++) {
        correctVotesTo[maxPlace] = votes[0][maxPlace];
        for (int minPlace = 1; minPlace <= maxPlace; minPlace++)
            correctVotesTo[maxPlace] = max(correctVotesTo[maxPlace], correctVotesTo[minPlace - 1] + votes[minPlace][maxPlace]);
    }

    cout << "Case " << test << ": " << carCount - correctVotesTo[carCount - 1] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}