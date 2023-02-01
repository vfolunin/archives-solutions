class Solution {
    vector<int> decodeColor(string &color) {
        int r = stoi(color.substr(1, 2), 0, 16);
        int g = stoi(color.substr(3, 2), 0, 16);
        int b = stoi(color.substr(5, 2), 0, 16);
        return { r, g, b };
    }

    string encodeColor(vector<int> &color) {
        stringstream ss;
        ss << "#" << hex;
        for (int value : color)
            ss << setw(2) << setfill('0') << value;
        return ss.str();
    }

    vector<int> makeColorWithShorthand(int r, int g, int b) {
        return { r * 16 + r, g * 16 + g, b * 16 + b };
    }

    int getSimilarity(const vector<int> &a, const vector<int> &b) {
        int res = 0;
        for (int i = 0; i < a.size(); i++)
            res += (a[i] - b[i]) * (a[i] - b[i]);
        return -res;
    }

public:
    string similarRGB(string &color) {
        vector<int> colorA = decodeColor(color);

        int bestSimilarity = -1e9;
        vector<int> bestColor;

        for (int r = 0; r < 16; r++) {
            for (int g = 0; g < 16; g++) {
                for (int b = 0; b < 16; b++) {
                    vector<int> colorB = makeColorWithShorthand(r, g, b);
                    int similarity = getSimilarity(colorA, colorB);
                    if (bestSimilarity < similarity) {
                        bestSimilarity = similarity;
                        bestColor = colorB;
                    }
                }
            }
        }

        return encodeColor(bestColor);
    }
};