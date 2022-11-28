class Solution {
    bool intersect(pair<int, int> &a, pair<int, int> &b) {
        return a.first <= b.second && b.first <= a.second;
    }

    pair<int, int> merge(pair<int, int> &a, pair<int, int> &b) {
        return { min(a.first, b.first), max(a.second, b.second) };
    }

public:
    vector<string> maxNumOfSubstrings(string &s) {
        vector<vector<int>> pos(26);
        vector<pair<int, int>> letterSegments(26, { -1, -1 });
        for (int i = 0; i < s.size(); i++) {
            pos[s[i] - 'a'].push_back(i);
            if (letterSegments[s[i] - 'a'].first == -1)
                letterSegments[s[i] - 'a'].first = i;
            letterSegments[s[i] - 'a'].second = i;
        }

        set<pair<int, int>> segmentSet;
        for (int i = 0; i < 26; i++) {
            if (letterSegments[i].first == -1)
                continue;

            pair<int, int> segment = letterSegments[i];
            while (1) {
                int prevSize = segment.second - segment.first + 1;

                for (int i = 0; i < 26; i++) {
                    if (letterSegments[i].first == -1)
                        continue;

                    auto l = lower_bound(pos[i].begin(), pos[i].end(), segment.first);
                    auto r = upper_bound(pos[i].begin(), pos[i].end(), segment.second);
                    if (l < r)
                        segment = merge(segment, letterSegments[i]);
                }

                if (prevSize == segment.second - segment.first + 1)
                    break;
            }

            segmentSet.insert(segment);
        }

        vector<pair<int, int>> segments(segmentSet.begin(), segmentSet.end());
        sort(segments.begin(), segments.end(), [](auto &a, auto &b) {
            return a.second - a.first < b.second - b.first;
        });

        vector<pair<int, int>> takenSegments;
        for (pair<int, int> &segment : segments) {
            bool intersects = 0;

            for (pair<int, int> &takenSegment : takenSegments) {
                if (intersect(segment, takenSegment)) {
                    intersects = 1;
                    break;
                }
            }

            if (!intersects)
                takenSegments.push_back(segment);
        }

        vector<string> res;
        for (auto &[l, r] : takenSegments)
            res.push_back(s.substr(l, r - l + 1));
        return res;
    }
};