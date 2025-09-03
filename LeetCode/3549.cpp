class Solution {
    using Complex = complex<double>;

    void fft(vector<Complex> &p, Complex x) {
        size_t n = p.size();
        if (n == 1)
            return;

        vector<Complex> a(n / 2), b(n / 2);
        for (int i = 0; i < n / 2; i++) {
            a[i] = p[2 * i];
            b[i] = p[2 * i + 1];
        }

        fft(a, x * x);
        fft(b, x * x);

        Complex xPow = 1;
        for (int i = 0; i < n / 2; i++) {
            p[i] = a[i] + xPow * b[i];
            p[n / 2 + i] = a[i] - xPow * b[i];
            xPow *= x;
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

    vector<long long> interpolate(vector<Complex> &p, int size) {
        int n = p.size();
        fft(p, polar(1.0, -2 * PI / n));

        vector<long long> res(size);
        for (int i = 0; i < n && i < size; i++)
            res[i] = round(real(p[i]) / n);
        return res;
    }
    
public:
    vector<long long> multiply(vector<int> &pa, vector<int> &pb) {
        int targetSize = pa.size() + pb.size();
        vector<Complex> a = evaluate(pa, targetSize);
        vector<Complex> b = evaluate(pb, targetSize);

        for (int i = 0; i < a.size(); i++)
            a[i] *= b[i];

        return interpolate(a, pa.size() + pb.size() - 1);
    }
};