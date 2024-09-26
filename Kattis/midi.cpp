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

    string res;
    for (int i = 0; i < size; i++) {
        string s;
        cin >> s;

        res += s;
    }

    reverse(res.begin(), res.end());

    cout << res;
}