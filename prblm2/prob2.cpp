#include <iostream>
using namespace std;

int merge(int* arr, int low, int mid, int high){
	int* arr1 = new int[mid - low + 1];
	int* arr2 = new int[high-mid];
	int* arr3 = new int[high - low + 1];
	for(int i = 0; i < mid - low + 1; i++){
		arr1[i] = arr[low + i];
	}
	for(int i = 0; i <= high-mid; i++){
		arr2[i] = arr[mid + i + 1];
	}
	int i = 0; 
	int j = 0;
	int leftlen = mid - low + 1;
	int rightlen = high - mid;
	int k = 0;
	int inv_count = 0;
	while(i < leftlen && j < rightlen){
		if(arr1[i] < arr2[j]){
			arr3[k] = arr1[i];
			i++;
		}else{
			arr3[k] = arr2[j];
			inv_count += (mid - i);
			j++;
		}
		k++;
	}
	while(i < leftlen){
		arr3[k] = arr1[i];
		k++;
		i++;
	}
	while(j < rightlen){
		arr3[k] = arr2[j];
		j++;
		k++;
	}
	for(int f = 0; f < k; f++){
		arr[low+f] = arr3[f];
	}
	cout << "Inversion count : " << inv_count << endl;
	return inv_count;
}

void mergeSort(int* arr, int low, int high){
	if(low >= high){
		return;
	}
	int mid = (low+high)/2;
	mergeSort(arr, low, mid);
	mergeSort(arr, mid+1, high);
	merge(arr, low, mid, high);
	for(int  i = low; i < high; i++){
		cout << arr[i] << ", ";
	}
	cout << endl;
}

int main(){
	int n;
	cout << "Enter the number of elements: ";
	cin >> n;
	int* arr = new int[n];
	for(int i = 0; i < n; i++){
		cout << "[" << i << "]: "; 
		cin >> arr[i];
	}
	mergeSort(arr, 0, n);
	return 0;
}
