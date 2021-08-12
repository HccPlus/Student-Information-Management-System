#include<iostream>
#include<string.h>

using namespace std;

class Student
{
	private:
		char *name = new char[8];//���� 
		char gender;//�Ա�M���У�F��Ů��U��δ֪�� 
		long long number;//ѧ�� 
		char *ClassAndGrade = new char[16];//�༶ 
		
		//ѧ����Ϣ�޸ĺ����� 
		void ChangeName()
		{
			char *i = new char[8];
			cout << "������ѧ��������" << endl; 
			cin >> i;
			while (getchar()!='\n');//��ջ���������ֹ�û������� 
			strcpy(name,i);
			delete i;
		}
		void ChangeGender()
		{
			char j;
			char *gd = new char[2];//������ʱ�洢���С�����Ů���ַ� 
			bool ck = false;//�����жϳ����Ƿ�ִ�й� 
			bool b = true;//�ж������Ƿ���ȷ 
			cout << "������ѧ���Ա�" << endl;
			do
			{
				b = true;
				if (ck) cout << "�����������������룺" << endl; 
				cin >> gd;
				while (getchar()!='\n');
				if (strcmp(gd,"M")==0) j = 'M';
				else if (strcmp(gd,"F")==0) j = 'F';
				else if (strcmp(gd,"��")==0) j = 'M';
				else if (strcmp(gd,"Ů")==0) j = 'F';
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
			cout << "������ѧ��ѧ�ţ�" << endl;
			do
			{
				if (ck) cout << "�����������������룺" << endl;
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
			cout << "������ѧ���༶��" << endl; 
			cin >> l;
			while (getchar()!='\n');
			strcpy(ClassAndGrade,l);
			delete l;
		}
		
	public:
		
		static int sum;//ѧ������ 
		
		Student(const char* i, char j = 'U', long long k = 0, const char* l = "δ֪")//ѧ���๹�캯�� 
		{
			strcpy(name,i);
			gender=j;
			number=k;
			strcpy(ClassAndGrade,l);
			sum++;
			//cout << "*ѧ����ӳɹ�" << endl;
		}
		Student()//�޲�����ѧ���๹�캯�� 
		{
			strcpy(name,"δ֪");
			gender='U';
			number=0;
			strcpy(ClassAndGrade,"δ֪");
			sum++;
			//cout << "*ѧ����ӳɹ���δ������Ϣ��" << endl;
		}
		
		long long ReturnNumber()//���ڷ���ѧ��ѧ�� 
		{
			return number;
		}
		
		bool ChangeData()//�޸�ѧ����Ϣ�ĺ��� 
		{
			char c;//�����ж��û���Ҫ�޸ĵ����� 
			bool ck = false; 
			bool change = false;
			cout << endl;
			cout << "������Ҫд������ݣ�";
			cout << "��N��������G���Ա�B��ѧ�ţ�C���༶��A���������ݣ�L��ȡ��д�룩" << endl;
			do
			{
				if (ck) cout << "�����������������룺" << endl;
				cin >> c;
				while (getchar()!='\n');
				ck = true;
			}
			while(c!='N'&&c!='G'&&c!='B'&&c!='C'&&c!='A'&&c!='L');
			//�޸�ѧ����Ϣ�� 
			if (c=='N'||c=='A') ChangeName();
			if (c=='G'||c=='A') ChangeGender();
			if (c=='B'||c=='A') ChangeNumber();
			if (c=='C'||c=='A') ChangeClassAndGrade();
			if (c=='L') cout << "��ȡ��" << endl;
			else 
			{
				change = true;
				cout << "д����ɣ�" << endl;
			}
			cout << endl;
		}
		
		void ViewData()//��ʾ����ѧ����Ϣ�ĺ��� 
		{
			cout << endl;
			cout << "ѧ��������\t";
			cout << name << endl;
			cout << "ѧ���Ա�\t";
			if (gender=='M') cout << "��" << endl;
			else if (gender=='F') cout << "Ů" << endl;
			else cout << "δ֪" << endl;
			cout << "ѧ��ѧ�ţ�\t";
			cout << number << endl;
			
			cout << "ѧ���༶��\t";
			if (strlen(ClassAndGrade)<=2)
			{
				cout << ClassAndGrade << "��" << endl;
			}
			else
			{
				cout << ClassAndGrade << endl;
			}
			cout << endl;
		}
		
		~Student()//ѧ������������ 
		{
			sum--;
		}
};

int Student::sum = 0;

void ViewAllData();//��ʾ����ѧ����Ϣ�ĺ��� 

void AddStudent();

int SerchStudent();

void DidNotFound();

void DeleteStudent();

void ModStudent();

void LookStudent();

void SumStudent();

Student *p[10000]={NULL};
int n=-1;//���ڼ�¼�洢ѧ������ָ����ռ�õĿռ� 

int main()
{
	char c = ' ';//�����ж��û���Ҫ���еĲ��� 
	cout << "��ӭʹ��Voyageѧ����Ϣ����ϵͳ��" << endl << endl;
	do
	{
		cout << endl;
		bool ck = false;
		cout << "�������ʲô������" << endl;;
		cout << "��A�����ѧ��  D��ɾ��ѧ��  M���޸�ѧ����Ϣ  L���鿴����ѧ����Ϣ";
		cout << "  V����ʾ����ѧ����Ϣ  S���鿴ѧ������  C���رճ���" << endl;
		do
		{
			if (ck) cout << "�����������������룺" << endl;
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
			cout << "���������棡����" << endl;
			cout << "�����Ҫ�رճ�����";
			cout << "�ò�����ɾ������ѧ�����ݣ�";
			cout << "���޷��ָ�������" << endl;
			cout << "��Y��ȷ�Ϲرգ�N���ֻ��ˣ�ȡ���رգ�" << endl;
			do
			{
				if (ck) cout << "�����������������룺" << endl;
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
	cout << "����رգ���Ϣ��ɾ����" << endl;
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
	if (n==-1) cout << "����ϵͳ��Ŀǰû��ѧ����" << endl;
	cout << endl;
}

void AddStudent()
{
	cout << endl;
	Student *q = new Student;//�½����� 
	Student &s = *q;
	s.ChangeData();
	n++;//ѡ����+1 
	p[n]=q;//���½�����ĵ�ַд������ 
	cout << endl;
}

int SerchStudent()
{
	char c;//����ѡ���û���������ʽ 
	bool b = false;
	int i=0;
	cout << endl;
	if (n==-1)
	{
		cout << "����ϵͳ��Ŀǰû��ѧ����" << endl;
		return -1; 
	}
	do
	{
		if (b) cout << "�����������������룺" << endl; 
		cout << "����ͨ��ʲô����������ѧ����";
		cout << "��N��������B��ѧ�ţ�" << endl;
		cin >> c;
		while (getchar()!='\n');
		if (c=='N')
		{
			cout << "��Ǹ���ó����ݲ�֧�ָù��ܣ�";
			cout << "�����ڴ������汾/(��o��)/~~" << endl;
			i=-1;
			/* 
			char *m = new char[8];
			for(int i=0;i<=n;i++)//�������ж��� 
			{
				if (strcmp(p[i]->name, m)) continue;//�Ƚ������Ƿ���ͬ 
				else
				{
					Student *q = new Student;//�½����� 
					Student &s = *q;
				}
			}
			cout << "������ѧ��������" << endl;
			cin >> m;
			while (getchar()!='\n');
			*/
		}
		else if (c=='B')
		{
			long long m0;
			bool bl = false;
			cout << "������ѧ��ѧ�ţ�" << endl;
			cin >> m0;
			while (getchar()!='\n');
			for (i;i<=n;i++)//�������ж��� 
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
				cout << "û����������ѧ����" << endl;
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
	cout << "û���ҵ���ѧ����" << endl;
}


void DeleteStudent()
{
	cout << endl;
	cout << "��Ǹ���ó����ݲ�֧�ָù��ܣ�";
	cout << "�����ڴ������汾/(��o��)/~~" << endl;
	cout << endl;
	/*
	cout << endl;
	char c;
	int k = SerchStudent();
	bool ck = false;
	if (k==-1) return;
	Student &s = *p[k];
	s.ViewData();
	cout << "�����Ҫɾ���𣿣��ò������ɻָ���";
	cout << "��Y���ǣ�N����" << endl;
	do
	{
		if (ck) cout << "�����������������룺" << endl;
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
	cout << "ȷ���޸���";
	cout << "��Y��ȷ�ϣ�N��ȡ����" << endl;
	do
	{
		if (ck) cout << "�����������������룺" << endl;
		cin >> c;
		while (getchar()!='\n');
		ck = true;
	}
	while(c!='Y'&&c!='N');
	if (c=='Y')
	{
		change = s.ChangeData();
		if (change) cout << "�޸���ɣ�" << endl;
	}
	else cout << "��ȡ��" << endl;
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
	cout << "ѧ������Ϊ��";
	cout << Student::sum << endl; 
	cout << endl;
}

