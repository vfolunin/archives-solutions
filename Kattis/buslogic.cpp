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

    int index, h, w;
    cin >> index >> h >> w;
    index--;

    vector<string> a(h);
    string res(w, '0');

    for (string &s : a) {
        cin >> s;

        if (s[index] == '1')
            for (int x = 0; x < w; x++)
                if (x != index && s[x] == '1')
                    res[x] = '1';
    }

    cout << count(res.begin(), res.end(), '1');
}