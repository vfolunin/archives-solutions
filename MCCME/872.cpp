#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int readTime() {
    int h, m;
    cin >> h >> m;
    return h * 60 + m;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int t1 = readTime(), t2 = readTime(), t3 = readTime();

    int delta = (t3 - t1 + 24 * 60) % (24 * 60);
    t2 = (t2 + delta * 2) % (24 * 60);

    cout << t2 / 60 << " " << t2 % 60;
}