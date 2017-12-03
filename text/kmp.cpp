/* Knuth-Morris-Pratt algorithm
 *
 * Author: Adam Bac
 */

#include <bits/stdc++.h>
using namespace std;


vector<int> kmp(const string& str, const string& pattern) {
    int n = str.size(), m = pattern.size();
    vector<int> t(m);

    int ps = 0;
    t[0] = ps;

    for(int i = 1; i < m; i++) {
        while(ps > 0 && pattern[ps] != pattern[i]) ps = t[ps - 1];
        if(pattern[ps] == pattern[i]) ps++;
        t[i] = ps;
    }

    vector<int> matches;
    ps = 0;

    for(int i = 0; i < n; i++) {
        while(ps > 0 && pattern[ps] != str[i]) ps = t[ps - 1];
        if(pattern[ps] == str[i]) ps++;
        if(ps == m) {
            matches.push_back(i - m + 1);
            ps = 0;
        }
    }

    return matches;
}


int main() {
    string str, pat;
    cout << "Input string: ";
    cin >> str;
    cout << "Pattern: ";
    cin >> pat;

    vector<int> matches = kmp(str, pat);
    cout << endl << "Found " << matches.size() << " matches:" << endl;
    cout << str << endl;
    int pos = 0;
    for(int m: matches) {
        for(; pos < m; pos++) cout << ' ';
        cout << '^';
        pos++;
    }
    cout << endl;
}
