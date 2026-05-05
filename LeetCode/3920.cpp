class Solution {
public:
    int maxFixedPoints(vector<int> &a) {
        vector<pair<int, int>> pairs;
        for (int i = 0; i < a.size(); i++)
            if (i >= a[i])
                pairs.push_back({ i - a[i], a[i] });

        sort(pairs.begin(), pairs.end());
        
        vector<int> lisLast(a.size() + 1, 1e9);
        lisLast[0] = -1e9;
        
        for (auto [_, value] : pairs)
            *lower_bound(lisLast.begin(), lisLast.end(), value) = value;

        int lisSize = a.size();
        while (lisLast[lisSize] == 1e9)
            lisSize--;
        return lisSize;
    }
};