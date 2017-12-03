/* Computing the prefix-suffix table.
 * 
 * Author: Adam Bac
 */

#include <bits/stdc++.h>
using namespace std;


/* For a given string `str` returns
 * a table t such that t[i] is the length
 * of the longest proper prefix of str[0..i],
 * being also a suffix of str[0..i],
 * for 0 <= i < str.size()
 */
vector<int> pref_suf(const string& str) {
    int len = str.size(), ps;
    vector<int> t(len);
    
    // A single letter has no proper prefix
    t[0] = ps = 0;

    for(int i = 1; i < len; i++) {
        while(ps > 0 && str[ps] != str[i]) ps = t[ps - 1];
        if(str[ps] == str[i]) ps++;
        t[i] = ps;
    }

    return t;
}


int main() {
    cout << "Input string: ";
    string str;
    cin >> str;

    int ps = pref_suf(str).back();
    cout << "Longest prefix-suffix: " << str.substr(0, ps) << endl;
}
