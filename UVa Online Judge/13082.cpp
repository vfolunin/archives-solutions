#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int studentCount;
    cin >> studentCount;

    deque<int> height(studentCount);
    for (int &h : height)
        cin >> h;

    int minMoved = 1e9;
    while (!height.empty()) {
        int minHeight = *min_element(height.begin(), height.end());
        while (height.front() != minHeight) {
            minMoved = min(minMoved, height.front());
            height.pop_front();
        }
        height.pop_front();
    }
    
    int res = 0;
    if (minMoved != 1e9)
        res = studentCount - minMoved + 1;

    cout << "Case " << test << ": " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}