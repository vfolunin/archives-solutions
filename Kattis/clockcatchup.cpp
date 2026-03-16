#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int readTime() {
    int hours, minutes, seconds;
    char colon;
    cin >> hours >> colon >> minutes >> colon >> seconds;

    return hours * 3600 + minutes * 60 + seconds;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t1 = readTime();
    int t2 = readTime();

    vector<int> res(3);
    for (int t = t1 + 1; t <= t2; t++) {
        res[0] += t % (12 * 60 * 60) == 0;
        res[1] += t % (60 * 60) == 0;
        res[2] += t % 60 == 0;
    }

    for (int value : res)
        cout << value << " ";
}