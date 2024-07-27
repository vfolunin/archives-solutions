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

    string s;
    cin >> s;

    int suffixSum = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] < '9' && suffixSum) {
            s[i]++;

            fill(s.begin() + i + 1, s.end(), '0');            
            suffixSum--;
            for (int j = s.size() - 1; suffixSum; j--) {
                int delta = min(suffixSum, 9);
                suffixSum -= delta;
                s[j] += delta;
            }

            cout << s;
            return 0;
        }

        suffixSum += s[i] - '0';
    }

    fill(s.begin(), s.end(), '0');
    suffixSum--;
    for (int j = s.size() - 1; suffixSum; j--) {
        int delta = min(suffixSum, 9);
        suffixSum -= delta;
        s[j] += delta;
    }

    cout << 1 << s;
}