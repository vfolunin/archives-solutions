#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int readTime() {
    int hours, minutes;
    cin >> hours >> minutes;
    return hours * 60 + minutes;
}

void writeTime(int time) {
    cout << time / 60 << " " << time % 60;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l = readTime();
    int m = 12 * 60;
    int r = readTime();

    int lm = m - l;
    int mr = r - m;

    writeTime((mr - lm) / 2);
}