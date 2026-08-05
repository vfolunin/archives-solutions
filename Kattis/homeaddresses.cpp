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

    vector<pair<string, string>> addresses;
    for (string street, house; cin >> street >> house; )
        addresses.push_back({ street, house });

    cout << "[";
    for (int i = 0; i < addresses.size(); i++)
        cout << "'" << addresses[i].first << " " << addresses[i].second << "'" << (i + 1 < addresses.size() ? ", " : "");
    cout << "]\n[";
    for (int i = 0; i < addresses.size(); i++)
        cout << "('" << addresses[i].first << "', '" << addresses[i].second << "')" << (i + 1 < addresses.size() ? ", " : "");
    cout << "]";
}