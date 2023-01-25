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

    vector<int> count(26);

    while (1) {
        char c;
        cin >> c;

        if (c == '.')
            break;

        if (isalpha(c))
            count[tolower(c) - 'a']++;
    }

    int index = max_element(count.begin(), count.end()) - count.begin();
    cout << (char)('A' + index) << " " << count[index];
}