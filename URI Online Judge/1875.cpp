#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int goalCount;
    cin >> goalCount;

    string colors = "RGB";
    vector<pair<int, int>> score = { {0, 0}, {0, 1}, {0, 2} };
    for (int i = 0; i < goalCount; i++) {
        char a, b;
        cin >> a >> b;
        int ai = colors.find(a);
        int bi = colors.find(b);
        score[ai].first += 1 + ((ai + 1) % 3 == bi);
    }
    sort(score.begin(), score.end());

    vector<string> teams = { "red", "green", "blue" };
    if (score[0].first == score[2].first)
        cout << "trempate\n";
    else if (score[1].first == score[2].first)
        cout << "empate\n";
    else
        cout << teams[score[2].second] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}