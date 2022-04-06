/* Testprogram for Spiderman's Workout
 * Author: Mikael Goldmann
 *
 *        Reads spiderman.in  (filename char *infile below can be changed if argc==2)
 *        and reads the output of candidate solution on stdin.
 *        Computes cost of optimal solution.
 *        Checks that candidate solution is legal and does not
 *        exceed optimal cost.
 *
 *        On correct solution exit code is 0
 *        and on incorrect exit code is 1
 *
 *        A message to standard output indicates success or the
 *        nature of a filure (testing stops after first incorrectly
 *        solved testcase.
 *
 *        Configuration: Must have correct search path to test input.
 */

#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

int  d[50];
int  minh[50][1010];
char Move[50][1010];


const int infty = 1000000000;


const char *infile = "input.txt"; // path to test input


bool check(ifstream &test, int casenr)
{
    int m;
    test >> m;
    int tot = 0;

    for (int i = 0; i < m; ++i) {
        test >> d[i];
        tot += d[i];
    }



    for (int i = 0; i < m; ++i)
        for (int j = 0; j <= tot; ++j)
            minh[i][j] = infty;

    minh[0][d[0]] = d[0];
    Move[0][d[0]] = 'U';
    for (int i = 1; i < m; ++i)
        for (int h = 0; h <= tot; ++h) {
            if (minh[i - 1][h] != infty) {
                if (h >= d[i]) { // try climbing down
                    if (minh[i][h - d[i]] > minh[i - 1][h]) {
                        minh[i][h - d[i]] = minh[i - 1][h];
                        Move[i][h - d[i]] = 'D';
                    }
                }
                // try climbing up
                int newminh = max(minh[i - 1][h], h + d[i]);
                if (minh[i][h + d[i]] > newminh) {
                    minh[i][h + d[i]] = newminh;
                    Move[i][h + d[i]] = 'U';
                }
            }


        }

    string sol;
    if (!(cin >> sol)) {// submitted solutions answer
        cout << "Missing solution for case " << casenr << endl;
        return false;
    }

    if (minh[m - 1][0] == infty)
        if (sol == "IMPOSSIBLE")
            return true;
        else {
            cout << "program says " << sol
                << " but should say IMPOSSIBLE for case " << casenr << endl;
            return false;
        }



    if (static_cast<int>(sol.length()) != m) {
        cout << "Incorrect solution to case " << casenr
            << ": string " << sol << " has wrong lenth," << endl;
        return false;
    }

    int mh = minh[m - 1][0];
    int h = 0;
    for (int i = 0; i < m; ++i) {
        //   cerr <<  sol[i] << endl;

        if (sol[i] == 'U')
            h += d[i];
        else if (sol[i] == 'D')
            h -= d[i];
        else {
            cout << "Illegal character:'" << sol[i] << "' in solution to case "
                << casenr << endl;
            return false;
        }

        //    cerr << h << endl;
        if (h < 0) {
            cout << "Below the ground in case " << casenr << endl;
            return false;
        } else if (h > mh) {
            cout << "Above optimal height in case " << casenr << endl;
            return false;
        }
    }
    if (h != 0) {
        cout << "Not finishing on the ground in case " << casenr << endl;
        return false;
    }

    return true;
}



int  main(int argc, char **argv)
{
    freopen("output.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;

    ifstream test("input.txt");
    test >> n;
    //  cerr << infile << endl;

    for (int i = 1; i <= n; ++i)
        if (!check(test, i)) {
            // cerr << "ERROR" << endl;
            return 1;
        }

    string rest;

    if (cin >> rest) {
        cout << "Data after last solution: " << rest << endl;

        return 1;
    }
    cout << "Correct" << endl;

    return 0;
}