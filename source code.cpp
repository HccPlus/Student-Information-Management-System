#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

void InputNum(int& x);

void InputNum(long long& x);

void InputNum(int& x, int min, int max);

class Student
{
private:
	char* name = new char[8];//姓名 
	char gender;//性别（M：男，F：女，U：未知） 
	long long number;//学号 
	char* ClassAndGrade = new char[16];//班级
	int birthday;

	//学生信息修改函数：
	void ChangeName()
	{
		char* i = new char[8];
		cout << "请输入学生姓名：" << endl;
		cin >> i;
		while (getchar() != '\n');//清空缓冲区，防止用户误输入 
		strcpy_s(name, 8, i);
		delete[] i;
	}
	void ChangeGender()
	{
		char j;
		char* gd = new char[2];//用来临时存储“男”、“女”字符 
		bool ck = false;//用于判断程序是否执行过 
		bool b = true;//判断输入是否正确 
		cout << "请输入学生性别：" << endl;
		do
		{
			b = true;
			if (ck) cout << "输入有误，请重新输入：" << endl;
			cin >> gd;
			while (getchar() != '\n');
			if (strcmp(gd, "M") == 0) j = 'M';
			else if (strcmp(gd, "F") == 0) j = 'F';
			else if (strcmp(gd, "男") == 0) j = 'M';
			else if (strcmp(gd, "女") == 0) j = 'F';
			else b = false;
			ck = true;
		} while (!b);
		gender = j;
	}
	void ChangeNumber()
	{
		long long k = 0;
		bool ck = false;
		cout << "请输入学生学号：" << endl;
		do
		{
			if (ck) cout << "输入有误，请重新输入：" << endl;
			InputNum(k);
			while (getchar() != '\n');
			ck = true;
		} while (k < 1000 || k>922337203685477580);
		number = k;
	}
	void ChangeClassAndGrade()
	{
		char* l = new char[16];
		cout << "请输入学生班级：" << endl;
		cin >> l;
		while (getchar() != '\n');
		strcpy_s(ClassAndGrade, 16, l);
		delete[] l;
	}
	void ChangeDetail()
	{
		cout << "可以输入学生生日信息：" << endl;
		ChangeBirthday();
	}
	void ChangeBirthday()
	{
		int year, month, day;
		cout << "请输入出生年份：" << endl;
		InputNum(year, 1000, 9999);
		cout << "请输入出生月份：" << endl;
		InputNum(month, 1, 12);
		cout << "请输入出生日期：" << endl;
		InputNum(day, 1, 31);
		birthday = 10000 * year + 100 * month + day;
	}

public:

	static int sum;//学生总量 
	static bool detail;//详细显示模式

	Student(const char* i, char j = 'U', long long k = 0, const char* l = "未知", int m = 0)//学生类构造函数 
	{
		strcpy_s(name, 8, i);
		gender = j;
		number = k;
		strcpy_s(ClassAndGrade, 16, l);
		birthday = m;
		sum++;
		//cout << "*学生添加成功" << endl;
	}
	Student()//无参数的学生类构造函数 
	{
		strcpy_s(name, 8, "未知");
		gender = 'U';
		number = 0;
		strcpy_s(ClassAndGrade, 16, "未知");
		birthday = 0;
		sum++;
		//cout << "*学生添加成功（未输入信息）" << endl;
	}

	long long ReturnNumber()//用于返回学生学号 
	{
		return number;
	}

	const char* ReturnName()
	{
		return name;
	}

