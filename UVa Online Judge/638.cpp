#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int pointCount;
    cin >> pointCount;

    if (!pointCount)
        return 0;

    map<pair<int, int>, char> pointMap;

    for (int i = 0; i < pointCount; i++) {
        char c;
        int x, y;
        cin >> c >> x >> y;
        pointMap[{x, y}] = c;
    }

    vector<string> rects;
    for (auto ul = pointMap.begin(); ul != pointMap.end(); ul++) {
        for (auto dr = next(ul); dr != pointMap.end(); dr++) {
            if (ul->first.first >= dr->first.first || ul->first.second <= dr->first.second)
                continue;

            auto ur = pointMap.find({ dr->first.first, ul->first.second });
            if (ur == pointMap.end())
                continue;

            auto dl = pointMap.find({ ul->first.first, dr->first.second });
            if (dl == pointMap.end())
                continue;

            string rect;
            rect += ul->second;
            rect += ur->second;
            rect += dr->second;
            rect += dl->second;
            rects.push_back(rect);
        }
    }

    sort(rects.begin(), rects.end());

    cout << "Point set " << test << ":";
    if (rects.empty())
        cout << " No rectangles\n";
    else
        cout << "\n";
    for (int i = 0; i < rects.size(); i++) {
        cout << " " << rects[i];
        if (i % 10 == 9 || i + 1 == rects.size())
            cout << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}