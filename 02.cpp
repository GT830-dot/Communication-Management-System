#include<iostream>
#include<string>
using namespace std;
struct student {
	string name;
	int age;
	int score;
};
struct teacher {
	int id;
	string name;
	int age;
	struct student stu;
};

int main() {
	teacher t;
	t.id = 10000;
	t.name = "mary";
	t.age = 50;
	t.stu.name = "tom";
	t.stu.age = 20;
	t.stu.score = 60;
	


	return 0;
}