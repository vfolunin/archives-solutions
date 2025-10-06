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

pair<int, int> readSegment() {
    int l = readTime();
    char dash;
    cin >> dash;
    int r = readTime();

    return { l, r };
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    int res = 1e9;
    for (int i = 0; i < size; i++) {
        pair<int, int> prevSegment;
        int cur = 0;
        for (int j = 0; 1; j++) {
            pair<int, int> segment = readSegment();
            if (j)
                cur += segment.first - prevSegment.second;
            prevSegment = segment;
            if (cin.peek() == '\n')
                break;
        }
        res = min(res, cur);
    }

    cout << res;
}