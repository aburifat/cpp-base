#ifndef MERGE_H
#define MERGE_H

void merge ( int *arr, int l, int mid, int r ) {
    int len_left = mid - l + 1;
    int len_right = r - mid;
    auto left = new int[len_left];
    auto right = new int[len_right];
    for ( int i = 0; i < len_left; i++ ) left[i] = arr[l + i];
    for ( int i = 0; i <len_right; i++ ) right[i] = arr[mid + i + 1];
    int idx_left = 0, idx_right = 0, idx_arr = l;
    while ( idx_left < len_left && idx_right < len_right ) {
        if ( left[idx_left] <= right[idx_right] ) {
            arr[idx_arr] = left[idx_left];
            idx_left++;
        }
        else{
            arr[idx_arr] = right[idx_right];
            idx_right++;
        }
        idx_arr++;
    }
    while ( idx_left < len_left ) {
        arr[idx_arr] = left[idx_left];
        idx_left++;
        idx_arr++;
    }
    while ( idx_right < len_right ) {
        arr[idx_arr] = right[idx_right];
        idx_right++;
        idx_arr++;
    }
    delete[] left;
    delete[] right;
}

#endif