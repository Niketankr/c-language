//01
#include <stdio.h>
//03
int add(int *a, int *b) {
    return *a + *b;
}
//07
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
//13
int main(void) {
    int a = 10;
    int b = 20;
    int *pa = &a;
    int *pb = &b;
    printf("a=%d b=%d\n", a, b);
    printf("*pa=%d *pb=%d\n", *pa, *pb);
    printf("pa=%p pb=%p\n", (void*)pa, (void*)pb);
    int sum = add(pa, pb);
    printf("sum=%d\n", sum);
    swap(pa, pb);
    printf("after swap a=%d b=%d\n", a, b);
    int arr[5] = {1,2,3,4,5};
    int *p = arr;
    printf("array via pointers:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(p + i));
    }
    printf("\n");
    int **ppa = &pa;
    printf("**ppa=%d\n", **ppa);
    const int c = 30;
    const int *pc = &c;
    printf("const value=%d\n", *pc);
    int d = 40;
    int * const pd = &d;
    *pd = 50;
    printf("d=%d\n", d);
    char str[] = "hello";
    char *ps = str;
    while (*ps) {
        putchar(*ps);
        ps++;
    }
    putchar('\n');
    int matrix[2][3] = {{1,2,3},{4,5,6}};
    int (*pm)[3] = matrix;
    printf("%d\n", pm[1][2]);
    void *vp = pa;
    printf("void*=%p\n", vp);
    int x = 5;
    int y = 7;
    int *px = &x;
    int *py = &y;
    if (px < py) {
        printf("px < py (address compare)\n");
    }
    size_t size = sizeof(arr) / sizeof(arr[0]);
    printf("size=%zu\n", size);
    int values[3] = {9,8,7};
    int *pv = values;
    *(pv + 1) = 88;
    printf("%d\n", values[1]);
    int n = 3;
    int nums[3] = {1,1,1};
    int *pn = nums;
    for (int i = 0; i < n; i++) {
        pn[i] += i;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    int e = 100;
    int *pe = &e;
    printf("%d\n", *pe);
    *pe += 23;
    printf("%d\n", e);
    int f = 0;
    int *pf = NULL;
    if (pf == NULL) {
        pf = &f;
    }
    *pf = 11;
    printf("%d\n", f);
    int g = 2;
    int h = 3;
    int *pg = &g;
    int *ph = &h;
    int result = (*pg) * (*ph);
    printf("%d\n", result);
    return 0;
}
//97
//98
//99
//100
a=10 b=20
*pa=10 *pb=20
pa=0x7ffd1ce7b0e0 pb=0x7ffd1ce7b0dc
sum=30
after swap a=20 b=10
array via pointers:
1 2 3 4 5 
**ppa=20
const value=30
d=50
hello
6
void*=0x7ffd1ce7b0e0
size=5
88
1 2 3 
100
123
11
6
