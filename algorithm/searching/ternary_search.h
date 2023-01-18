#ifndef TERNARY_SEARCH_H
#define TERNARY_SEARCH_H

int ternary_search(int *arr, int l, int r, int x)
{
    while (l <= r)
    {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        if (arr[m1] == x)
            return m1;
        if (arr[m2] == x)
            return m2;
        if (x < arr[m1])
            r = m1 - 1;
        else if (x > arr[m2])
            l = m2 + 1;
        else
        {
            l = m1 + 1;
            r = m2 - 1;
        }
    }
    return -1;
}

#endif