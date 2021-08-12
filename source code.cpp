#include<iostream>
#include<string.h>

using namespace std;

class Student
{
	private:
		char *name = new char[8];//姓名 
		char gender;//性别（M：男，F：女，U：未知） 
		long long number;//学号 
		char *ClassAndGrade = new char[16];//班级 
		
		//学生信息修改函数： 
		void ChangeName()
		{
			char *i = new char[8];
			cout << "请输入学生姓名：" << endl; 
			cin >> i;
			while (getchar()!='\n');//清空缓冲区，防止用户误输入 
			strcpy(name,i);
			delete i;
		}
		void ChangeGender()
		{
			char j;
			char *gd = new char[2];//用来临时存储“男”、“女”字符 
			bool ck = false;//用于判断程序是否执行过 
			bool b = true;//判断输入是否正确 
			cout << "请输入学生性别：" << endl;
			do
			{
				b = true;
				if (ck) cout << "输入有误，请重新输入：" << endl; 
				cin >> gd;
				while (getchar()!='\n');
				if (strcmp(gd,"M")==0) j = 'M';
				else if (strcmp(gd,"F")==0) j = 'F';
				else if (strcmp(gd,"男")==0) j = 'M';
				else if (strcmp(gd,"女")==0) j = 'F';
				else b = false;
				ck = true;
			}
			while(!b);
			gender=j;
		}
		void ChangeNumber()
		{
			long long k;
			bool ck = false;
			cout << "请输入学生学号：" << endl;
			do
			{
				if (ck) cout << "输入有误，请重新输入：" << endl;
				cin >> k;
				while (getchar()!='\n');
				ck = true;
			}
			while(k<1000||k>922337203685477580);
			number=k;
		}
		void ChangeClassAndGrade()
		{
			char *l = new char[16];
			cout << "请输入学生班级：" << endl; 
			cin >> l;
			while (getchar()!='\n');
			strcpy(ClassAndGrade,l);
			delete l;
		}
		
	public:
		
		static int sum;//学生总量 
		
		Student(const char* i, char j = 'U', long long k = 0, const char* l = "未知")//学生类构造函数 
		{
			strcpy(name,i);
			gender=j;
			number=k;
			strcpy(ClassAndGrade,l);
			sum++;
			//cout << "*学生添加成功" << endl;
		}
		Student()//无参数的学生类构造函数 
		{
			strcpy(name,"未知");
			gender='U';
			number=0;
			strcpy(ClassAndGrade,"未知");
			sum++;
			//cout << "*学生添加成功（未输入信息）" << endl;
		}
		
		long long ReturnNumber()//用于返回学生学号 
		{
			return number;
		}
		
		bool ChangeData()//修改学生信息的函数 
		{
			char c;//用于判断用户想要修改的数据 
			bool ck = false; 
			bool change = false;
			cout << endl;
			cout << "请输入要写入的数据：";
			cout << "（N：姓名，G：性别，B：学号，C：班级，A：所有数据，L：取消写入）" << endl;
			do
			{
				if (ck) cout << "输入有误，请重新输入：" << endl;
				cin >> c;
				while (getchar()!='\n');
				ck = true;
			}
			while(c!='N'&&c!='G'&&c!='B'&&c!='C'&&c!='A'&&c!='L');
			//修改学生信息： 
			if (c=='N'||c=='A') ChangeName();
			if (c=='G'||c=='A') ChangeGender();
			if (c=='B'||c=='A') ChangeNumber();
			if (c=='C'||c=='A') ChangeClassAndGrade();
			if (c=='L') cout << "已取消" << endl;
			else 
			{
				change = true;
				cout << "写入完成！" << endl;
			}
			cout << endl;
		}
		
		void ViewData()//显示单个学生信息的函数 
		{
			cout << endl;
			cout << "学生姓名：\t";
			cout << name << endl;
			cout << "学生性别：\t";
			if (gender=='M') cout << "男" << endl;
			else if (gender=='F') cout << "女" << endl;
			else cout << "未知" << endl;
			cout << "学生学号：\t";
			cout << number << endl;
			
			cout << "学生班级：\t";
			if (strlen(ClassAndGrade)<=2)
			{
				cout << ClassAndGrade << "班" << endl;
			}
			else
			{
				cout << ClassAndGrade << endl;
			}
			cout << endl;
		}
		
		~Student()//学生类析构函数 
		{
			sum--;
		}
};

int Student::sum = 0;

void ViewAllData();//显示所有学生信息的函数 

void AddStudent();

int SerchStudent();

void DidNotFound();

void DeleteStudent();

void ModStudent();

void LookStudent();

void SumStudent();

Student *p[10000]={NULL};
int n=-1;//用于记录存储学生对象指针所占用的空间 

