#define EXAMPLE_MACRO_NAME）
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

void InitContact(Contact *p)
{
	assert(p);
	p->count = 0;
	memset(p->data, 0, sizeof(p->data));
}

void AddContact(Contact* p)
{
	assert(p);
	if (p->count == MAX)
	{
		printf("通讯录满了，无法添加\n");
		return;
	}
	else
	printf("请输入名字：>");
	scanf_s("%s", p->data[p->count].name,20);
	printf("请输入年龄：>");
	scanf_s("%d", &(p->data[p->count].age));
	printf("请输入性别：>");
	scanf_s("%s", (p->data[p->count].sex),10);
	printf("请输入电话：>");
	scanf_s("%s", (p->data[p->count].tele),12);
	printf("请输入地址：>");
	scanf_s("%s", (p->data[p->count].addr),30);
}

void ShowContact(Contact* p)
{
	assert(p);
	int i = 0;
	printf("%20s\t%5s\t%5s\t%12s\t%30s\n", "名字", "年龄", "性别", "电话", "地址");
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
		printf("通讯录为空，没有信息可以删除\n");
		return;
	}
	printf("请输入要删除人的名字");
	scanf_s("%s", name,30);
	//1.查找
	int pos = FindByName(p, name);
	int i = 0;
	if (pos == -1)
	{
		printf("要删除的人不在\n");
		return;
	}
	//2.删除
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
	printf("请输入要删除人的名字");
	scanf_s("%s", name,30);
	int pos = FindByName(p, name);
	int i = 0;
	if (pos == -1)
	{
		printf("要查找的人不在\n");
		return;
	}
	//打印
	printf("%20s\t%5s\t%5s\t%12s\t%30s\n", "名字", "年龄", "性别", "电话", "地址");
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
	qsort(pc->data, pc->count, sizeof(People),cm_peo_by_name);
	printf("排序成功:\n");
}
int main()
{
	int input = 0;
	Contact con;//通讯录
	//初始化通讯录
	InitContact(&con);
	do
	{
		menu();
		printf("请选择：>");
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
		case 4:
			break;
		case 5:
			ShowContact(&con);
		case 6:
			SortContact(&con);
			break;
		case 0:
			printf("退出通讯\n");
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}