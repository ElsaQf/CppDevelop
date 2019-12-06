//冒泡排序
//选择排序
//插入排序
//快速排序
//堆排序 
 

#include <iostream>
using namespace std;

void bubbleSort(int *a, int n){
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - 1 - i; j++){
			if(a[j] > a[j+1]){
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

void selectSort(int *a, int n){
	for(int i = 0; i < n; i++){
		int k = i;
		for(int j = i + 1; j < n; j++){
			if(a[j] < a[k]){
				k = j;
			}
		} 
		if(k != i){
			int temp = a[k];
			a[k] = a[i];
			a[i] = temp;
		}
	}
} 

void insertSort(int *a, int n){
	for(int i = 1; i < n; i++){
		for(int j = i - 1; j >= 0 && a[j+1] < a[j]; j--){
			int temp = a[j];
			a[j] = a[j+1];
			a[j+1] = temp;
		}
	}
}

void quickSort(int left, int right, int a[]){
	if(left >= right){
		return;
	}
	int i, j, base, temp;
	i = left;
	j = right;
	base = a[left];
	while(i < j){
		while(a[j] >= base && i < j){
			j--;
		}
		while(a[i] <= base && i < j){
			i++;
		}
		if(i < j){
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	a[left] = a[i];
	a[i] = base;
	quickSort(left, i-1, a);
	quickSort(j+1, right, a);
} 

void adjust(int *a, int len, int index){
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	
	int maxIdx = index;
	if(left < len && a[left] > a[maxIdx]){
		maxIdx = left;
	}
	if(right < len && a[right] > a[maxIdx]){
		maxIdx = right;
	}
	
	if(maxIdx != index){
		int temp = a[maxIdx];
		a[maxIdx] = a[index];
		a[index] = temp;
		adjust(a, len, maxIdx);
	}
}

void heapSort(int *a, int n){
	for(int i = n/2 - 1; i >= 0; i--){
		adjust(a, n, i);
	}
	for(int i = n - 1; i >= 1; i--){
		int temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		
		adjust(a, i, 0);
	}
}


void printArray(int *a, int n){
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

int main(){
	int a[] = {2,4,1,3};
	
//	bubbleSort(a, 4);
//	selectSort(a, 4);
//	insertSort(a, 4);
//	quickSort(0, 3, a);
	heapSort(a, 4);
	printArray(a, 4);
	
	return 0;
}