	bool ChangeData()//修改学生信息的函数 
	{
		char c = ' ';//用于判断用户想要修改的数据 
		bool ck = false;
		bool change = false;
		cout << endl;
		cout << "请输入要写入的数据：";
		cout << "（A：全部基本数据，N：姓名，G：性别，B：学号，C：班级，D：详细信息）" << endl;
		do
		{
			if (ck) cout << "输入有误，请重新输入：" << endl;
			cin >> c;
			while (getchar() != '\n');
			ck = true;
		} while (c != 'N' && c != 'G' && c != 'B' && c != 'C' && c != 'A' && c != 'L' && c != 'D');
		//修改学生信息： 
		if (c == 'N' || c == 'A') ChangeName();
		if (c == 'G' || c == 'A') ChangeGender();
		if (c == 'B' || c == 'A') ChangeNumber();
		if (c == 'C' || c == 'A') ChangeClassAndGrade();
		if (c == 'D') ChangeDetail();
		else
		{
			change = true;
			cout << "写入完成！" << endl;
		}
		cout << endl;
		return change;
	}

	void ViewData()//显示单个学生信息的函数 
	{
		cout << endl;
		cout << "学生姓名：\t";
		cout << name << endl;
		cout << "学生性别：\t";
		if (gender == 'M') cout << "男" << endl;
		else if (gender == 'F') cout << "女" << endl;
		else cout << "未知" << endl;
		cout << "学生学号：\t";
		cout << number << endl;
		cout << "学生班级：\t";
		if (strlen(ClassAndGrade) <= 2)
		{
			cout << ClassAndGrade << "班" << endl;
		}
		else
		{
			cout << ClassAndGrade << endl;
		}
		if (detail)
		{
			if (birthday == 0) cout << "学生生日：\t未知" << endl;
			else
			{
				int year, month, day;
				year = birthday / 10000;
				month = (birthday - 10000 * year) / 100;
				day = birthday - 10000 * year - 100 * month;
				cout << "学生生日：\t";
				cout << year << "年" << month << "月" << day << "日" << endl;
			}

		}
		cout << endl;
	}

	void SaveInformation()
	{
		ofstream outfile;
		outfile.open("Information.dat", ios::app);
		outfile << "Data" << endl;
		outfile << name << endl;
		outfile << gender << endl;
		outfile << number << endl;
		outfile << ClassAndGrade << endl;
		outfile << birthday << endl;
		outfile.close();
	}

	~Student()//学生类析构函数 
	{
		sum--;
		//cout << "学生类已删除！" << endl;
	}
};

struct library//存储学生信息的库链表
{
	Student s;//学生类
	library* next = NULL;//指向下一个学生结点的指针
};

library* LHead = NULL;//学生信息库链表的头指针

int Student::sum = 0;
bool Student::detail = false;

void ViewAllData();//显示所有学生信息的函数 

void AddStudent();//添加学生的函数

library* SearchStudent();//搜索学生的函数

void DidNotFound();

void DeleteStudent();//删除学生的函数

void AutoDeleteStudent(library* s);

void ModStudent();

void LookStudent();

void SumStudent();

void DeleteAll();

void Set();

void ReadSet();

void Save();

void Read(bool IsAuto);

int main()
{
	char c = ' ';//用于判断用户想要进行的操作 
	cout << "欢迎使用Voyage学生信息管理系统！" << endl << endl;
	Read(true);
	ReadSet();
	do
	{
		cout << endl;
		bool ck = false;
		cout << "您想进行什么操作？" << endl;;
		cout << "（A：添加学生  D：删除学生  M：修改学生信息";
		cout << "  L：查看单个学生信息  V：显示所有学生信息  S：查看学生总数";
		cout << "  T：设置  E：保存  R：读档  C：关闭程序）" << endl;
		do
		{
			if (ck) cout << "输入有误，请重新输入：" << endl;
			cin >> c;
			while (getchar() != '\n');
			ck = true;
		} while (c != 'A' && c != 'D' && c != 'M' && c != 'L' && c != 'V' && c != 'S' && c != 'C' && c != 'T' && c != 'E' && c != 'R');
		if (c == 'A') AddStudent();
		else if (c == 'D') DeleteStudent();
		else if (c == 'M') ModStudent();
		else if (c == 'L') LookStudent();
		else if (c == 'V') ViewAllData();
		else if (c == 'S') SumStudent();
		else if (c == 'T') Set();
		else if (c == 'E') Save();
		else if (c == 'R') Read(false);
		else if (c == 'C')
		{
			char close = ' ';
			bool ck = false;
			cout << "确认关闭吗？" << endl;
			cout << "（Y：确认关闭，N：手滑了，取消关闭）" << endl;
			do
			{
				if (ck) cout << "输入有误，请重新输入：" << endl;
				cin >> close;
				while (getchar() != '\n');
				ck = true;
			} while (close != 'Y' && close != 'N');
			if (close == 'N') c = ' ';
			cout << endl;
		}
	} while (c != 'C');
	Save();
	DeleteAll();
	cout << "程序已关闭。" << endl;
	return 0;
}

