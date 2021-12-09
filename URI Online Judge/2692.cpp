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

    int swapCount, lineCount;
    cin >> swapCount >> lineCount;

    map<char, char> swaps;
    for (int i = 0; i < swapCount; i++) {
        char a, b;
        cin >> a >> b;
        swaps[a] = b;
        swaps[b] = a;
    }

    string line;
    getline(cin, line);

    for (int i = 0; i < lineCount; i++) {
        getline(cin, line);

        for (char &c : line)
            if (swaps.count(c))
                c = swaps[c];

        cout << line << "\n";
    }
}