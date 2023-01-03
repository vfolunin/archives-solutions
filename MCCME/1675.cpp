#include <iostream>
#include <iomanip>
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

    int t = readTime();

    t = (t + 150) % (24 * 60);

    cout << setw(2) << setfill('0') << t / 60 << ":";
    cout << setw(2) << setfill('0') << t % 60;
}