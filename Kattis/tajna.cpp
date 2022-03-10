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

    string text;
    cin >> text;

    int h = 1;
    for (int i = 2; i * i <= text.size(); i++)
        if (text.size() % i == 0)
            h = i;
    int w = text.size() / h;

    for (int i = 0; i < text.size(); i++) {
        int y = i / w, x = i % w;
        cout << text[x * h + y];
    }
}