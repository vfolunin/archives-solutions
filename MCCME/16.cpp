#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Human {
    int height, hands, index;

    bool operator < (const Human &that) const {
        return height + hands < that.height + that.hands;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int humanCount;
    cin >> humanCount;

    vector<Human> humans(humanCount);
    for (int i = 0; i < humanCount; i++) {
        cin >> humans[i].height >> humans[i].hands;
        humans[i].index = i + 1;
    }

    int depth;
    cin >> depth;

    int totalHeight = 0;
    for (auto &[height, hands, index] : humans)
        totalHeight += height;

    sort(humans.begin(), humans.end());

    vector<vector<int>> minEscapedHeight(humanCount + 1, vector<int>(humanCount + 1, 1e9));
    minEscapedHeight[0][0] = 0;

    int res = 0;
    vector<vector<int>> resIndex(humanCount + 1, vector<int>(humanCount + 1));

    for (int processed = 1; processed <= humanCount; processed++) {
        auto &[height, hands, index] = humans[processed - 1];

        for (int escaped = 0; escaped <= processed; escaped++) {
            if (minEscapedHeight[processed][escaped] > minEscapedHeight[processed - 1][escaped])
                minEscapedHeight[processed][escaped] = minEscapedHeight[processed - 1][escaped];

            if (escaped && totalHeight - minEscapedHeight[processed - 1][escaped - 1] + hands >= depth &&
                minEscapedHeight[processed][escaped] > minEscapedHeight[processed - 1][escaped - 1] + height) {
                minEscapedHeight[processed][escaped] = minEscapedHeight[processed - 1][escaped - 1] + height;
                res = max(res, escaped);
                resIndex[processed][escaped] = index;
            }
        }
    }

    cout << res << "\n";

    for (int processed = humanCount, escaped = res; escaped; processed--) {
        if (resIndex[processed][escaped]) {
            cout << resIndex[processed][escaped] << " ";
            escaped--;
        }
    }
}