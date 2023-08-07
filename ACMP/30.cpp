#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int readTime() {
    int h, m, s;
    char colon;
    cin >> h >> colon >> m >> colon >> s;
    return h * 60 * 60 + m * 60 + s;
}

void processTime(int t, vector<int> &count) {
    int h = t / (60 * 60);
    int m = t / 60 % 60;
    int s = t % 60;

    count[h / 10]++;
    count[h % 10]++;
    count[m / 10]++;
    count[m % 10]++;
    count[s / 10]++;
    count[s % 10]++;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l = readTime();
    int r = readTime();

    vector<int> count(10);
    for (int t = l; t <= r; t++)
        processTime(t, count);

    for (int value : count)
        cout << value << "\n";
}