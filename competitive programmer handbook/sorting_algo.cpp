#include <bits/stdc++.h>

using namespace std;

void bubble_sort(int * arr, int n);
void counting_sort(int * arr, int n);
void merge_sort(int * arr, int n);

int main() {
    int n, i = 0;

    cout << "Enter n: ";
    cin >> n;
    if (n < 1) {
        cout << "n cannot be " << n << "\n";
        return -1;
    }

    cout << "Enter elements: ";
    int arr[n] = {};
    while (i < n) {
        cin >> arr[i++];
    }

//    bubble_sort(arr, n);
//    counting_sort(arr, n);
    merge_sort(arr, n);

    // print array
    i = 0;
    while (i < n) {
        cout << arr[i++] << " ";
    }
}

// worst case: O(n^2)
// avg case: O(n^2)
// best case O(n^2)
/*
Bubble sort is an example of a sorting algorithm that always swaps consecutive
elements in the array. It turns out that the time complexity of such an algorithm
is always at least O(n2), because in the worst case, O(n2) swaps are required for
sorting the array.

A useful concept when analyzing sorting algorithms is an inversion: a pair
of array elements (array[a],array[b]) such that a < b and array[a] > array[b], i.e.,
the elements are in the wrong order.

The number of inversions indicates
how much work is needed to sort the array. An array is completely sorted when
there are no inversions. On the other hand, if the array elements are in the
reverse order, the number of inversions is the largest possible
*/
void bubble_sort(int * arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

/*
merge sort was invented by J. von Neumann in 1945
worst case: O(n log n)
*/
void merge_sort(int * arr, int n) {
    if (n == 1) { // base-case
        return;
    }

    int pn = n/2;
    int rn = n - pn;
    int p[pn], r[rn];
    int k = 0;
    for (int i = 0; i < pn; i++) p[i] = arr[k++];
    for (int i = 0; i < rn; i++) r[i] = arr[k++];

    // divide the array in half
    merge_sort(p, pn);
    merge_sort(r, rn);

    // actually sort the divided array
    // since the p and r are sorted, iterate over them and pick the smallest
    // by looking at the first element of each array.
    k = 0;
    int temp_pn = 0, temp_rn = 0;
    while (temp_pn < pn && temp_rn < rn) {
        if (p[temp_pn] < r[temp_rn]) arr[k++] = p[temp_pn++];
        else arr[k++] = r[temp_rn++];
    }

    // sort the remaining elements, if the length of p and r are not same
    while (temp_pn < pn) arr[k++] = p[temp_pn++];
    while (temp_rn < rn) arr[k++] = r[temp_rn++];
}


/* Counting sort
The lower bound n log n does not apply to algorithms that do not compare array
elements but use some other information. An example of such an algorithm is
counting sort that sorts an array in O(n) time assuming that every element in
the array is an integer between 0...c and c = O(n)

The algorithm creates a bookkeeping array, whose indices are elements of the
original array. The algorithm iterates through the original array and calculates
how many times each element appears in the array.

Counting sort is a very efficient algorithm but it can only be used when the
constant c is small enough, so that the array elements can be used as indices in
the bookkeeping array.
*/
void counting_sort(int * arr, int n) {
    int max_val = 0;
    for (int i = 0; i < n; i++) {
        max_val = max(max_val, arr[i]);
    }

    int bookkeeper[max_val+1] = {};
    for (int i = 0; i < n; i++) {
        bookkeeper[arr[i]] += 1;
    }

    int j = 0;
    for (int i = 0; i < max_val + 1; i++) {
        int nb_occurence = bookkeeper[i];
        if (nb_occurence != 0) {
            while (nb_occurence-- > 0) {
                arr[j++] = i;
            }
        }
    }
}
