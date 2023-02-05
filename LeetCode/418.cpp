class Solution {
    tuple<int, int, int> fit(vector<int> &sizes, int lineWidth, int width, vector<tuple<int, int, int>> &memo) {
        auto &[resCount, resLineCount, resLineWidth] = memo[lineWidth];
        if (resCount != -1)
            return { resCount, resLineCount, resLineWidth };
        
        resCount = 0;
        resLineCount = 0;
        resLineWidth = lineWidth;

        while (!resLineCount) {
            for (int size : sizes) {
                if (resLineWidth + (resLineWidth > 0) + size <= width) {
                    resLineWidth += (resLineWidth > 0) + size;
                } else {
                    resLineCount++;
                    resLineWidth = size;
                }
            }
            resCount++;
        }

        return { resCount, resLineCount, resLineWidth };
    }

public:
    int wordsTyping(vector<string> &a, int height, int width) {
        vector<int> sizes(a.size());
        for (int i = 0; i < a.size(); i++) {
            if (a[i].size() > width)
                return 0;
            sizes[i] = a[i].size();
        }

        int count = 0, lineCount = 0, lineWidth = width;
        vector<tuple<int, int, int>> memo(width + 1, { -1, -1, -1 });
        while (lineCount <= height) {
            auto [fitCount, fitLineCount, fitLineWidth] = fit(sizes, lineWidth, width, memo);
            count += fitCount;
            lineCount += fitLineCount;
            lineWidth = fitLineWidth;
        }
        return count - 1;
    }
};