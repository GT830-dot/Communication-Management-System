#include<iostream>
#include<string>
#define MAX 1000

using namespace std;

//联系人结构体
struct Person {
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};


//通讯录结构体
struct Addressbooks {
	struct Person personArray[MAX];
	int m_Size;
};
//显示菜单
void showManu() {
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;


}
//添加联系人
void addPerson(Addressbooks* abs) {
	if (abs->m_Size == MAX) {
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else {
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		cout << "请输入性别：" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
				cout << "输入有误，请重新输入" << endl;
			}
		}
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		cout << "请输入联系电话:" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		cout << "请输入住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;
		abs->m_Size++;
		cout << "添加成功" << endl;
		system("pause");//请按任意键继续
		system("cls");//清屏
	}

}
//显示所有的联系人
void showPerson(Addressbooks* abs) {
	//判断通讯录中人数是否为0
	if (abs->m_Size == 0) {
		cout << "当前无联系人" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "姓名：" << abs->personArray[i].m_Name << " ";
			cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << " ";
			cout << "年龄：" << abs->personArray[i].m_Age << " ";
			cout << "电话：" << abs->personArray[i].m_Phone << " ";
			cout << "住址：" << abs->personArray[i].m_Addr << endl;

		}

	}
	system("pause");
	system("cls");
}
/*删除联系人*/
//检测联系人是否存在
int isExist(Addressbooks* abs, string name) {
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_Name == name) {
			return i;
		}
	}
	return -1;
}
//删除指定联系人
void deletePerson(Addressbooks* abs) {
	cout << "请输入要删除的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1) {
		cout << "查无此人！" << endl;
	}
	else {
		for (int i = ret; i < abs->m_Size-1; i++) {
			//数据迁移，删除位之后的每个数据向前移动一位
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
	}
	system("pause");
	system("cls");
}
//查找联系人
void findPerson(Addressbooks* abs) {
	cout << "请输入要查找的联系人：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1) {
		cout << "查无此人！" << endl;
	}
	else {
		cout << "姓名：" << abs->personArray[ret].m_Name << " ";
		cout << "性别：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << " ";
		cout << "年龄：" << abs->personArray[ret].m_Age << " ";
		cout << "电话：" << abs->personArray[ret].m_Phone << " ";
		cout << "住址：" << abs->personArray[ret].m_Addr << endl;

	}
	system("pause");
	system("cls");
}
//修改联系人
void modifyPerson(Addressbooks* abs) {
	cout << "请输入要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1) {
		cout << "查无此人" << endl;
	}
	else {
		cout << "请输入新的姓名：" << endl;
		string newName;
		cin >> newName;
		abs->personArray[ret].m_Name = newName;
		cout << "请输入新的性别：" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int newSex;
		while (true) {
			cin >> newSex;
			if (newSex == 1 || newSex == 2) {
				abs->personArray[ret].m_Sex = newSex;
				break;
			}
			else {
				cout << "输入有误，请重新输入" << endl;

			}
		}
		cout << "请输入新的年龄" << endl;
		int newAge;
		cin >> newAge;
		abs->personArray[ret].m_Age = newAge;
		cout << "请输入新的电话" << endl;
		string newPhone;
		cin >> newPhone;
		abs->personArray[ret].m_Phone = newPhone;
		cout << "请输入新的住址：" << endl;
		string newAddr;
		cin >> newAddr;
		abs->personArray[ret].m_Addr = newAddr;
		cout << "修改成功!" << endl;
	}
	system("pause");
	system("cls");
}
//重置通讯录
void cleanPerson(Addressbooks* abs) {
	cout << "您确定要重置吗？" << endl;
	cout << "1---确定" << endl;
	cout << "2---放弃重置" << endl;
	int ensure;
	while (true) {
		cin >> ensure;
		if (ensure == 1 || ensure == 2) {
			if (ensure == 1) {
				abs->m_Size = 0;
				cout << "通讯录已清空！" << endl;
				break;
			}
			else {
				cout << "已放弃清空！" << endl;
				break;
			}
		}
		else {
			cout << "输入错误，请重新输入！" << endl;
		}
	}
	system("pause");
	system("cls");
}




int main() {
	Addressbooks abs;
	abs.m_Size = 0;
	int select = 0;
	while (true) {
		showManu();
		cin >> select;
		switch (select) {
		case 1:  //添加联系人
		{
			addPerson(&abs);
			break;
		}
		case 2:  //显示联系人
		{
			showPerson(&abs);
			break;
		}
		case 3: {      //删除联系人
			deletePerson(&abs);
			break;
		}
		case 4:       //查找联系人
		{
			findPerson(&abs);
			break;
		}
		case 5:        //修改联系人
			modifyPerson(&abs);
			break;
		case 6:        //清空联系人
			cleanPerson(&abs);
			break;
		case 0:        //退出通讯录
			cout << "欢迎下次使用!" << endl;
			return 0;
			break;

		default:cout << "输入错误" << endl;
		}

	}



	return 0;
}