#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int followerCount, targetFollowerCount;
    cin >> followerCount >> targetFollowerCount;

    deque<int> followers(30);
    int sum = 0;
    for (int &f : followers) {
        cin >> f;
        sum += f;
    }

    int days = 0;
    while (followerCount < targetFollowerCount) {
        followers.push_back((sum + 29) / 30);
        sum += followers.back();
        sum -= followers.front();
        followers.pop_front();
        followerCount += followers.back();
        days++;
    }

    cout << days << "\n";
}