#include<string.h>
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#define DEFAULT_sz 3
#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30
//���͵�����
//�˵���Ϣ
typedef struct People
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];

}people;

typedef struct Contact
{
	People* data;
	int count;
	//当前通讯录容量
	int capacity;
}Contact;

enum Switch
{
	ADD=1,
   DELITE,
	SEARCH,
   MODIFY,
	SHOW,
	SORT,
	EXTI,
};


void CheckCapacity(Contact* p);

void DestroyContact(Contact* p);

int  InitContact(Contact* p);//��ʼ��ͨѶ¼

int  AddContact(Contact* p);//������ϵ��ͨѶ¼

void ShowContact(Contact* p);//��ӡͨѶ¼�е���Ϣ

void DelContact(Contact* p);//ɾ��ͨѶ¼������Ϣ

void SearchContact(Contact* p);//Ѱ��ͨѶ¼����Ϣ

void SortContact(Contact* p);//ͨѶ¼��Ϣ����