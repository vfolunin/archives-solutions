class Solution {
    bool can(string &s, int w, int h, int font, FontInfo &fontInfo) {
        if (fontInfo.getHeight(font) > h)
            return 0;
        for (char c : s)
            w -= fontInfo.getWidth(font, c);
        return w >= 0;
    }

public:
    int maxFont(string &s, int w, int h, vector<int> &fonts, FontInfo &fontInfo) {
        sort(fonts.begin(), fonts.end());

        int l = -1, r = fonts.size();
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(s, w, h, fonts[m], fontInfo))
                l = m;
            else
                r = m;
        }
        return l == -1 ? l : fonts[l];
    }
};