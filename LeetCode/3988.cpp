class Solution {
    void createCorridor(vector<string> &res, int startY, int startX) {
        for (int y = startY; y < res.size(); y++)
            res[y][startX] = '.';
        for (int x = startX + 1; x < res[0].size(); x++)
            res.back()[x] = '.';
    }

    vector<string> create1(vector<string> &res) {
        createCorridor(res, 0, 0);
        return res;
    }

    vector<string> create2(vector<string> &res) {
        if (res.size() >= 2 && res[0].size() >= 2) {
            for (int y = 0; y < 2; y++)
                for (int x = 0; x < 2; x++)
                    res[y][x] = '.';
            createCorridor(res, 1, 1);
            return res;
        }
        return {};
    }

    vector<string> create3(vector<string> &res) {
        int h = 0, w = 0;
        if (res.size() >= 2 && res[0].size() >= 3) {
            h = 2;
            w = 3;
        } else if (res.size() >= 3 && res[0].size() >= 2) {
            h = 3;
            w = 2;
        }

        if (!h)
            return {};

        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                res[y][x] = '.';
        createCorridor(res, h - 1, w - 1);
        return res;
    }

    vector<string> create4(vector<string> &res) {
        int h = 0, w = 0;
        if (res.size() >= 2 && res[0].size() >= 4) {
            h = 2;
            w = 4;
        } else if (res.size() >= 3 && res[0].size() >= 3) {
            h = 3;
            w = 3;
        } else if (res.size() >= 4 && res[0].size() >= 2) {
            h = 4;
            w = 2;
        }

        if (!h)
            return {};

        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                res[y][x] = '.';
        if (h == 3 && w == 3)
            res[0][2] = res[2][0] = '#';
        createCorridor(res, h - 1, w - 1);
        return res;
    }

public:
    vector<string> createGrid(int h, int w, int pathCount) {
        vector<string> res(h, string(w, '#'));

        if (pathCount == 1)
            res = create1(res);
        else if (pathCount == 2)
            res = create2(res);
        else if (pathCount == 3)
            res = create3(res);
        else
            res = create4(res);

        return res;
    }
};