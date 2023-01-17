#ifndef COUNTING_SORT_H
#define COUNTING_SORT_H

#include "../utils/min.h"
#include "../utils/max.h"

void counting_sort ( int *arr, int l, int r ) {
    int min_val = arr[l];
    int max_val = arr[l];
    int len = r - l + 1;
    for ( int i=l; i <= r; i++ ) {
        min_val = min ( min_val, arr[i] );
        max_val = max ( max_val, arr[i] );
    }
    int dif = max_val - min_val + 1;
    int cnt[dif + 1];
    for ( int i = 0; i <= dif; i++ ) cnt[i] = 0;
    for ( int i = l; i<= r; i++ ) {
        int idx = arr[i] - min_val;
        cnt[idx]++;
    }
    int idx=l;
    for( int i = 0; i <= dif; i++ ) {
        while( cnt[i] ){
            arr[idx] = i + min_val;
            cnt[i]--;
            idx++;
        }
    }
}

#endif