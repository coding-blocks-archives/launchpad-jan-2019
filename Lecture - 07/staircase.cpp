#include <iostream>
using namespace std;

bool staircaseSearch(int mat[][4], int key) {
	int row = 0, col = 3;
	while(row<4 and col>=0) {
		if(mat[row][col] == key) {
			cout<<row<<" "<<col<<endl;
			return true;
		} else if(key < mat[row][col]) {
			col--;
		} else {
			row++;
		}
	}
	cout<<"Not found";
	return false;
}


int main(int argc, char const *argv[])
{
	/* code */

	int arr[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	cout<<staircaseSearch(arr, 14);
	return 0;
}
