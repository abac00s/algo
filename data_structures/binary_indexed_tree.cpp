/* Demonstration of Binary Indexed Tree data strucure.
 *
 * Author: Adam Bac
 *
 * The following implementation implements BIT with sum
 * operation, although it is possible to use other
 * operations, i.e. xor.
 */

#include <bits/stdc++.h>
using namespace std;

template <class T>
class BIT {
public:
    BIT(int l);
    void add(int pos, T x);
    T get_prefix(int pos);

private:
    inline int jump(int x);

    vector<T> v;
    int len;
};

template <class T>
BIT<T>::BIT(int l) : len(l) {
    v.resize(l, 0);
}

template <class T>
void BIT<T>::add(int pos, T x) {
    pos++;
    for(; pos <= len; pos += jump(pos)) {
        v[pos-1] += x;
    }
}

template <class T>
T BIT<T>::get_prefix(int pos) {
    pos++;
    T ret = 0;
    for(; pos > 0; pos -= jump(pos)) {
        ret += v[pos-1];
    }
    return ret;
}

template <class T>
inline int BIT<T>::jump(int x) {
    return x&(-x);
}

int main() {
    cout << "Number of cells: ";
    int n;
    cin >> n;

    BIT<int> bit(n);
    cout << "BIT has been created and filled with zeros." << endl;

    while(true) {
        cout << "Action (a - add, g - get prefix, q - quit): ";
        char action;
        cin >> action;
        if(action == 'a') {
            int pos, x;
            cout << "Position (0 - " << n-1 << "): ";
            cin >> pos;
            cout << "Value to add: ";
            cin >> x;
            bit.add(pos, x);
        }
        else if(action == 'g') {
            int pos;
            cout << "End of the prefix (0 - " << n-1 << "): ";
            cin >> pos;
            cout << "Sum = " << bit.get_prefix(pos) << endl;
        }
        else if(action == 'q') {
            return 0;
        }
        else {
            cout << "Incorrect action." << endl;
        }
    }
}
