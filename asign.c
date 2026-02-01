#include <stdio.h>
#include <limits.h>

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Array must contain at least two elements\n");
        return 0;
    }

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max1 = INT_MIN, max2 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX;

    for (int i = 0; i < n; i++) {

        
        if (arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        } else if (arr[i] > max2 && arr[i] != max1) {
            max2 = arr[i];
        }

        
        if (arr[i] < min1) {
            min2 = min1;
            min1 = arr[i];
        } else if (arr[i] < min2 && arr[i] != min1) {
            min2 = arr[i];
        }
    }

    printf("\n1st Maximum = %d", max1);
    printf("\n2nd Maximum = %d", max2);
    printf("\n1st Minimum = %d", min1);
    printf("\n2nd Minimum = %d", min2);

    return 0;
}

output:

Enter number of elements: 8
Enter 8 elements:
4
56
87
98
78
12
53
87

1st Maximum = 98
2nd Maximum = 87
1st Minimum = 4
2nd Minimum = 12
#include <stdio.h>
#include <limits.h>

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Array must contain at least two elements\n");
        return 0;
    }

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max1 = INT_MIN, max2 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX;

    for (int i = 0; i < n; i++) {

        
        if (arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        } else if (arr[i] > max2 && arr[i] != max1) {
            max2 = arr[i];
        }

        
        if (arr[i] < min1) {
            min2 = min1;
            min1 = arr[i];
        } else if (arr[i] < min2 && arr[i] != min1) {
            min2 = arr[i];
        }
    }

    printf("\n1st Maximum = %d", max1);
    printf("\n2nd Maximum = %d", max2);
    printf("\n1st Minimum = %d", min1);
    printf("\n2nd Minimum = %d", min2);

    return 0;
}

output:

Enter number of elements: 8
Enter 8 elements:
4
56
87
98
78
12
53
87

1st Maximum = 98
2nd Maximum = 87
1st Minimum = 4
2nd Minimum = 12


#include <stdio.h>


int firstOccurrence(int arr[], int n, int x) {
    int low = 0, high = n - 1, result = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == x) {
            result = mid;
            high = mid - 1;   // move left
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}


int lastOccurrence(int arr[], int n, int x) {
    int low = 0, high = n - 1, result = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == x) {
            result = mid;
            low = mid + 1;   
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

int main() {
    int n, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter sorted array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to count: ");
    scanf("%d", &x);

    int first = firstOccurrence(arr, n, x);

    if (first == -1) {
        printf("Count of %d = 0\n", x);
    } else {
        int last = lastOccurrence(arr, n, x);
        printf("Count of %d = %d\n", x, last - first + 1);
    }

    return 0;
}

output :

Enter number of elements: 8
Enter sorted array elements:
35
46
56
68
78
87
98
99
Enter element to count: 3
Count of 3 = 0


#include <stdio.h>
#include <limits.h>

double findMedian(int A[], int B[], int n) {
    int low = 0, high = n;

    while (low <= high) {
        int i = (low + high) / 2;
        int j = n - i;

        int Aleft  = (i == 0) ? INT_MIN : A[i - 1];
        int Aright = (i == n) ? INT_MAX : A[i];
        int Bleft  = (j == 0) ? INT_MIN : B[j - 1];
        int Bright = (j == n) ? INT_MAX : B[j];

        if (Aleft <= Bright && Bleft <= Aright) {
            return ( (double)( (Aleft > Bleft ? Aleft : Bleft) +
                                (Aright < Bright ? Aright : Bright) ) ) / 2;
        }
        else if (Aleft > Bright) {
            high = i - 1;
        }
        else {
            low = i + 1;
        }
    }

    return -1; 
}

int main() {
    int n;

    printf("Enter size of arrays: ");
    scanf("%d", &n);

    int A[n], B[n];

    printf("Enter sorted array A:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    printf("Enter sorted array B:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &B[i]);

    double median = findMedian(A, B, n);
    printf("Median = %.2f\n", median);

    return 0;
}


output:

Enter size of arrays: 5
Enter sorted array A:
45
56
65
75
78
Enter sorted array B:
23
32
35
45
65
Median = 50.50
