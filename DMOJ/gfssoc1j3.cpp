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

    return hours * 60 * 60 + minutes * 60 + seconds;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t1 = readTime();
    int t2 = readTime();

    cout << t2 - t1;
}