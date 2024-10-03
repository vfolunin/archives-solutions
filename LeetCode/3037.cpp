class Solution {
public:
    int findPattern(InfiniteStream *stream, vector<int> &a) {
        a.push_back(-1);
        vector<int> p(1);
        
        for (int i = 1; 1; i++) {
            int value = i < a.size() ? a[i] : stream->next();

            int border = p.back();
            while (border > 0 && value != a[border])
                border = p[border - 1];
            p.push_back(border + (value == a[border]));

            if (p.back() == a.size() - 1)
                return i - 2 * (a.size() - 1);
        }
    }
};