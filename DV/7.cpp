//Diseñe un algoritmo "divide y vencerás" que permita encontrar la mediana de un 
//vector sin tener que ordenar el vector previamente.
#include <iostream>
#include <vector>

using namespace std;

double findMedian(std::vector<int>& nums) {
    int n = nums.size();
    int left = 0, right = n - 1;
    while (true) {
        int mid = left + (right - left) / 2;
        int i = left, j = right;
        while (i < j) {
            if (nums[i] < nums[right]) {
                i++;
            }
            else {
                swap(nums[i], nums[j - 1]);
                j--;
            }
        }
        swap(nums[j], nums[right]);
        if (j == n / 2) {
            if (n % 2 == 0) {
                return (nums[j] + nums[j - 1]) / 2.0;
            }
            else {
                return nums[j];
            }
        }
        else if (j > n / 2) {
            right = j - 1;
        }
        else {
            left = j + 1;
        }
    }
}

int main() {
    vector<int> nums{ 9, 1, 7, 5, 8, 4, 2, 10, 6 };
    double median = findMedian(nums);
    cout << "La mediana es " << median << endl;
    return 0;
}