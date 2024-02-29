#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long readTime() {
    long long t = 0, value;
    char c;
    do {
        cin >> noskipws >> value >> c;
        t = t * 60 + value;
    } while (c == ':');
    return t;
}

void writeTime(long long t) {
    long long days = t / (24 * 60 * 60);
    t %= 24 * 60 * 60;
    int h = t / (60 * 60), m = t / 60 % 60, s = t % 60;
    cout << setw(2) << setfill('0') << h << ":";
    cout << setw(2) << setfill('0') << m << ":";
    cout << setw(2) << setfill('0') << s;
    if (days)
        cout << "+" << days << " days";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long t = readTime();
    t += readTime();

    writeTime(t);
}