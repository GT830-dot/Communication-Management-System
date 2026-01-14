#include<iostream>
using namespace std;
void num(int* p, int b);
int main() {
	int arr[9] = { 4,5,6,1,2,3,8,9,0 };
	cout << "排序前" << endl;
	for (int a = 0; a < 9; a++) {
		cout << arr[a] << " ";
	}
	cout << "排序后" << endl;
	int c = sizeof(arr) / sizeof(arr[0]);
	num(arr, c);
	for (int e = 0; e < 9; e++) {
		cout << arr[e] << " ";
	}
    return 0;
}
void num(int* p, int b) {
	for (int i = 0; i < b - 1; i++) {
		for (int j = 0; j < b - i - 1; j++) {
			if (p[j] > p[j + 1]) {
				int temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
}

