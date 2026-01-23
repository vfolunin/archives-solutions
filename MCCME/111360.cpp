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

    vector<int> a;
    for (string s; getline(cin, s); ) {
        while (s.back() == ' ')
            s.pop_back();
        a.push_back(stoi(s.substr(s.rfind(' ') + 1)));
    }

    sort(a.rbegin(), a.rend());

    int index = 45 * a.size() / 100 - 1;
    if (index + 1 < a.size() && a[index] == a[index + 1] && a[index] <= 50) {
        do {
            index--;
        } while (index >= 0 && a[index] == a[index + 1]);
    }

    cout << a[index];
}