#include <bits/bits/stdc++.h>

using namespace std;

int main() {
    /*
    The function sort requires that a comparison operator is defined for the data
    type of the elements to be sorted. this operator will be used
    whenever it is necessary to find out the order of two elements.

    Most C++ data types have a built-in comparison operator, and elements
    of those types can be sorted automatically.
    */

    vector<int> v = {4, 2, 5, 3, 5, 8, 3};
    sort(v.begin(), v.end()); // ascending sort
    sort(v.rbegin(), v.rend()); // descending sort

    // sorting ordinary array
    int n = 7;
    int a[] = {4, 2, 5, 3, 5, 8, 3};
    sort(a, a + n);

    // sorting string
    string s = "codemonkey";
    sort(s.begin(), s.end());

    /* Pairs (pair) are sorted primarily according to their first elements (first).
    However, if the first elements of two pairs are equal, they are sorted according to
    their second elements (second)
    */

    vector<pair<int, int>> v;
    v.push_back({1, 5});
    v.push_back({2, 3});
    v.push_back({1, 2});
    sort(v.begin(), s.end());

    /* tuples (tuple) are sorted primarily by the first element,
    secondarily by the second element, etc.
    Note: in some older compilers, the function make_tuple has to be used to create a tuple
    instead of braces
    */
    vector<tuple<int, int, int>> v;
    v.push_back({2, 1, 4});
    v.push_back({1, 5, 3});
    v.push_back({2, 1, 3});
    sort(v.begin(), v.end());

    /*
    User-defined structs do not have a comparison operator automatically. The
    operator should be defined inside the struct as a function operator<, whose
    parameter is another element of the same type. The operator should return true
    if the element is smaller than the parameter, and false otherwise.
    */
    struct P {
        int x, y;
        bool operator<(const P &p) {
            if ( x != p.x) return x < p.x;
            else return y < p.y;
        }
    };

    /*
    It is also possible to give an external comparison function to the sort function
    as a callback function. For example, the following comparison function comp sorts
    strings primarily by length and secondarily by alphabetical order.
    */
    bool comp(string a, string b) {
        if (a.size() != b.size()) return a.size() < b.size();
        return a < b;
    }

    // sorting vector of strings
    sort(v.begin(), v.end(), comp);
}
