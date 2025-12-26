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

    writeTime((readTime() - 45 + 24 * 60) % (24 * 60));
}