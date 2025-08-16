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
    char c;
    int border, margin;
    cin >> s >> c >> border >> margin;

    int h = (border + margin) * 2 + 1;
    int w = (border + margin) * 2 + s.size();

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (y < border || y + border >= h || x < border || x + border >= w)
                cout << c;
            else if (y < border + margin || y + margin + border >= h || x < border + margin || x + margin + border >= w)
                cout << " ";
            else
                cout << s[x - border - margin];
        }
        cout << "\n";
    }
}