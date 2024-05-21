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

    int swapCount;
    cin >> swapCount;

    vector<vector<int>> has = { { 1, 0, 0 }, { 0, 1, 0 }, { 0, 0, 1 } };
    vector<int> score(3);

    for (int i = 0; i < swapCount; i++) {
        int a, b, guess;
        cin >> a >> b >> guess;
        a--;
        b--;
        guess--;

        for (int j = 0; j < has.size(); j++) {
            swap(has[j][a], has[j][b]);
            score[j] += has[j][guess];
        }
    }

    cout << *max_element(score.begin(), score.end());
}