#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<long long> v;

long long binarySearch(long long target, long long max_height) {
    long long left = 0, right = max_height, mid, sum;
    long long answer = 0;

    while (left <= right) {
        sum = 0;
        mid = (left + right) / 2;

        for (long long height : v) {
            if (height > mid)
                sum += height - mid;
        }

        if (sum >= target) {
            answer = mid; 
            left = mid + 1;  
        }
        else {
            right = mid - 1;
        }
    }
    return answer;
}

int main() {
    long long n, m;
    cin >> n >> m;  
    v.resize(n);

    for (long long i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout << binarySearch(m, *max_element(v.begin(), v.end()));
}
