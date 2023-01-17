#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H

int linear_search(int *arr, int l, int r, int key){
    for (int i = l; i <= r; i++){
        if (arr[i] == key)return i;
    }
    return -1;
}

#endif