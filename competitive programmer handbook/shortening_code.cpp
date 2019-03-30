#include <bits/stdc++.h>

// macros
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i <= b; i++)
//#define SQ(a) a*a // does not work as expected for SQ(3+3) -> 3+3*3+3 = 15
#define SQ(a) (a)*(a)


using namespace std;

int main() {
//    // long code
//    v.push_back(make_pair(y1, x1));
//    v.push_back(make_pair(y2, x2));
//    int d = v[i].first + v[i].second;
//
//    for (int i = 1; i <= n; i++) {
//        search(i);
//    }

    // using macros
    v.PB(MP(y1, x1));
    v.PB(MP(y2, x2));
    int d = v[i].F + v[i].S;

    REP(i, 1, n) {
        search(i);
    }


//    long long a = 123456789;
//    long long b = 987654321;
//    cout << a*b << "\n";

    // using type names to shorten the code
    typedef long long ll;
    ll a = 123456789;
    ll b = 987654321;
    cout << a*b << "\n";

    typedef vector<int> vi;
    typedef pair<int, int> pi;
}
