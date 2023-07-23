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
    char colon;
    cin >> h >> colon >> m;

    return h * 60 + m;
}

void writeTime(int time) {
    cout << setw(2) << setfill('0') << time / 60 << ":";
    cout << setw(2) << setfill('0') << time % 60;
}

bool isPalindrome(int time) {
    return time / 60 / 10 == time % 10 && time / 60 % 10 == time % 60 / 10;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int time = readTime();

    do {
        time = (time + 1) % (24 * 60);
    } while (!isPalindrome(time));

    writeTime(time);
}