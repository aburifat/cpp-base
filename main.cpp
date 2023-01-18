#include <iostream>
using namespace std;

// include custom cpp files start
#include "algorithm/searching/ternary_search.h"

// include custom cpp files end

int main()
{
    int arr[] = {1, 2, 2, 2, 2, 3, 5, 5};
    int idx = ternary_search(arr, 0, 7, 5);
    cout << idx << endl;
    return 0;
}