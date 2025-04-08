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

    vector<int> res(s.size() + 1);
    int l = -1, r = 1;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '<')
            res[i + 1] = r++;
        else
            res[i + 1] = l--;

    for (int value : res)
        cout << value - l << "\n";
}