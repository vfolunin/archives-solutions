using Complex = complex<double>;

void fft(vector<Complex> &p, Complex x) {
    int n = p.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n / 2;
        while (j & bit) {
            j ^= bit;
            bit /= 2;
        }
        j ^= bit;
        if (i < j)
            swap(p[i], p[j]);
    }

    for (int len = 2; len <= n; len *= 2) {
        Complex step = polar(1.0, arg(x) * (n / len));
        for (int i = 0; i < n; i += len) {
            Complex xPow = 1;
            for (int j = 0; j < len / 2; j++) {
                Complex a = p[i + j], b = xPow * p[i + j + len / 2];
                p[i + j] = a + b;
                p[i + j + len / 2] = a - b;
                xPow *= step;
            }
        }
    }
}

const double PI = acos(-1);

vector<Complex> fixSize(vector<int> &p, int targetSize) {
    vector<Complex> res(p.begin(), p.end());
    while (res.size() < targetSize || (res.size() & (res.size() - 1)))
        res.push_back(0);
    return res;
}

vector<Complex> evaluate(vector<int> &p, int targetSize) {
    vector<Complex> res = fixSize(p, targetSize);
    fft(res, polar(1.0, 2 * PI / res.size()));
    return res;
}

vector<int> interpolate(vector<Complex> &p) {
    int n = p.size();
    fft(p, polar(1.0, -2 * PI / n));

    vector<int> res(n);
    for (int i = 0; i < n; i++)
        res[i] = round(real(p[i]) / n);

    while (res.size() > 1 && !res.back())
        res.pop_back();
    return res;
}

vector<int> multiply(vector<int> &pa, vector<int> &pb) {
    int targetSize = pa.size() + pb.size();
    vector<Complex> a = evaluate(pa, targetSize);
    vector<Complex> b = evaluate(pb, targetSize);

    for (int i = 0; i < a.size(); i++)
        a[i] *= b[i];

    return interpolate(a);
}

class Solution {
public:
    int minOperations(string &s) {
        vector<int> cost(s.size());
        for (int border = 0; border < 13; border++) {
            vector<int> mask(s.size());
            int ones = 0;
            for (int i = 0; i < mask.size(); i++) {
                mask[i] = (s[i] - 'a' - border + 26) % 26 < 13;
                ones += mask[i];
            }

            vector<int> product = multiply(mask, mask);
            product.resize(s.size() * 2);
            for (int i = 0; i < s.size(); i++)
                cost[i] += ones - product[i] - product[i + s.size()];
        }

        int res = 1e9;
        for (int shift = 0; shift < s.size(); shift++)
            res = min(res, shift + cost[(shift * 2 + s.size() - 1) % s.size()]);
        return res;
    }
};