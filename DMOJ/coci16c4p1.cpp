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

    string values = "JQKA";
    int res = 0;

    for (int i = 0; i < size; i++) {
        string s;
        cin >> s;

        for (char c : s)
            if (int i = values.find(c); i != -1)
                res += i + 1;
    }

    cout << res;
}