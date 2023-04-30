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

    string target;
    int wordCount;
    cin >> target >> wordCount;

    for (int i = 0; i < wordCount; i++) {
        string word;
        cin >> word;

        if (word == target) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
}