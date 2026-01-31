#include <stdio.h>

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the bitonic sequence:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    
    for (i = 1; i < n - 1; i++) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            printf("Bitonic point is %d at index %d\n", arr[i], i);
            return 0;
        }
    }

    printf("No bitonic point found\n");
    return 0;
}
output:
Enter number of elements: 5
Enter the bitonic sequence:
2
5
6
8
7
Bitonic point is 8 at index 3


#include <stdio.h>

long long merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;     
    int j = mid + 1;  
    int k = left;      
    long long invCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount += (mid - i + 1);
        }
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return invCount;
}

long long mergeSort(int arr[], int temp[], int left, int right) {
    long long invCount = 0;

    if (left < right) {
        int mid = (left + right) / 2;

        invCount += mergeSort(arr, temp, left, mid);
        invCount += mergeSort(arr, temp, mid + 1, right);
        invCount += merge(arr, temp, left, mid, right);
    }

    return invCount;
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n], temp[n];

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long inversionCount = mergeSort(arr, temp, 0, n - 1);

    printf("Number of inversion pairs = %lld\n", inversionCount);

    return 0;
}

output:

Enter number of elements: 4
Enter array elements:
8
7
9
6
Number of inversion pairs = 4




#include <stdio.h>

struct Item {
    int value;
    int weight;
    float ratio;
};

int main() {
    int n, capacity;
    float maxValue = 0.0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    for (int i = 0; i < n; i++) {
        printf("Enter value and weight of item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                struct Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }

    int remainingCapacity = capacity;

    for (int i = 0; i < n && remainingCapacity > 0; i++) {
        if (items[i].weight <= remainingCapacity) {
            
            maxValue += items[i].value;
            remainingCapacity -= items[i].weight;
        } else {
           
            maxValue += items[i].ratio * remainingCapacity;
            remainingCapacity = 0;
        }
    }

    printf("Maximum value in knapsack = %.2f\n", maxValue);

    return 0;
}


output:

Enter number of items: 5
Enter value and weight of item 1: 6
4
Enter value and weight of item 2: 7
8
Enter value and weight of item 3: 9
7
Enter value and weight of item 4: 2
4
Enter value and weight of item 5: 5
6
Enter knapsack capacity: 6
Maximum value in knapsack = 8.57

