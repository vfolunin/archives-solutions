#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    unordered_set<string> departments;
    for (int i = 0; i < size; i++) {
        string s;
        cin >> s >> s >> s;
        departments.insert(s.substr(s.rfind('-') + 1));
    }

    cout << fixed << (double)size / departments.size();
}