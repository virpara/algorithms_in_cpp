#include <bits/stdc++.h>

using namespace std;

void bubble_sort(int * arr, int n);
void counting_sort(int * arr, int n);

int main() {
    int n, i = 0;

    cout << "Enter n: ";
    cin >> n;

    cout << "Enter elements: ";
    int arr[n] = {};
    while (i < n) {
        cin >> arr[i++];
    }

//    bubble_sort(arr, n);
    counting_sort(arr, n);

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
