#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

// Deterministic Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i < j) {
        while(arr[i] <= pivot && i <= high-1) {
            i++;
        }

        while(arr[j] > pivot && j >= low+1) {
            j--;
        }

        if(i < j) {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[low], arr[j]);
    return j;
}

void qsort(int arr[], int low, int high) {
    if(low < high) {
        int part = partition(arr, low, high);

        qsort(arr, low, part-1);
        qsort(arr, part+1, high);
    }
}

// Randomized Quick Sort
int randomPartition(int arr[], int low, int high) {
    int r = low + rand() % (high - low + 1);

    swap(arr[low], arr[r]);

    return partition(arr, low, high);
}

void randomizedQuickSort(int arr[], int low, int high) {
    if(low < high) {
        int part = randomPartition(arr, low, high);

        randomizedQuickSort(arr, low, part-1);
        randomizedQuickSort(arr, part+1, high);
    }
}

int main() {
    int n, a[100], b[100];

    cout << "Enter number of elements: ";
    cin >> n;

    if(n < 1 || n > 100) {
        cout << "Invalid size";
        return 0;
    }

    cout << "Enter elements: ";

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    qsort(a, 0, n-1);

    cout << "Deterministic Quick Sort: ";
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    srand(time(0));

    randomizedQuickSort(b, 0, n-1);

    cout << "\nRandomized Quick Sort: ";
    for(int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }

    return 0;
}
