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

    int res = 0;
    for (int i = 0; i < size; i++) {
        string s;
        cin >> s;

        res += (12 <= s.size() && s.size() <= 13 && s.substr(0, 3) == "+39");
    }

    cout << res;
}