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
    getline(cin, line);

    int last = -1, res = 0;
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == '.' || line[i] == '?' || line[i] == '!') {
            res += last + 1 < i;
            last = i;
        }
    }

    cout << res;
}