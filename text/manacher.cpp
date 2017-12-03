/**
 * Manacher's algorithm
 *
 * Author: Adam Bac
 *
 * Links:
 * [1] https://www.hackerrank.com/topics/manachers-algorithm
 * [2] http://was.zaa.mimuw.edu.pl/?q=node/5 (Polish)
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * Manacher's algorithm
 * @param  str input string
 * @param  sep separator to insert between characters,
 *             to ensure that both odd and even palindromes
 *             will be found (see link [1]).
 * @return     A vector of computed palindrome lengths
 *
 * Example:
 *
 * str = abba
 * i = 0 1 2 3 4 5 6 7 8
 * S = # a # b # b # a #
 * P = 0 1 0 1 4 1 0 1 0
 */
vector<int> manacher(const string& str, char sep) {
    int len = str.size(), n = len*2 + 1;
    vector<int> P(n);

    #define S(i) ((i & 1) ? str[(i - 1) >> 1] : sep)

    int R = 0;
    P[0] = 0;

    for(int i = 1; i < n;) {
        while(i - R - 1 >= 0 && i + R + 1 < n && S(i - R - 1) == S(i + R + 1))
            R++;
        P[i] = R;

        int k = 1;
        for(; k <= R && P[i - k] != R - k; k++) P[i + k] = min(P[i - k], R - k);
        i += k; R -= k;
    }

    return P;
}


int main() {
    cout << "Input string: ";
    string str;
    cin >> str;
    auto r = manacher(str, '#');
    for(int p: r) cout << p << ' ';
    cout << endl;
}
