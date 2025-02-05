class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>> &segments) {
        for (int i = 0; i < segments.size(); i++)
            segments[i].push_back(i);

        sort(segments.begin(), segments.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });

        vector res(segments.size(), vector(5, pair<long long, vector<int>>{ -1e18, {} }));
        for (int i = 0; i < segments.size(); i++) {
            if (i)
                res[i] = res[i - 1];

            if (res[i][1].first < segments[i][2] || res[i][1].first == segments[i][2] && res[i][1].second[0] > segments[i][3])
                res[i][1] = { segments[i][2], { segments[i][3] } };

            int l = -1, r = i;
            while (l + 1 < r) {
                int m = l + (r - l) / 2;
                if (segments[m][1] < segments[i][0])
                    l = m;
                else
                    r = m;
            }
            if (l == -1)
                continue;

            for (int count = 2; count <= 4; count++) {
                if (res[l][count - 1].first == -1e18)
                    continue;
                
                long long bonus = res[l][count - 1].first + segments[i][2];
                vector<int> indexes = res[l][count - 1].second;
                indexes.push_back(segments[i][3]);
                sort(indexes.begin(), indexes.end());

                if (res[i][count].first < bonus || res[i][count].first == bonus && res[i][count].second > indexes)
                    res[i][count] = { bonus, indexes };
            }
        }

        long long resBonus = 0;
        vector<int> resIndexes;
        for (auto &[bonus, indexes] : res.back()) {
            if (resBonus < bonus || resBonus == bonus && resIndexes > indexes) {
                resBonus = bonus;
                resIndexes = indexes;
            }
        }
        return resIndexes;
    }
};