#include <stdio.h>
#include <stdlib.h>

#define N 6

int moda(int * arr, int len) {
    int count = 1;
    int times_now  = 0;
    int times_last = 0;
    int x = 0;

    for (int i = 0; i < len; i++) {
        times_now = 0;
        int n = arr[i];
        for (int j = i; j < len; j++) {
            if (arr[j] == n)
                times_now++;
        }
        if (times_last == times_now)
            count++;
        if (times_now > times_last) {
            times_last = times_now;
            x = arr[i];
        }
    }

    if (count*2 == len || count == len) {
        printf("No moda found\n");
        return -1;
    }
    printf("%d: %d\n", x, times_last);
    return x;
}

int main() {
    int arr[N] = {1,2,3,4,5,6};  //{3, 4, 3, 2, 3, 1, 3, 3};{1, 2, 3, 4}; // {1 ,2 ,2 ,3 ,2};2 3 4
    printf("%d",moda(arr, N));
}