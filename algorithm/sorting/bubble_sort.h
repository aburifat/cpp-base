#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

void bubble_sort( int *arr, int l, int r ) {
    for ( int i = l; i <= r; i++ ) {
        for ( int j = i + 1; j <= r; j++ ) {
            if ( arr[i] > arr[j] ) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

#endif