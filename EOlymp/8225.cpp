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

    string word, text;
    int from;
    cin >> word >> text >> from;
    from--;

    for (int i = 0; i < word.size(); i++) {
        if (text[from + i] != word[i]) {
            cout << "NO\n" << i + 1;
            return 0;
        }
    }

    cout << "YES\n" << word.size();
}