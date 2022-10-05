#include <stdio.h>
#include <stdlib.h>

void qqsort(int *, int, int);
void swap(int *, int, int)

int main(){
    int arr[] = {1,4,7,6,2,3,9,8,5};
    qqsort(&arr[0], 0, 8);
    for(int i = 0; i < 9; i++){
        printf("%d ", arr[i]);
    }
}

void qqsort(int *arr, int left, int right){

    if(left+1 >= right)
        return;

    int wall = left;
    for(int i = left; i < right; i++)
        if(arr[i] < arr[right])
            swap(arr, wall++, i);
    
    swap(arr, wall, right);
    qqsort(arr, left, wall - 1);
    qqsort(arr, wall + 1, right);
}

void swap(int *arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
