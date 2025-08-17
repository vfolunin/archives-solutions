#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    unordered_map<string, bool> value;
    for (int i = 0; i < size; i++) {
        string type, name;
        cin >> type;

        if (type == "INNTAK") {
            string s;
            cin >> name >> s;
            
            value[name] = s == "SATT";
        } else if (type == "UTTAK") {
            cin >> name;

            cout << name << " " << (value[name] ? "SATT\n" : "OSATT\n");
        } else if (type == "OG") {
            string a, b;
            cin >> a >> b >> name;

            value[name] = value[a] && value[b];
        } else if (type == "EDA") {
            string a, b;
            cin >> a >> b >> name;

            value[name] = value[a] || value[b];
        } else {
            string s;
            cin >> s >> name;

            value[name] = !value[s];
        }
    }
}