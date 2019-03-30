#include <bits/stdc++.h>

using namespace std;

void algo1(int * arr, int n);
void algo2(int * arr, int n);
void algo3(int * arr, int n);

// maximum subarray sum.
// we assume that an empty subarray is allowed and the maximum
// subarray sum is always at least 0.
int main() {
    int n, i = 0;

    cout << "number of elements: ";
    cin >> n;

    int arr[n] = {};
    // check content
//    for (int x = 0; x < n; x++) {
//        cout << arr[x] << " ";
//    }
//    cout << "\n";

    while (i < n) {
        cin >> arr[i++];
    }

    algo1(arr, n);
    algo2(arr, n);
    algo3(arr, n);

}

// O(n^3)
void algo1(int * array, int n) {
    int best = 0;
    for (int a = 0; a < n; a++) {
        for (int b = a; b < n; b++) {
            int sum = 0;
            for (int j = a; j <= b; j++) {
                sum += array[j];
            }

            best = max(best, sum);

        }
    }

    cout << "Algo1 O(n^3): max subarray sum: " << best << "\n";
}

// O(n^2)
void algo2(int * array, int n) {
    int best = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += array[j];
            best = max(best, sum);
        }
    }

    cout << "Algo2 O(n^2): max subarray sum: " << best << "\n";
}

// O(n) Kadane's Algorithm
// for each array, calculate maximum sum of a subarray that ends at that position.
// After this, the answer is maximum of these sums
void algo3(int * array, int n) {
    int best = 0, sum = 0;

    for (int i = 0; i < n; i++) {
        sum = max(array[i], sum + array[i]); // find max from the subarray to the right of element i
        best = max(best, sum);
    }

    cout << "Algo3 O(n): max subarray sum: " << best << "\n";
}
