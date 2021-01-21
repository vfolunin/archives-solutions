#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int n;
    if (scanf("%d", &n) == EOF)
        return 0;

    vector<pair<int, int>> segments = { {600, 600}, {1080, 1080} };
    for (int i = 0; i < n; i++) {
        int h1, m1, h2, m2;
        scanf("%d:%d %d:%d%*[^\n]", &h1, &m1, &h2, &m2);
        segments.push_back({ h1 * 60 + m1, h2 * 60 + m2 });
    }

    sort(segments.begin(), segments.end());

    int bestI = 0;
    for (int i = 0; i + 1 < segments.size(); i++)
        if (segments[i + 1].first - segments[i].second > segments[bestI + 1].first - segments[bestI].second)
            bestI = i;

    int startTime = segments[bestI].second;
    printf("Day #%d: the longest nap starts at %02d:%02d and will last for ", test, startTime / 60, startTime % 60);

    int napTime = segments[bestI + 1].first - segments[bestI].second;
    if (napTime >= 60)
        printf("%d hours and ", napTime / 60);
    printf("%d minutes.\n", napTime % 60);
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}