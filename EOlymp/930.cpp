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

    string res;
    for (char c = '0'; c <= '9'; c++)
        if (line.find(c) == -1)
            res += c;

    cout << res.size() << "\n";
    for (char c : res)
        cout << c << " ";
}