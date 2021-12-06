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

    vector<int> scores(5);

    for (int &score : scores) {
        for (int i = 0; i < 4; i++) {
            int grade;
            cin >> grade;
            score += grade;
        }
    }

    int maxPos = max_element(scores.begin(), scores.end()) - scores.begin();

    cout << maxPos + 1 << " " << scores[maxPos];
}