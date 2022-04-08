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

    int n;
    cin >> n;

    string s = "a";
    for (; n >= 25; n -= 25)
        s.push_back('a' + 'z' - s.back());
    if (n)
        s.push_back(s.back() == 'a' ? 'a' + n : 'z' - n);
    
    if (s.size() > 2) {
        for (; s[1] > 'a'; s[1]--) {
            if (s[s.size() - 2] == 'a') {
                if (s.back() + 2 > 'z')
                    break;
                s.back() += 2;
            } else {
                if (s.back() - 2 < 'a')
                    break;
                s.back() -= 2;
            }
        }
    }

    cout << s;
}