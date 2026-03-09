#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s >> s;

    vector<int> pos;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == 'A')
            pos.push_back(i);

    vector<int> res(s.size() + 1);
    iota(res.begin(), res.end(), 1);
    if (!pos.empty())
        reverse(res.begin() + pos[pos.size() / 2], res.end());

    for (int value : res)
        cout << value << " ";
}