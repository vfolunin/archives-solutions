#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int readTime() {
    int h, m;
    cin >> h >> m;
    return h * 60 + m;
}

void writeTime(int t) {
    cout << t / 60 << " " << t % 60;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t1 = readTime();
    int t2 = readTime();

    writeTime(t2 - t1);
}