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

    int personCount;
    cin >> personCount;

    map<vector<int>, string> person;
    for (int i = 0; i < personCount; i++) {
        vector<int> date(3);
        string name;
        cin >> name >> date[2] >> date[1] >> date[0];
        person[date] = name;
    }

    cout << person.rbegin()->second << "\n";
    cout << person.begin()->second << "\n";
}