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
    string s;
    cin >> size >> s;

    int count1 = 0, count2 = 0;
    long long res = 0;

    for (char c : s) {
        if (c == '1') {
            if (count1 + 1 + count2 * 2 <= size) {
                count1++;
            } else if (count2 && (count1 + 1) + (count2 - 1) * 2 <= size) {
                count1++;
                count2--;
            }
        } else {
            if (count1 + (count2 + 1) * 2 <= size)
                count2++;
        }
        res += count1 + count2;
    }

    cout << res;
}