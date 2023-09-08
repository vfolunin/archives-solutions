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

    int personCount, queryCount;
    cin >> personCount >> queryCount;

    map<int, string> persons;
    for (int i = 0; i < personCount; i++) {
        int phone;
        cin >> phone;

        string s;
        cin.ignore();
        getline(cin, s);
        persons[phone] = s;

        getline(cin, s);
        persons[phone] += " (" + s + ")";
    }

    for (int i = 0; i < queryCount; i++) {
        int phone;
        cin >> phone;

        cout << persons[phone] << "\n";
    }
}