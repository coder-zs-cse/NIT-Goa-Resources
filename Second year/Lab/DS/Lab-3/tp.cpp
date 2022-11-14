#include <iostream>
#include <vector>
using namespace std;

void flip(vector<int> &arr, int k)
{
    k += 1;
    for (int i = 0; i < k / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[k - i - 1];
        arr[k - i - 1] = temp;
    }
}

vector<int> pancakeSort(vector<int> &input)
{
    // your code goes here
    vector<int> arr = input;
    int end = input.size() - 1;
    while (end > 0)
    {
        int small_index = end;
        for (int i = end; i >= 0; i--)
        {
            if (arr[i] < arr[small_index])
                small_index = i;
        }
        if (small_index != end)
        {
            flip(arr, small_index);
            flip(arr, end);
        }
        end--;
    }
    flip(arr, input.size() - 1);
    return arr;
}

int main()
{

    int n;
    cin >> n;
    vector<int> input(n);
    for (int i = 0; i < n; i++)
        cin >> input[i];
    vector<int> output = pancakeSort(input);
    for (auto it : output)
        cout << it << " ";
    return 0;
}