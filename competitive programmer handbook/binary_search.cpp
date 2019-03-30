#include <bits/stdc++.h>

using namespace std;

int main() {

}

int bin_search(int * arr, int n, int search_for) {
    int a = 0, b = n - 1;

    while (a <= b) {
        int mid = (a + b) / 2;
        if (arr[mid] == search_for) {
            cout << "Found " << search_for << " at index " << mid << "\n";
            return mid;
        }
        if (arr[mid] < search_for) a = mid + 1;
        else b = mid - 1;
    }

    cout << "Couldn't find " << search_for << " in the array.";
}
