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

    string s;
    cin >> s >> s;

    int res = 0;
    for (int i = 0; i < s.size(); ) {
        if (i + 1 < s.size() && s.substr(i, 2) == "IU") {
            i += 2;
        } else {
            res++;
            i++;
        }
    }

    cout << res / 2 << "\n";
}