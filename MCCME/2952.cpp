#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int readTime() {
    int h, m, s;
    cin >> h >> m >> s;
    return h * 3600 + m * 60 + s;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int ta = readTime();
    int tb = readTime();

    cout << tb - ta;
}