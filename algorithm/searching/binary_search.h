#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

int binary_search(int *arr, int l, int r, int x)
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (arr[m] == x)
            return m;
        else if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int lower_bound(int *arr, int l, int r, int x)
{
    while (l < r)
    {
        int m = l + (r - l) / 2;
        if (arr[m] >= x)
            r = m;
        else
            l = m + 1;
    }
    return l;
}

int upper_bound(int *arr, int l, int r, int x)
{
    while (l < r)
    {
        int m = l + (r - l) / 2;
        if (arr[m] <= x)
            l = m + 1;
        else
            r = m;
    }
    return l;
}

#endif