#include<algorithm>
#include<deque>
#include<cstring>
#include<set>
#include<stack>
#include <iostream>
#include <string>
#include<cctype>
#include<iomanip>
#include<vector>
#include<cmath>
#include<array>
using namespace std;

vector<int> nums;
void merge(int l, int m, int r)
{
    int A[1000];
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r) {
        if (nums[i] < nums[j])
            A[k++] = nums[i++];
        else
            A[k++] = nums[j++];
    }
    while (i <= m)
        A[k++] = nums[i++];
    while (j <= r)
        A[k++] = nums[j++];
    for (int p = l; p <= r; p++)
        nums[p] = A[p];
}
void Sortby(int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        Sortby(l, m);
        Sortby(m + 1, r);
        merge(l, m, r);

    }
}


int main()
{
    int x;
    while (1) {
        cin >> x;
        if (x == 0)    break;//读入0代表结束
        nums.push_back(x);
    }
    int k = nums.size() - 1;
    Sortby(0, k);

    for (int i = 0; i <= k; i++)
        cout << nums[i] << "  ";
}