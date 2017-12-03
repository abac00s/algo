#include <bits/stdc++.h>
using namespace std;

vector<int> ps_tab(const string& s) {
    int n = s.size();
    vector<int> t(n);
    int l = t[0] = 0;
    for(int i = 1; i < n; i++) {
        while(l > 0 && s[l] != s[i]) l = t[l - 1];
        if(s[l] == s[i]) l++;
        t[i] = l;
    }
    return t;
}

vector<int> pref_suf(const string& s, const vector<int>& t) {
    vector<int> ps;
    int l = s.size();
    while(l > 0) {
        ps.push_back(l);
        l = t[l - 1];
    }
    reverse(ps.begin(), ps.end());
    return ps;
}

bool is_temp(const string& s, int l, const vector<int>& t) {
    int b = 0, len = 0;
    for(int i = 0; i < (int) s.size(); i++) {
        while(len >= l || (len > 0 && s[len] != s[i])) len = t[len - 1];
        if(s[len] == s[i]) len++;
        if(len == l) {
            if(i - l + 1 > b) return false;
            b = i + 1;
        }
    }
    return true;
}

int solve(const string& s) {
    auto t = ps_tab(s);
    auto ps = pref_suf(s, t);
    int i = 0;
    while(i < (int) ps.size()) {
        int l = ps[i];
        if(is_temp(s, l, t)) return l;
        while(i < (int) ps.size() && ps[i] < 2*l) i++;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin >> str;
    cout << solve(str) << '\n';
}
