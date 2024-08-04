#include<string.h>
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30
//类型的声明
//人的信息
typedef struct People
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];

}people;

//通讯录
typedef struct Contact
{
	People data[100];//存放人的信息
	int count;//记录通讯录中实际人数
}Contact;

void InitContact(Contact* p);//初始化通讯录

void AddContact(Contact* p);//增加联系人通讯录

void ShowContact(Contact* p);//打印通讯录中的信息

void DelContact(Contact* p);//删除通讯录里面信息

void SearchContact(Contact* p);//寻找通讯录里信息

void SortContact(Contact* p);//通讯录信息排序