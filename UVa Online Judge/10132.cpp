#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    vector<string> parts;
    int size = 0;

    while (1) {
        string part;
        getline(cin, part);

        if (part.empty())
            break;

        parts.push_back(part);
        size += part.size();
    }

    size /= (parts.size() / 2);
    
    map<string, int> count;
    string res;

    for (int i = 0; i < parts.size(); i++) {
        for (int j = 0; j < parts.size(); j++) {
            if (i != j && parts[i].size() + parts[j].size() == size) {
                string word = parts[i] + parts[j];
                count[word]++;
                if (res.empty() || count[word] > count[res])
                    res = word;
            }
        }
    }

    if (test)
        cout << "\n";
    cout << res << "\n";
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