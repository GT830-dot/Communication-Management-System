#include<iostream>
using namespace std;
int main() {
	int arr[5] = { 0,1,2,3,4 };
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	int a, b;
	a = 0;
	b = sizeof(arr) / sizeof(arr[0]) - 1;
	while (a < b) {
		int temp = 0;
		temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;
		a++;
		b--;
	}
	for (int e = 0; e < 5; e++) {
		cout << arr[e] << " ";
	}



	return 0;
}