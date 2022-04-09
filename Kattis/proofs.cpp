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

    int lineCount;
    cin >> lineCount;

    set<string> theorems;
    for (int i = 0; i < lineCount; i++) {
        while (1) {
            string token;
            cin >> token;
            if (token == "->") {
                cin >> token;
                theorems.insert(token);
                break;
            } else if (!theorems.count(token)) {
                cout << i + 1;
                return 0;
            }
        }
    }

    cout << "correct";
}