void InputNum(int& x)
{
	bool suc = true;//定义变量记录输入是否成功
	do
	{
		if (!suc) cout << "输入错误！请重新输入：" << endl;
		cin >> x;
		suc = !cin.fail();
		if (!suc)
		{
			cin.clear();
			cin.get();
		}
	} while (!suc);
}

void InputNum(long long& x)
{
	bool suc = true;//定义变量记录输入是否成功
	do
	{
		if (!suc) cout << "输入错误！请重新输入：" << endl;
		cin >> x;
		suc = !cin.fail();
		if (!suc)
		{
			cin.clear();
			cin.get();
		}
	} while (!suc);
}

void InputNum(int& x, int min, int max)
{
	bool suc = true;//定义变量记录输入是否成功
	bool again = false;//定义变量判断循环是否已经执行过
	do
	{
		if (again) cout << "输入错误！请重新输入：" << endl;
		again = true;
		cin >> x;
		suc = !cin.fail();
		if (!suc)
		{
			cin.clear();
			cin.get();
		}
	} while (!suc && x >= min && x <= max);
}

void ViewAllData()
{
	cout << endl;
	library* s = LHead;
	if (Student::sum == 0)
	{
		cout << "您的系统中目前没有学生！" << endl;
		return;
	}
	while (s)
	{
		s->s.ViewData();
		s = s->next;
	}
	cout << endl;
}

void AddStudent()
{
	cout << endl;
	library* s = new library;
	s->s.ChangeData();
	s->next = LHead;
	LHead = s;
	cout << endl;
}

library* SearchStudent()
{
	char c = ' ';//用于选择用户的搜索方式 
	bool b = false;
	library* p = LHead;
	cout << endl;
	if (Student::sum == 0)
	{
		cout << "您的系统中目前没有学生！" << endl;
		return NULL;
	}
	do
	{
		if (b) cout << "输入有误，请重新输入：" << endl;
		cout << "您想通过什么数据来搜索学生？";
		cout << "（N：姓名，B：学号）" << endl;
		cin >> c;
		while (getchar() != '\n');
		if (c == 'N')
		{
			bool suc = false;
			char* name = new char[8];
			cout << "请输入学生姓名：" << endl;
			cin >> name;
			while (getchar() != '\n');
			while (p)//遍历所有对象
			{
				if (strcmp(p->s.ReturnName(), name))
				{
					p = p->next;
					continue;//比较姓名是否相同
				}
				else
				{
					suc = true;
					break;
				}
			}
			if (!suc)
			{
				p = NULL;
				cout << "没有搜索到该学生！" << endl;
			}
			delete[] name;
		}
		else if (c == 'B')
		{
			long long m0;
			bool suc = false;
			cout << "请输入学生学号：" << endl;
			cin >> m0;
			while (getchar() != '\n');
			while (p)//遍历所有对象 
			{
				if (m0 == p->s.ReturnNumber())
				{
					suc = true;
					break;
				}
				else
				{
					p = p->next;
				}
			}
			if (!suc)
			{
				p = NULL;
				cout << "没有搜索到该学生！" << endl;
			}
		}
		b = true;
	} while (c != 'N' && c != 'B');
	cout << endl;
	return p;
}

