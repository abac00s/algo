//////////////////////////////////////////////////////////////////
// Multiplication of long numbersf using Fast Fourier Transform //
// Author: Adam Bac					        //
// 							        //
// Takes two non-negative integers from the standard input      //
// and prints their product.				        //
//////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
#define REP(i, n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;
typedef complex<double> cd;

// MAX_LEN should be >= sum of lengths (in base 10)
// of input numbers.
const int MAX_LEN = 1<<19;


void fft(cd *v, int n, bool rev = false) {
    if(n == 1) return;
    int m = n/2;

    // Move all even coefficients/values to
    // first half of v and all odd to the second.
    static cd tmp[MAX_LEN];
    REP(i, m) tmp[i] = v[2*i + 1];
    REP(i, m) v[i] = v[2*i];
    REP(i, m) v[i + m] = tmp[i];

    fft(v, m, rev);
    fft(v + m, m, rev);

    REP(i, m) {
        cd even = v[i], odd = v[i + m];
        ld mul = rev ? -1.0 : 1.0;
        cd e = polar(1.0, mul*2*M_PI*i/n);
        v[i] = even + odd*e;
        v[i + m] = even - odd*e;
    }
}



/////////////////////////////////////////////////////
// Read a string and convert it to polynomial form //
/////////////////////////////////////////////////////
int read(cd *v) {
    string s;
    cin >> s;
    int l = s.size();
    REP(i, l) v[i] = s[l - i - 1] - '0';
    return l;
}


///////////////////////////////////////////////
// Smallest power of 2 greater or equal to x //
///////////////////////////////////////////////
int min_pow(int x) {
    int res = 1;
    while(res < x) res <<= 1;
    return res;
}


/////////////////
// Print table //
/////////////////
template <typename T>
void pt(T *v, int n) {
    REP(i, n) cout << v[i] << "  ";
    cout << endl;
}


cd p1[MAX_LEN], p2[MAX_LEN];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n1 = read(p1);
    int n2 = read(p2);

    int n = min_pow(n1 + n2);

    fft(p1, n);
    fft(p2, n);

    REP(i, n) p1[i] *= p2[i];

    fft(p1, n, true);

    REP(i, n) p1[i] /= n;

    vector<int> res(n);
    int carry = 0;
    REP(i, n) {
        carry += round(real(p1[i]));
        res[i] = carry%10;
        carry /= 10;
    }

    int b = n-1;
    while(res[b] == 0) b--;

    for(; b >= 0; b--) cout << res[b];
    cout << '\n';
}
