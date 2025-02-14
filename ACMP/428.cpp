#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
 
using namespace std;
 
const int max_size = 80 * 4 + 5;
const int BigInt_size = 10;
int Amount[30] ={   1,2,3,      // ABC
                    1,2,3,      // DEF
                    1,2,3,      // GHI
                    1,2,3,      // JKL
                    1,2,3,      // MNO
                    1,2,3,4,    // PQRS
                    1,2,3,      // TUV
                    1,2,3,4 };  // WXYZ
 
int Button[30] = {  2,2,2,      // ABC
                    3,3,3,      // DEF
                    4,4,4,      // GHI
                    5,5,5,      // JKL
                    6,6,6,      // MNO
                    7,7,7,7,    // PQRS
                    8,8,8,      // TUV
                    9,9,9,9 };  // WXYZ
 
int Len[10];           
void input(int &n, string &init)
{
    for (int i=0;i<30;i++)
        Len[Button[i]]++;
    cin>>n;
    cin>>init;
}
void ParseStr(string &init, vector<int> &mas)
{
    mas.push_back(0);
    for (int i=0;i<init.size();i++)
    {
        int len = Amount[init[i] - 'A'];
        for (int j=0;j<len;j++)
            mas.push_back(Button[init[i] - 'A']);
    }
}
 
int osn = 100000000;
char* format = "%.8d";
struct BigInt
{
    int amount;
    int digits[BigInt_size];
    BigInt()
    {
        amount = 1;
        memset(digits, 0, sizeof(digits));
    }
    BigInt(int n)
    {
        amount = 1;
        memset(digits, 0 , sizeof(digits));
        digits[0] = n;
    }
    void output()
    {
        cout<<digits[amount-1];
        for (int i=amount-2;i>=0;i--)
            printf(format,digits[i]);
    }
};
BigInt operator + (const BigInt &a, const BigInt &b)
{
    BigInt res;
    res.amount = max(a.amount, b.amount);
    int r = 0;
    for (int i=0;i<res.amount || r;i++)
    {
        res.digits[i] = a.digits[i] + b.digits[i] + r;
        if (res.digits[i] >= osn)
        {
            res.digits[i] -= osn;
            r = 1;
        }
        else
            r = 0;
    }
    if (res.digits[res.amount])
        res.amount++;
    return res;
}
void solve(int n, string &init)
{
    vector<int> str;
    ParseStr(init,str);
    vector<vector<BigInt> > mas = vector<vector<BigInt> >(n+1,vector<BigInt>(str.size(),BigInt(0)));
 
    mas[0][0] = BigInt(1);
 
    for (int i=1;i<mas.size();i++)
    {
        for (int j=1;j<mas[i].size();j++)
        {
            mas[i][j] = mas[i-1][j-1];
            int len = Len[str[j]];
            for (int k = 1; k < len; k++)
            {
                if (j - k - 1 >=0 && str[j] == str[j-k])
                    mas[i][j] = mas[i][j] + mas[i-1][j-k-1];
                else
                    break;
            }
        }
    }
    mas[n].back().output();
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 
    int n;
    string init;
    input(n,init);
    solve(n,init);
    return 0;
} 
