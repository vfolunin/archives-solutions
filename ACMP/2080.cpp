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

    vector<int> count(s.size());
    for (int i = 1; i < s.size(); i++)
        if ((s[i - 1] == 'A' || s[i - 1] == 'C') && s[i] == 'B')
            count[i] = 1 + (i - 2 >= 0 ? count[i - 2] : 0);
    
    cout << *max_element(count.begin(), count.end());
}