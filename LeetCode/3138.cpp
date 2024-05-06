class Solution {
    unordered_map<char, int> getCount(string &s, int from, int width) {
        unordered_map<char, int> count;
        for (int i = from; i < from + width; i++)
            count[s[i]]++;
        return count;
    }

    bool check(string &s, int width) {
        unordered_map<char, int> count = getCount(s, 0, width);
        for (int from = width; from < s.size(); from += width)
            if (count != getCount(s, from, width))
                return 0;
        return 1;
    }

public:
    int minAnagramLength(string &s) {
        for (int width = 1; 1; width++)
            if (s.size() % width == 0 && check(s, width))
                return width;
    }
};