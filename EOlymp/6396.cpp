#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Prize {
    vector<int> stickers;
    int cost;

    int getTotalCost(vector<int> &collectedStickers) {
        int count = 1e9;
        for (int i = 0; i < stickers.size(); i++)
            if (stickers[i])
                count = min(count, collectedStickers[i] / stickers[i]);
        return count * cost;
    }
};

void solve() {
    int prizeCount, stickerTypeCount;
    cin >> prizeCount >> stickerTypeCount;

    vector<Prize> prizes(prizeCount);
    for (auto &[stickers, price] : prizes) {
        int stickerCount;
        cin >> stickerCount;

        stickers.resize(stickerTypeCount);
        for (int i = 0; i < stickerCount; i++) {
            int sticker;
            cin >> sticker;
            stickers[sticker - 1]++;
        }

        cin >> price;
    }

    vector<int> collectedStickers(stickerTypeCount);
    for (int &stickerCount : collectedStickers)
        cin >> stickerCount;

    int totalCost = 0;
    for (Prize &prize : prizes)
        totalCost += prize.getTotalCost(collectedStickers);

    cout << totalCost << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}