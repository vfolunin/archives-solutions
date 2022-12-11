class Allocator {
    vector<int> used;
    map<int, vector<pair<int, int>>> usedSegments;

public:
    Allocator(int capacity) : used(capacity) {}

    int allocate(int size, int id) {
        if (size > used.size())
            return -1;

        int usedCount = count(used.begin(), used.begin() + size, 1);
        if (!usedCount) {
            usedSegments[id].push_back({ 0, size - 1 });
            fill(used.begin(), used.begin() + size, 1);
            return 0;
        }

        for (int l = 1, r = size; r < used.size(); l++, r++) {
            usedCount -= used[l - 1];
            usedCount += used[r];

            if (!usedCount) {
                usedSegments[id].push_back({ l, r });
                fill(used.begin() + l, used.begin() + r + 1, 1);
                return l;
            }
        }

        return -1;
    }

    int free(int id) {
        int res = 0;
        for (auto &[l, r] : usedSegments[id]) {
            fill(used.begin() + l, used.begin() + r + 1, 0);
            res += r - l + 1;
        }
        usedSegments.erase(id);
        return res;
    }
};