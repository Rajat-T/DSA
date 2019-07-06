#include <bits/stdc++.h>

using namespace std;

int maxsumSubArray(int a[], int size) {
    int max_so_far = INT_MIN, max_ending_here = 0;

    for (int i = 0; i < size; i++) {
        max_ending_here = max_ending_here + a[i];

        if (max_ending_here > max_so_far)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

int main() {

    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};

    cout << maxsumSubArray(a, 8) << endl;

    return 0;

}
