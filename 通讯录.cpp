#include<iostream>
#include<string>
using namespace std;
#define MAX 1000 //最大人数

//联系人结构体
struct Person
{
	string m_name; string m_phone;
	string m_addr;
	string  m_emai;
	int m_qq;
	int m_youbian;
};

//通讯录结构体
struct Addressbooks
{
	struct Person personArray[MAX]; //通讯录中保存的联系人数组
	int m_Size; //通讯录中人员个数
};

//添加联系人
void addPerson(Addressbooks* abs)
{
	//判断联系人是否满了
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else
	{
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_name = name;
		cout << "EMAI：" << endl;
		string emai;
		cin >> emai;
		abs->personArray[abs->m_Size].m_emai = emai;
		cout << "请输入QQ：" << endl;
		int qq = 0;
		cin >> qq;
		abs->personArray[abs->m_Size].m_qq = qq;
		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_phone = phone;
		cout << "请输入邮编：" << endl;
		int youbian;
		cin >> youbian;
		abs->personArray[abs->m_Size].m_youbian = youbian;
		cout << "请输入住址：" << endl;
		string addr;
		cin >> addr;
		abs->personArray[abs->m_Size].m_addr = addr;

		abs->m_Size++;//更新通讯录人数
		cout << "添加成功：" << endl;

	}
}

//显示联系人
void showPerson(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "暂时没有联系人" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_name << "\t";
			cout << "EMAI：" << (abs->personArray[i].m_emai) << "\t";
			cout << "QQ号：" << abs->personArray[i].m_qq << "\t";
			cout << "电话：" << abs->personArray[i].m_phone << "\t";
			cout << "邮编：" << abs->personArray[i].m_youbian << "\t";
			cout << "住址：" << abs->personArray[i].m_addr << endl;
		}
	}



}

//判断是否存在查询的人员，存在返回在数组中索引位置，不存在返回-1
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_name == name)
		{
			return i;
		}
	}
	return -1;
}

//删除联系人
void deletePerson(Addressbooks* abs)
{
	cout << "请输入您要删除的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i++];
		}
		abs->m_Size--;
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}



}

//查找联系人
void findPerson(Addressbooks* abs)
{
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->personArray[ret].m_name << "\t";
		cout << "EMAI：" << abs->personArray[ret].m_emai << "\t";
		cout << "QQ号：" << abs->personArray[ret].m_qq << "\t";
		cout << "电话：" << abs->personArray[ret].m_phone << "\t";
		cout << "邮编：" << abs->personArray[ret].m_youbian << "\t";

		cout << "住址：" << abs->personArray[ret].m_addr << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}


}

//修改联系人
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入你要修改的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "请输入姓名：" << endl;
		string name;
		cin >> name;
		abs->personArray[ret].m_name = name;

		cout << "请输入EMAI：" << endl;

		string emai;
		cin >> emai;
		abs->personArray[ret].m_emai = emai;


		cout << "请输入QQ：" << endl;
		int qq;
		cin >> qq;
		abs->personArray[ret].m_qq = qq;

		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_phone = phone;

		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_addr = address;

		cout << "修改成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}


}



//菜单界面
void showMenu()
{
	cout << "         请选择操作" << endl;
	cout << "-------------------------------" << endl;

	cout << "       1、添加联系人  " << endl;
	cout << "       2、显示所有联系人  " << endl;
	cout << "       3、删除联系人  " << endl;
	cout << "       4、查询联系人  " << endl;
	cout << "       5、修改联系人  " << endl;
	cout << "       0、退出通讯录  " << endl;
	cout << "                         " << endl;
}

int main()
{
	int select = 0;

	//创建通讯录
	Addressbooks abs;
	//初始化通讯录中的人数
	abs.m_Size = 0;

	while (true)
	{
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1: //添加联系人
			addPerson(&abs);
			break;
		case 2: //显示联系人
			showPerson(&abs);
			break;
		case 3: //删除联系人
			deletePerson(&abs);
			break;
		case 4: //查找联系人
			findPerson(&abs);
			break;
		case 5: //修改联系人
			modifyPerson(&abs);
			break;


		case 0: //退出通讯录
			cout << "欢迎下次使用" << endl;

			return 0;
			break;
		default:
			break;
		}
	}


	return 0;
}

