#define EXAMPLE_MACRO_NAME��
#include"contact.h.cpp"

void menu()
{
	printf("************************************\n");
	printf("*******1.add       2.del    ********\n");
	printf("*******3.search    4.modify ********\n");
	printf("*******5.show      6.sort   ********\n");
	printf("*******0.exit               ********\n");
	printf("************************************\n");
}

int InitContact(Contact *p)
{
	assert(p);
	p->count = 0;
	p->data=(People*)malloc(DEFAULT_sz,sizeof(People));
	if(p->data==NULL)
	{
		printf("%s\n",strerror(errno));
		return 1;
	}
	p->capacity=3;
	return 0;
}

int  AddContact(Contact* p)
{
	assert(p);
	CheckCapacity(p);
	printf("���������֣�>");
	scanf_s("%s", p->data[p->count].name,20);
	printf("���������䣺>");
	scanf_s("%d", &(p->data[p->count].age));
	printf("�������Ա�>");
	scanf_s("%s", (p->data[p->count].sex),10);
	printf("������绰��>");
	scanf_s("%s", (p->data[p->count].tele),12);
	printf("�������ַ��>");
	scanf_s("%s", (p->data[p->count].addr),30);
}

void CheckCapacity(Contact* p)
{
  if (p->count == p->capacity)
  {
  	People* ptr=(People*)realloc(p->data,(p->capacity+2)*sizeof(People));
  	if(ptr==NULL)
  	{
  		printf("AddContact::%s",strerror(errno));
  		return ;
  	}
  else
  {
  	p->data=ptr;
  	p->capacity+=2;
  	printf("增容成功\n");
  }
  }
}

void ShowContact(Contact* p)
{
	assert(p);
	int i = 0;
	printf("%20s\t%5s\t%5s\t%12s\t%30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	for (i = 0; i < p->count; i++)
	{
		printf("%20s\t%5d\t%5s\t%12s\t%30s\n", p->data[i].name, p->data[i].age,
			p->data[i].sex, p->data[i].tele, p->data[i].addr);
	}
}

int FindByName(Contact* p, char name[])
{
	assert(p);
	int i = 0;
	for (i = 0; i < p->count; i++)
	{
		if (0== strcmp(p->data[i].name, name))
		{
			return i;
		}
	}
	return -1;
}

void DelContact(Contact* p)
{
	char name[MAX_NAME] = { 0 };
	assert(p);
	if (p->count == 0)
	{
		printf("ͨѶ¼Ϊ�գ�û����Ϣ����ɾ��\n");
		return;
	}
	printf("������Ҫɾ���˵�����");
	scanf_s("%s", name,30);
	//1.����
	int pos = FindByName(p, name);
	int i = 0;
	if (pos == -1)
	{
		printf("Ҫɾ�����˲���\n");
		return;
	}
	//2.ɾ��
	for (i = pos; i < p->count; i++)
	{
		p->data[i] = p->data[i + 1];
	}
	p->count--;
}

void SearchContact(Contact* p)
{
	assert(p);
	char name[MAX_NAME] = { 0 };
	printf("������Ҫɾ���˵�����");
	scanf_s("%s", name,30);
	int pos = FindByName(p, name);
	int i = 0;
	if (pos == -1)
	{
		printf("Ҫ���ҵ��˲���\n");
		return;
	}
	//��ӡ
	printf("%20s\t%5s\t%5s\t%12s\t%30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	printf("%20s\t%5d\t%5s\t%12s\t%30s\n", p->data[i].name, p->data[i].age,
			p->data[i].sex, p->data[i].tele, p->data[i].addr);
}

int cm_peo_by_name(const void* e1,const void* e2)
{
	return strcmp(((People*)e1)->name, ((People*)e1)->name);

}

void SortContact(Contact* p)
{
	assert(p);
	qsort(p->data, p->count, sizeof(People),cm_peo_by_name);
	printf("����ɹ�:\n");
}

void DestroyContact(Contact* p)
{
	assert(p);
	free(p->data);
	p->data=NULL;
}
int main()
{
	int input = 0;
	Contact con;//ͨѶ¼
	//��ʼ��ͨѶ¼
	InitContact(&con);
	do
	{
		menu();
		printf("��ѡ��>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			AddContact(&con);
			break;
		case 2:
			DelContact(&con);
			break;
		case 3:
			SearchContact(&con);
			break;
		case 4:
			break;
		case 5:
			ShowContact(&con);
		case 6:
			SortContact(&con);
			break;
		case 0:
			printf("�˳�ͨѶ\n");
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
	return 0;
}