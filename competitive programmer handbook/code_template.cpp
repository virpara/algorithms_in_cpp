#include <bits/stdc++.h>

using namespace std;

int main() {

    // Input/output is sometimes a bottleneck. to make input and output more efficient. print to console order changes.
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    cout << "hello" << "\n";

    int a, b;
    string s;

    // taking input. e.g. 123 456 monkey
    // the below works if user gives spaces or new lines to separate the input
    cin >> a >> b >> s;
    cout << a << " " << b << " " << s << "\n";
    // note: the newline "\n" works faster than endl, because endl always causes a flush operation

    // faster but difficult to use
    scanf("%d %d", &a, &b);
    printf("%d %d\n", a, b);

    // read line
    string line;
    getline(cin, s);

    cout << "line: " << s << "\n";

    // get data until there is none. How to break this when getting data from console ?
    while (cin >> s) {
        cout << s;
    }

    // if files are used for input/output
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);



}
