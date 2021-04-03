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

    int size;
    cin >> size;

    vector<string> a(size);
    for (string &row : a)
        cin >> row;

    while (1) {
        string word;
        cin >> word;

        if (word == "0")
            break;

        bool found = 0;
        for (int i = 0; !found && i < size; i++) {
            for (int j = 0; !found && j < size; j++) {
                static vector<int> di = { -1, 0, 1, 1, 1, 0, -1 };
                static vector<int> dj = { 1, 1, 1, 0, -1, -1, -1 };
                for (int d = 0; !found && d < 7; d++) {
                    bool ok = 1;
                    for (int s = 0; ok && s < word.size(); s++) {
                        int ti = i + di[d] * s, tj = j + dj[d] * s;
                        ok &= (0 <= ti && ti < size && 0 <= tj && tj < size && a[ti][tj] == word[s]);
                    }
                    if (ok) {
                        cout << i + 1 << "," << j + 1 << " ";
                        cout << i + di[d] * (word.size() - 1) + 1 << ",";
                        cout << j + dj[d] * (word.size() - 1) + 1 << "\n";
                        found = 1;
                    }
                }
            }
        }

        if (!found)
            cout << "Not found\n";
    }
}