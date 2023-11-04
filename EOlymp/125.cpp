#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int readTime() {
    int hours, minutes, seconds;
    cin >> hours >> minutes >> seconds;

    return hours * 3600 + minutes * 60 + seconds;
}

void writeTime(int time) {
    cout << time / 3600 << " " << time % 3600 / 60 << " " << time % 60;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l = readTime();
    int r = readTime();

    writeTime(r - l);
}