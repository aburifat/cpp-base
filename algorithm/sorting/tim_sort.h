#ifndef TIM_SORT_H
#define TIM_SORT_H

#include "../utils/min.h"
#include "../utils/merge.h"
#include "insertion_sort.h"

void tim_sort ( int *arr, int l, int r ) {
    int run = 32;
    int len = r - l + 1;
    for ( int i = l; i <= r; i += run ){
        insertion_sort( arr, i, min ( i + run - 1, r ) );
    }
    for ( int siz = run; siz < len; siz = 2 * siz ){
        for ( int left = l; left <= r; left += 2 * siz ) {
            int mid = left + siz - 1;
            int right = min ( left + 2 * siz - 1, r );
            if ( mid < right ){
                merge ( arr, left, mid, right );
            }
        }
    }
}

#endif