int main()
{
	char c = ' ';//用于判断用户想要进行的操作 
	cout << "欢迎使用Voyage学生信息管理系统！" << endl << endl;
	do
	{
		cout << endl;
		bool ck = false;
		cout << "您想进行什么操作？" << endl;;
		cout << "（A：添加学生  D：删除学生  M：修改学生信息  L：查看单个学生信息";
		cout << "  V：显示所有学生信息  S：查看学生总数  C：关闭程序）" << endl;
		do
		{
			if (ck) cout << "输入有误，请重新输入：" << endl;
			cin >> c;
			while (getchar()!='\n');
			ck = true;
		}
		while(c!='A'&&c!='D'&&c!='M'&&c!='L'&&c!='V'&&c!='S'&&c!='C');
		if (c=='A') AddStudent();
		else if (c=='D') DeleteStudent();
		else if (c=='M') ModStudent();
		else if (c=='L') LookStudent();
		else if (c=='V') ViewAllData();
		else if (c=='S') SumStudent();
		else if (c=='C')
		{
			char close;
			bool ck = false;
			cout << "！！！警告！！！" << endl;
			cout << "您真的要关闭程序吗？";
			cout << "该操作会删除所有学生数据，";
			cout << "且无法恢复！！！" << endl;
			cout << "（Y：确认关闭，N：手滑了，取消关闭）" << endl;
			do
			{
				if (ck) cout << "输入有误，请重新输入：" << endl;
				cin >> close;
				while (getchar()!='\n');
				ck = true;
			}
			while(close!='Y'&&close!='N');
			if (close=='N') c = ' ';
			cout << endl;
		} 
	}
	while (c!='C');
	cout << "程序关闭，信息已删除。" << endl;
	//delete; 
	return 0;
}

void ViewAllData()
{
	cout << endl;
	for(int i=0;i<=n;i++)
	{
		Student &s = *p[i];
		s.ViewData();
	}
	if (n==-1) cout << "您的系统中目前没有学生！" << endl;
	cout << endl;
}

void AddStudent()
{
	cout << endl;
	Student *q = new Student;//新建对象 
	Student &s = *q;
	s.ChangeData();
	n++;//选择器+1 
	p[n]=q;//将新建对象的地址写入数组 
	cout << endl;
}

int SerchStudent()
{
	char c;//用于选择用户的搜索方式 
	bool b = false;
	int i=0;
	cout << endl;
	if (n==-1)
	{
		cout << "您的系统中目前没有学生！" << endl;
		return -1; 
	}
	do
	{
		if (b) cout << "输入有误，请重新输入：" << endl; 
		cout << "您想通过什么数据来搜索学生？";
		cout << "（N：姓名，B：学号）" << endl;
		cin >> c;
		while (getchar()!='\n');
		if (c=='N')
		{
			cout << "抱歉，该程序暂不支持该功能，";
			cout << "敬请期待后续版本/(ㄒoㄒ)/~~" << endl;
			i=-1;
			/* 
			char *m = new char[8];
			for(int i=0;i<=n;i++)//遍历所有对象 
			{
				if (strcmp(p[i]->name, m)) continue;//比较姓名是否相同 
				else
				{
					Student *q = new Student;//新建对象 
					Student &s = *q;
				}
			}
			cout << "请输入学生姓名：" << endl;
			cin >> m;
			while (getchar()!='\n');
			*/
		}
		else if (c=='B')
		{
			long long m0;
			bool bl = false;
			cout << "请输入学生学号：" << endl;
			cin >> m0;
			while (getchar()!='\n');
			for (i;i<=n;i++)//遍历所有对象 
			{
				Student &s = *p[i];
				if(m0==s.ReturnNumber())
				{
					bl = true;
					break;
				}
				else continue;
			}
			if (!bl)
			{
				i = -1;
				cout << "没有搜索到该学生！" << endl;
			}
		}
		b = true;
	}
	while (c!='N'&&c!='B');
	cout << endl;
	return i;
}

void DidNotFound()
{
	cout << "没有找到该学生！" << endl;
}


void DeleteStudent()
{
	cout << endl;
	cout << "抱歉，该程序暂不支持该功能，";
	cout << "敬请期待后续版本/(ㄒoㄒ)/~~" << endl;
	cout << endl;
	/*
	cout << endl;
	char c;
	int k = SerchStudent();
	bool ck = false;
	if (k==-1) return;
	Student &s = *p[k];
	s.ViewData();
	cout << "您真的要删除吗？（该操作不可恢复）";
	cout << "（Y：是，N：否）" << endl;
	do
	{
		if (ck) cout << "输入有误，请重新输入：" << endl;
		cin >> c;
		while (getchar()!='\n');
		ck = true;
	}
	while(c!='Y'&&c!='N');
	*/
}

void ModStudent()
{
	cout << endl;
	int k = SerchStudent();
	char c;
	bool ck = false;
	bool change;
	if (k==-1)
	{
		cout << endl;
		return;
	}
	Student &s = *p[k];
	s.ViewData();
	cout << "确认修改吗？";
	cout << "（Y：确认，N：取消）" << endl;
	do
	{
		if (ck) cout << "输入有误，请重新输入：" << endl;
		cin >> c;
		while (getchar()!='\n');
		ck = true;
	}
	while(c!='Y'&&c!='N');
	if (c=='Y')
	{
		change = s.ChangeData();
		if (change) cout << "修改完成！" << endl;
	}
	else cout << "已取消" << endl;
	cout << endl;
}

void LookStudent()
{
	cout << endl;
	int k = SerchStudent();
	if (k==-1)
	{
		cout << endl;
	}
	else
	{
		Student &s = *p[k];
		s.ViewData();
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