void DidNotFound()
{
	cout << "没有找到该学生！" << endl;
}

void DeleteStudent()
{
	cout << endl;
	char c = ' ';
	bool ck = false;
	library* s = SearchStudent();
	if (s == NULL) return;
	s->s.ViewData();
	cout << "确认删除吗？";
	cout << "（Y：确认，N：取消）" << endl;
	do
	{
		if (ck) cout << "输入有误，请重新输入：" << endl;
		cin >> c;
		while (getchar() != '\n');
		ck = true;
	} while (c != 'Y' && c != 'N');
	if (c == 'Y')
	{
		library* p = LHead;
		if (Student::sum == 1)
		{
			delete p;
			cout << "该学生已删除！" << endl;
		}
		else if (p == s)
		{
			LHead = p->next;
			delete p;
			cout << "该学生已删除！" << endl;
		}
		else
		{
			while (p->next != s)
			{
				p = p->next;
			}
			p->next = s->next;
			delete s;
			cout << "该学生已删除！" << endl;
		}
	}
	else cout << "已取消" << endl;
	cout << endl;
}

void AutoDeleteStudent(library* s)
{
	library* p = LHead;
	if (Student::sum == 1)
	{
		delete p;
		cout << "该学生已删除！" << endl;
	}
	else if (p == s)
	{
		LHead = p->next;
		delete p;
		cout << "该学生已删除！" << endl;
	}
	/*else
	{
		while (p->next != s)
		{
			p = p->next;
		}
		p->next = s->next;
		delete s;
		cout << "该学生已删除！" << endl;
	}*/
}

void ModStudent()
{
	cout << endl;
	library* s = SearchStudent();
	char c = ' ';
	bool ck = false;
	bool change;
	if (s == NULL)
	{
		cout << endl;
		return;
	}
	s->s.ViewData();
	cout << "确认修改吗？";
	cout << "（Y：确认，N：取消）" << endl;
	do
	{
		if (ck) cout << "输入有误，请重新输入：" << endl;
		cin >> c;
		while (getchar() != '\n');
		ck = true;
	} while (c != 'Y' && c != 'N');
	if (c == 'Y')
	{
		change = s->s.ChangeData();
		if (change) cout << "修改完成！" << endl;
	}
	else cout << "已取消" << endl;
	cout << endl;
}

void LookStudent()
{
	cout << endl;
	library* s = SearchStudent();
	if (s == NULL)
	{
		cout << endl;
	}
	else
	{
		s->s.ViewData();
		cout << endl;
	}
}

void SumStudent()
{
	cout << endl;
	cout << "学生总数为：";
	cout << Student::sum << endl;
	cout << endl;
}

void DeleteAll()
{
	/*
	library* p = LHead;
	while (LHead)
	{
		p = LHead;
		
		library* q = p->next;
		AutoDeleteStudent(p);
		while (q)
		{
			p = q;
			q = q->next;
			AutoDeleteStudent(p);
		}
	}*/
	LHead = NULL;
	Student::sum = 0;
}

void Set()
{
	cout << endl;
	char c = ' ';
	char set = ' ';
	bool b = false;
	bool again = false;
	cout << "请选择修改的设置项：" << endl;
	cout << "（D：详细信息模式）" << endl;
	do
	{
		if (again) cout << "输入错误，请重新输入：" << endl;
		again = true;
		cin >> c;
		while (getchar() != '\n');
	} while (c != 'D');
	if (c == 'D')
	{
		bool again = false;
		cout << "要打开详细信息模式吗？（O：打开  C：关闭）" << endl;
		do
		{
			if (again) cout << "输入错误，请重新输入：" << endl;
			again = true;
			cin >> set;
			while (getchar() != '\n');
		} while (set != 'O' && set != 'C');
		if (set == 'O')
		{
			Student::detail = true;
			cout << "详细信息模式已打开！" << endl;
		}
		if (set == 'C')
		{
			Student::detail = false;
			cout << "详细信息模式已关闭！" << endl;
		}
		ofstream outfile;
		outfile.open("setting.dat");
		outfile << c << endl << set << endl;
		outfile.close();
	}
	cout << endl;
}

