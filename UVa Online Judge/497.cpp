#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    vector<int> a;
    while (1) {
        string line;
        getline(cin, line);
        if (line.empty())
            break;
        a.push_back(stoi(line));
    }

    vector<int> lis(a.size(), 1), prev(a.size(), -1);
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
                prev[i] = j;
            }
        }
    }

    vector<int> path;
    for (int i = max_element(lis.begin(), lis.end()) - lis.begin(); i != -1; i = prev[i])
        path.push_back(i);
    reverse(path.begin(), path.end());

    if (test)
        cout << "\n";
    cout << "Max hits: " << path.size() << "\n";
    for (int i : path)
        cout << a[i] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore(2);

    for (int i = 0; i < n; i++)
        solve(i);
}