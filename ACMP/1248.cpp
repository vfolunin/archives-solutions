#include <iostream>
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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int time = readTime();

    vector<int> hours = { 0, 8, 9, 10, 11, 11, 13, 13, 15, 15, 16, 17, 18 };
    vector<int> minutes = { 0, 30, 55, 10, 35, 50, 15, 45, 10, 25, 50, 5, 30 };
    vector<string> names = { "MORNING", "1", "BREAK", "2", "BREAK", "3", "BREAK", "4", "BREAK", "5", "BREAK", "6", "EVENING" };
    
    vector<int> times(hours.size());
    for (int i = 0; i < hours.size(); i++)
        times[i] = hours[i] * 60 + minutes[i];

    cout << names[upper_bound(times.begin(), times.end(), time) - times.begin() - 1];
}