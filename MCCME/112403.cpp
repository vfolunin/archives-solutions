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

    string line;
    bool found = 0;

    while (getline(cin, line)) {
        for (int i = 0; i < line.size(); i++) {
            if (tolower(line[i]) == 'a' && (!i || line[i - 1] == ' ')) {
                cout << line << "\n";
                found = 1;
                break;
            }
        }
    }

    if (!found)
        cout << 0;
}