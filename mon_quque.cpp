#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n;
ll k;

int monotonic_queue(vector<int>& nums, int k) {
    deque<int> d;
    int ans = INT_MAX;
    int n = nums.size();

    for (int i = 0; i < n; i++) {

        while (!d.empty() && nums[i] - nums[d.front()] >= k) {
            ans = min(ans, i - d.front());
            d.pop_front();
        }

        while (!d.empty() && nums[i] <= nums[d.back()]) {
            d.pop_back();
        }

        d.push_back(i);
    }

    return ans == INT_MAX ? -1 : ans;
}


