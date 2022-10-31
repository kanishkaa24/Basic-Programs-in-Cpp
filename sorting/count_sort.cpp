// Counting sort which takes negative numbers as well
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void countSortUse(vector<int>& arr)
{
	int max = *max_element(arr.begin(), arr.end());
	int min = *min_element(arr.begin(), arr.end());
	int range = max - min + 1;

	vector<int> countervector(range), output(arr.size());
	for (int i = 0; i < arr.size(); i++)
		countervector[arr[i] - min]++;

	for (int i = 1; i < countervector.size(); i++)
		countervector[i] += countervector[i - 1];

	for (int i = arr.size() - 1; i >= 0; i--) {
		output[countervector[arr[i] - min] - 1] = arr[i];
		countervector[arr[i] - min]--;
	}

	for (int i = 0; i < arr.size(); i++)
		arr[i] = output[i];
}

void printArray(vector<int>& arr)
{
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << "\n";
}

int main()
{
	vector<int> arr = { -5, -10, 0, -3, 8, 5, -1, 10 };
	countSortUse(arr);
	printArray(arr);
	return 0;
}
