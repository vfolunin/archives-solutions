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

    vector<string> parts;
    for (string part; cin >> part; )
        parts.push_back(part);

    cout << parts.back() << (parts.size() > 1 ? "," : "");
    for (int i = 0; i + 1 < parts.size(); i++)
        cout << " " << parts[i][0] << ".";
}