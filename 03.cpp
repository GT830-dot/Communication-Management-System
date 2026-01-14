#include<iostream>
#include<string>
using namespace std;
struct student {
	string name;
	int age;
	int score;
};
int main() {
	student s = { "tom",10,65 };
	student* p = &s;
	cout << p->name << endl;



	return 0;
}