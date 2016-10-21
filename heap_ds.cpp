#include <iostream>
#include <cstdio>
using namespace std;
void max_heapify(int arr[],int i,int n) {
	int left = 2*i;
	int right = 2*i+1;
	int largest = i;
	if (left <= n && arr[largest] < arr[left]) {
		largest = left;
	}
	if (right <= n && arr[largest] < arr[right]) {
		largest = right;
	}
	if (largest != i) {
		swap(arr[i],arr[largest]);
		max_heapify(arr,largest,n);
	}
}
void build_maxheap (int arr[],int n) {
    for(int i = n/2 ; i >= 1 ; i--) {
        max_heapify (arr, i,n) ;
    }
}
void min_heapify (int arr[],int i,int n) {
    int left  = 2*i;
    int right = 2*i+1;
    int smallest = i;
    if (left <= n and arr[left] < arr[ i ]) {
    	smallest = left;
	}
    if (right <= n and arr[right] < arr[smallest]) {
    	smallest = right;
	}
	if (smallest != i) {
        swap (arr[i], arr[smallest]);
        min_heapify (arr, smallest,n);
    }
}
void build_minheap (int arr[],int n) {
    for (int i = n/2 ; i >= 1 ; i--) {
    	min_heapify (arr,i,n);
	}
}
void heap_sort(int arr[],int n) {
    int heap_size = n;
    build_maxheap(arr,n);
    for(int i = n; i >= 2; i-- ) {
        swap (arr[1], arr[i]);
        heap_size = heap_size-1;
        max_heapify(arr,1,heap_size);
    }
}
int main() {
	int n;
	scanf("%d",&n);
	int arr[n+1];
	for (int i = 1; i <= n;i++) {
		cin >> arr[i];
	}
	build_maxheap(arr,n+1);
	return 0;
}
