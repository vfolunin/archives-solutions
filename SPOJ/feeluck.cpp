#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    vector<string> bestUrls;
    int bestScore = 0;

    for (int i = 0; i < 10; i++) {
        string url;
        int score;
        cin >> url >> score;

        if (score > bestScore) {
            bestUrls.clear();
            bestScore = score;
        }
        if (score == bestScore)
            bestUrls.push_back(url);
    }

    cout << "Case #" << test << ":\n";
    for (string &url : bestUrls)
        cout << url << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}