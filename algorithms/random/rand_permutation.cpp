/* Generating random permutations
 * Adam Bac
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <cstdlib>
using namespace std;

// Returns a random integer from the range [a, b]
int get_rand(int a, int b) {
    return rand()%(b - a + 1) + a;
}

template <class T>
ostream & operator<<(ostream & os, const vector<T> & v) {
    os << '{';
    for(int i = 0; i < v.size(); i++) {
        os << v[i];
        if(i != v.size() - 1) os << ", ";
    }
    os << '}';
    
    return os;
}

/* Naive approach for each argument of the permutation, choose
 * a value randomly until you get one that hasn't been used before.
 */
void rand_perm1(vector<int>& v) {
    int n = v.size();
    unordered_set<int> used;

    for(int i = 0; i < n;) {
        int next_val = get_rand(1, n);
        if(used.find(next_val) == used.end()) {
            v[i++] = next_val;
            used.insert(next_val);
        }
    }
}

int main() {
    cout << "Generating random permutations\n\n";

    srand(time(0));
    
    vector<int> v(10);

    cout << "Naive approach 1:\n";
    for(int i = 0; i < 5; i++) {
        rand_perm1(v);
        cout << v << endl;
    }
}
