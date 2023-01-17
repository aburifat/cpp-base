#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

void insertion_sort( int *arr, int l, int r ) {
    for ( int i = l; i <= r ; i++ ) {
        int key = arr[i];
        int j = i-1;
        while( j >= l && arr[j] > key ) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

#endif