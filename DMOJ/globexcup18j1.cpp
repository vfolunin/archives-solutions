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

    int size;
    cin >> size;

    vector<int> res(2);
    for (int i = 0; i < size; i++) {
        string s;
        cin >> s;

        res[s[s.find('.') + 1] >= '5']++;
    }

    cout << res[1] << "\n" << res[0];
}