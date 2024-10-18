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
    cin >> size;

    vector<int> win(size + 1);
    for (int i = 1; i < win.size(); i++)
        for (int j = 1; j * j <= i && !win[i]; j++)
            win[i] |= !win[i - j * j];
    
    cout << count(win.begin() + 1, win.end(), 0) << "\n";
    for (int i = 1; i < win.size(); i++)
        if (!win[i])
            cout << i << "\n";
}