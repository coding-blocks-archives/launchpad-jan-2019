#include <iostream>
using namespace std;



int main(int argc, char const *argv[])
{
	// 1-d array in c++ using DMA;
	// int *arr = new int[100];
	// for(int i=0;i<100;i++) {
	// 	arr[i] = i;
	// }
	// for(int i=0;i<100;i++) {
	// 	cout<<arr[i];
	// }
	// delete [] arr;

	// 2-d array in C++ DMA
	int **arr2 = new int*[10];
	for(int i=0;i<10;i++) {
		if(i==0) {
			arr2[i] = new int[10];
			continue;
		}
		arr2[i] = new int[4];
	}
	int count=0;
	for(int i=0;i<10;i++) {
		if(i==0) {
			// do something
			for(int j=0;j<10;j++) {
				arr2[i][j] = count;
			}
		} else {
			// do something
			for(int j=0;j<4;j++) {
				arr2[i][j] = count;
			}
		}
		count++;
	}
	for(int i=0;i<10;i++) {
		if(i==0) {
			// do something
			for(int j=0;j<10;j++) {
				cout<<arr2[i][j]<< " ";
			}
		} else {
			// do something
			for(int j=0;j<4;j++) {
				cout<<arr2[i][j]<< " ";
			}
		}
		cout<<"\n";
	}
	// Deallocation
	for(int i=0;i<10;i++) {
		delete [] arr2[i];
	}
	delete [] arr2;
	return 0;
}
