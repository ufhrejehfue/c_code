#include<string.h>
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
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

//ͨѶ¼
typedef struct Contact
{
	People data[100];//����˵���Ϣ
	int count;//��¼ͨѶ¼��ʵ������
}Contact;

void InitContact(Contact* p);//��ʼ��ͨѶ¼

void AddContact(Contact* p);//������ϵ��ͨѶ¼

void ShowContact(Contact* p);//��ӡͨѶ¼�е���Ϣ

void DelContact(Contact* p);//ɾ��ͨѶ¼������Ϣ

void SearchContact(Contact* p);//Ѱ��ͨѶ¼����Ϣ

void SortContact(Contact* p);//ͨѶ¼��Ϣ����