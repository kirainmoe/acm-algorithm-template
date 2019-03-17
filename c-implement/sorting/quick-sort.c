#include <stdio.h>
#include <string.h>
#define MAXN 1005

int a[MAXN];

typedef int ElementType;

void sort(int left, int right, ElementType arr[]) {
    if (left >= right)
        return;
    
    int i = left, j = right;
    ElementType key = arr[i];
    
    while (i < j) {
        while (arr[j] >= key && i < j)
            j--;
        arr[i] = arr[j];
        while (arr[i] <= key && i < j)
            i++;
        arr[j] = arr[i];
    }
    
    arr[i] = key;
    sort(left, i - 1, arr);
    sort(i + 1, right, arr);
}

int main() {
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    sort(0, n - 1, a);
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}
