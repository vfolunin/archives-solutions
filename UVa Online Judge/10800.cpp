#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    string s;
    cin >> s;

    vector<int> ys = { 0 };
    for (char c : s) {
        if (c == 'C')
            ys.push_back(ys.back());
        else if (c == 'R')
            ys.push_back(ys.back() + 1);
        else
            ys.push_back(ys.back() - 1);
    }

    int minY = *min_element(ys.begin(), ys.end());
    for (int &y : ys)
        y -= minY;

    int height = *max_element(ys.begin(), ys.end());
    bool decreaseHeight = 1;
    for (int i = 1; i < ys.size(); i++)
        if (ys[i - 1] == height && ys[i] == height)
            decreaseHeight = 0;
     height -= decreaseHeight;

    vector<string> plot(height + 1, string(ys.size(), ' '));
    for (int i = 1; i < ys.size(); i++) {
        if (ys[i - 1] == ys[i])
            plot[ys[i]][i - 1] = '_';
        else if (ys[i - 1] < ys[i])
            plot[ys[i] - 1][i - 1] = '/';
        else
            plot[ys[i]][i - 1] = '\\';
    }

    for (string &row : plot)
        while (!row.empty() && row.back() == ' ')
            row.pop_back();

    cout << "Case #" << test << ":\n";
    for (int i = height; i >= 0; i--)
        cout << "| " << plot[i] << "\n";
    cout << "+" << string(ys.size() + 1, '-') << "\n\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}