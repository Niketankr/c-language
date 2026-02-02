#include <stdio.h>

double max(double a, double b) {
    return (a > b) ? a : b;
}

double min(double a, double b) {
    return (a < b) ? a : b;
}

double medianSingle(int arr[], int n) {
    if (n % 2 == 0)
        return (arr[n/2] + arr[n/2 - 1]) / 2.0;
    else
        return arr[n/2];
}

double findMedian(int A[], int B[], int n) {
    // Base cases
    if (n == 1)
        return (A[0] + B[0]) / 2.0;

    if (n == 2)
        return (max(A[0], B[0]) + min(A[1], B[1])) / 2.0;

    double m1 = medianSingle(A, n);
    double m2 = medianSingle(B, n);

    if (m1 == m2)
        return m1;

    if (m1 < m2) {
        if (n % 2 == 0)
            return findMedian(A + n/2 - 1, B, n - (n/2 - 1));
        else
            return findMedian(A + n/2, B, n - n/2);
    } else {
        if (n % 2 == 0)
            return findMedian(A, B + n/2 - 1, n - (n/2 - 1));
        else
            return findMedian(A, B + n/2, n - n/2);
    }
}

int main() {
    int n;

    printf("Enter size of arrays (n): ");
    scanf("%d", &n);

    int A[n], B[n];

    printf("Enter elements of array A (sorted):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    printf("Enter elements of array B (sorted):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &B[i]);
    }

    double median = findMedian(A, B, n);
    printf("Median of the two sorted arrays is: %.2f\n", median);

    return 0;
}


output:

Enter size of arrays (n): 5
Enter elements of array A (sorted):
25
56
65
45
28
Enter elements of array B (sorted):
85
65
75
15
35
Median of the two sorted arrays is: 56.50


  #include <stdio.h>

void sortDigits(int arr[], int n) {
    int count[10] = {0};

    
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    
    int index = 0;
    for (int digit = 0; digit <= 9; digit++) {
        while (count[digit] > 0) {
            arr[index++] = digit;
            count[digit]--;
        }
    }
}

int main() {
    int n;

    printf("Enter number of digits: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the digits (0 to 9):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    sortDigits(arr, n);

    printf("Sorted digits:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}


output:

Enter number of digits: 9
Enter the digits (0 to 9):
0
2
3
1
6
7
8
4
9
Sorted digits:
0 1 2 3 4 6 7 8 9 



  #include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}


int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}


void quickSelect(int arr[], int low, int high, int k) {
    if (low < high) {
        int p = partition(arr, low, high);

        if (p == k)
            return;
        else if (p > k)
            quickSelect(arr, low, p - 1, k);
        else
            quickSelect(arr, p + 1, high, k);
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int k = n / 2;  

    quickSelect(arr, 0, n - 1, k);

    int median = arr[k];

   
    int leftNeighbor = arr[0];
    for (int i = 0; i < k; i++) {
        if (arr[i] > leftNeighbor)
            leftNeighbor = arr[i];
    }

    int rightNeighbor = arr[k + 1];
    for (int i = k + 1; i < n; i++) {
        if (arr[i] < rightNeighbor)
            rightNeighbor = arr[i];
    }

    printf("Median: %d\n", median);
    printf("Left Neighbor: %d\n", leftNeighbor);
    printf("Right Neighbor: %d\n", rightNeighbor);

    return 0;
}


output:

Enter number of elements: 4
Enter elements:
32
65
74
98
Median: 74
Left Neighbor: 65
Right Neighbor: 98
