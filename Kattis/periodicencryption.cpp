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

    int size, step;
    string s;
    cin >> size >> step >> s;
    step--;

    for (int i = step; !s.empty(); i += step) {
        i %= s.size();
        cout << s[i];
        s.erase(i, 1);
    }
}