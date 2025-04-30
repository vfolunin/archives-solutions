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

    vector<int> count(26);
    for (int i = 0; i < size; i++) {
        string s;
        cin >> s;

        count[s[0] - 'a']++;
    }

    bool found = 0;
    for (int i = 0; i < count.size(); i++) {
        if (count[i] >= 5) {
            cout << (char)(i + 'a');
            found = 1;
        }
    }

    if (!found)
        cout << "PREDAJA";
}