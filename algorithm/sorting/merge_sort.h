#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "../utils/merge.h"

void merge_sort( int *arr, int l, int r ) {
    if ( l < r ){
        int mid = l + (r - l) / 2;
        merge_sort(arr, l, mid);
        merge_sort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
}

#endif