void ReadSet()
{
	char detail = ' ';
	char details = ' ';
	ifstream infile;
	infile.open("setting.dat");
	infile >> detail >> details;
	if (detail == 'D' && details == 'O')
	{
		Student::detail = true;
	}
	else if (detail == 'D' && details == 'C')
	{
		Student::detail = false;
	}
	else cout << "设置项读取失败！" << endl;
	infile.close();
}

void Save()
{
	cout << endl;
	library* p = LHead;
	bool again = false;//定义变量判断循环是否执行过
	char c = ' ';
	cout << "确认保存吗？该操作将覆盖原有的数据！" << endl;
	cout << "（Y：是  N：否）" << endl;
	do
	{
		if (again) cout << "输入错误，请重新输入：" << endl;
		again = true;
		cin >> c;
	} while (c != 'Y' && c != 'N');
	if (c == 'Y')
	{
		ofstream outfile;
		outfile.open("Information.dat", ios::trunc);
		outfile.close();
		if (Student::sum != 0)
		{
			while (p)
			{
				p->s.SaveInformation();
				p = p->next;
			}
		}
		outfile.open("Information.dat", ios::app);
		outfile << "End" << endl;
		outfile.close();
		cout << "保存完成！" << endl;
	}
	else cout << "已取消" << endl;
	cout << endl;
}

void Read(bool IsAuto)
{
	if (!IsAuto) cout << endl;
	char c = ' ';
	if (!IsAuto)
	{
		bool again = false;
		cout << "确认读档吗？该操作将覆盖原有数据！" << endl;
		cout << "（Y：是  N：否）" << endl;
		do
		{
			if (again) cout << "输入错误，请重新输入：" << endl;
			again = true;
			cin >> c;
		} while (c != 'Y' && c != 'N');
	}
	if (IsAuto || c == 'Y')
	{
		DeleteAll();
		char* check = new char[4];
		char* name = new char[8];//姓名 
		char gender;//性别（M：男，F：女，U：未知） 
		long long number;//学号 
		char* ClassAndGrade = new char[16];//班级
		int birthday;
		ifstream infile;
		infile.open("Information.dat");
		while (true)
		{
			infile >> check;
			if (!strcmp(check, "Data"))//如果读取内容为“Data”
			{

				infile >> name >> gender >> number >> ClassAndGrade >> birthday;
				library* p = new library;
				Student stu(name, gender, number, ClassAndGrade, birthday);

				p->s = stu;
				p->next = LHead;
				LHead = p;
			}
			else if (!strcmp(check, "End"))//如果读取内容为“End”
			{
				cout << "存档读取完成！" << endl;
				break;
			}
			else
			{
				char c = ' ';
				bool again = false;
				cout << "存档文件出错！" << endl;
				cout << "要重置存档吗？这将清除一切数据！" << endl;
				cout << "（Y：是  N：否）" << endl;
				do
				{
					if (again) cout << "输入错误，请重新输入：" << endl;
					again = true;
					cin >> c;
					while (getchar() != '\n');
				} while (c != 'Y' && c != 'N');
				if (c == 'Y')
				{
					ofstream outfile;
					outfile.open("Information.dat", ios::trunc);
					outfile << "End" << endl;
					outfile.close();
					Read(true);
				}
				break;
			}
		}
		infile.close();
		delete[] name;
		delete[] ClassAndGrade;
	}
	else cout << "已取消" << endl;
	if (!IsAuto) cout << endl;
}
