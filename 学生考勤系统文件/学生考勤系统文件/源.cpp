#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int N = 0;//����ȫ�ֱ���N(  N��������Ϣ��������  )
struct Student //����ѧ��������Ϣ�ṹ��
{
	int xuhao;
	int xuehao;
	char name[15];
	struct M {
		int year;
		int month;
		int day;
		int jie;
		char coursename[15];
		char type[15];
	}m;
}stu[100];
void start()
{
	printf("\n\n\n\n\t\t\t\t\t<-------------------------->");
	printf("\n\n\n\t\t\t\t\t   ��ӭʹ��ѧ������ϵͳ");
	printf("\n\n\n\n\t\t\t\t\t<-------------------------->");
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t   by 2121806--Ԭ����");
	_sleep(1500);
}
int menu()//���˵�
{
	printf("\n\n\n\n\t\t\t\t*************************************************\n");
	printf("\t\t\t\t\t\t  ѧ������ϵͳ");
	printf("\n\t\t\t\t*************************************************\n\n");
	printf("\t\t\t\t\t    1.����ѧ��������Ϣ\n");
	printf("\t\t\t\t\t    2.��ѯѧ��������Ϣ\n");
	printf("\t\t\t\t\t    3.�޸�ѧ��������Ϣ\n");
	printf("\t\t\t\t\t    4.ɾ��ѧ��������Ϣ\n");
	printf("\t\t\t\t\t    5.ͳ��ѧ��������Ϣ\n");
	printf("\t\t\t\t\t    6.�˳�ϵͳ\n\n");
	printf("\t\t\t\t*************************************************\n");
	printf("\t\t\t        ����������ѡ��");
	int x;
	scanf("%d", &x);
	return x;
}
void input()/*������Ϣ*/
{
	int n, k = N;
	printf("\n\n\n\n\t\t\t\t*************************************************\n");
	printf("\t\t\t\t\t\t  ѧ������ϵͳ");
	printf("\n\t\t\t\t*************************************************\n");
	printf("\n\n\t\t\t\t������Ҫ��¼�Ŀ�����Ϣ��������");
	scanf("%d", &n);
	N += n;//ʵ����ԭ������Ϣ�������µ���Ϣ
	FILE* fp;
	if ((fp = fopen("ARecord.txt", "w")) == NULL)
	{
		printf("\t\t�ļ���ʧ��!\n");
		system("pause");
	}
	for (int i = k; i < N; i++)
	{
		system("cls");
		printf("\n\n\n\n\t\t\t\t*************************************************\n");
		printf("\t\t\t\t\t\t  ѧ������ϵͳ");
		printf("\n\t\t\t\t*************************************************\n\n");
		printf("\t\t\t\t   ���������%d��������Ϣ......\n", i + 1);
		printf("\t\t\t\t�����·�����ѧ���ĸ�����Ϣ(ѧ��/����)��\n");
		stu[i].xuhao = i + 1;
		printf("\t\t\t\tѧ�ţ�");
		scanf("%d", &stu[i].xuehao);
		printf("\n\t\t\t\t������");
		scanf("%s", stu[i].name);
		printf("\n\t\t\t\t���ڣ���/��/�գ���");
		scanf("%d%d%d", &stu[i].m.year, &stu[i].m.month, &stu[i].m.day);
		printf("\n\t\t\t\t������");
		scanf("%d", &stu[i].m.jie);
		printf("\n\t\t\t\t�γ����ƣ�");
		scanf("%s", stu[i].m.coursename);
		printf("\n\t\t\t\t�������(�ٵ�/����/���/����)��");
		scanf("%s", stu[i].m.type);
		if (fwrite(&stu[i], sizeof(struct Student), 1, fp) != 1)
		{
			printf("�ļ�д�����\n");
			system("pause");
		}
	}
	getchar();//���ջس���
	system("cls");
	printf("\n\n\t\t\t\t������ϣ���������������˵�......\n");
}
void find()/*������Ϣ*/
{
	printf("\n\n\n\n\t\t\t\t*************************************************\n");
	printf("\t\t\t\t\t\t  ѧ������ϵͳ");
	printf("\n\t\t\t\t*************************************************\n\n");
	printf("\t\t\t\t������Ҫ��ѯ��ѧ�ţ�");
	FILE* fp;
	if ((fp = fopen("ARecord.txt", "r")) == NULL)   //���ļ����ݶ����ڴ�
	{
		printf("\t\t�ļ���ʧ��!\n");
		system("pause");
	}
	int x, i, num = 0;
	scanf_s("%d", &x);
	printf("\t\t\t\t��ѯ������£�\n");
	printf("\t\t\t\t���\tѧ��\t����\t����  \t����\t�γ�����\t�������\n");
	for (i = 0; i < N; i++)
	{
		fread(&stu[i], sizeof(struct Student), 1, fp);  //��ȡ�ļ�����
		if (stu[i].xuehao == x)
		{
			printf("\t\t\t\t%d%11d%8s%7d.%d.%d%5d%11s%16s\n", stu[i].xuhao, stu[i].xuehao, stu[i].name, stu[i].m.year, stu[i].m.month, stu[i].m.day, stu[i].m.jie, stu[i].m.coursename, stu[i].m.type);
			num += 1;
		}
	}
	if (num == 0)printf("\n\t\t\t\t��¼�����ڣ�");
	fclose(fp);
	getchar();
	printf("\n\n\t\t\t\t��ѯ��ϣ���������������˵�......\n");
}
void ModifyXuehao(int x)//�޸�ѧ��
{
	system("cls");
	printf("\n\n\n\n\t\t\t\t*************************************************\n");
	printf("\t\t\t\t\t\t  ѧ������ϵͳ");
	printf("\n\t\t\t\t*************************************************\n\n");
	printf("\t\t\t\t�������޸ĺ�����ݣ�");
	int a;
	scanf("%d", &a);
	stu[x - 1].xuehao = a;
	printf("\t\t\t\t�޸ĳɹ����������������һ��......\n");
	getchar();
}
void ModifyName(int x)//�޸�����
{
	system("cls");
	printf("\n\n\n\n\t\t\t\t*************************************************\n");
	printf("\t\t\t\t\t\t  ѧ������ϵͳ");
	printf("\n\t\t\t\t*************************************************\n\n");
	printf("\t\t\t\t�������޸ĺ�����ݣ�");
	char a[10];
	scanf("%s", a);
	memset(stu[x - 1].name, '\0', sizeof(a));
	strcpy(stu[x - 1].name, a);
	printf("\t\t\t\t�޸ĳɹ����������������һ��......\n");
	getchar();
}
void ModifyYear(int x)//�޸����
{
	system("cls");
	printf("\n\n\n\n\t\t\t\t*************************************************\n");
	printf("\t\t\t\t\t\t  ѧ������ϵͳ");
	printf("\n\t\t\t\t*************************************************\n\n");
	printf("\t\t\t\t�������޸ĺ�����ݣ�");
	int a;
	scanf("%d", &a);
	stu[x - 1].m.year = a;
	printf("\t\t\t\t�޸ĳɹ����������������һ��......\n");
	getchar();
}
void ModifyMonth(int x)//�޸��·�
{
	system("cls");
	printf("\n\n\n\n\t\t\t\t*************************************************\n");
	printf("\t\t\t\t\t\t  ѧ������ϵͳ");
	printf("\n\t\t\t\t*************************************************\n\n");
	printf("\t\t\t\t�������޸ĺ�����ݣ�");
	int a;
	scanf("%d", &a);
	stu[x - 1].m.month = a;
	printf("\t\t\t\t�޸ĳɹ����������������һ��......\n");
	getchar();
}
void ModifyDay(int x)//�޸�day
{
	system("cls");
	printf("\n\n\n\n\t\t\t\t*************************************************\n");
	printf("\t\t\t\t\t\t  ѧ������ϵͳ");
	printf("\n\t\t\t\t*************************************************\n\n");
	printf("\t\t\t\t�������޸ĺ�����ݣ�");
	int a;
	scanf("%d", &a);
	stu[x - 1].m.day = a;
	printf("\t\t\t\t�޸ĳɹ����������������һ��......\n");
	getchar();
}
void ModifyJie(int x)//�޸Ľ���
{
	system("cls");
	printf("\n\n\n\n\t\t\t\t*************************************************\n");
	printf("\t\t\t\t\t\t  ѧ������ϵͳ");
	printf("\n\t\t\t\t*************************************************\n\n");
	printf("\t\t\t\t�������޸ĺ�����ݣ�");
	int a;
	scanf("%d", &a);
	stu[x - 1].m.jie = a;
	printf("\t\t\t\t�޸ĳɹ����������������һ��......\n");
	getchar();
}
void ModifyCoursename(int x)//�޸Ŀγ�����
{
	system("cls");
	printf("\n\n\n\n\t\t\t\t*************************************************\n");
	printf("\t\t\t\t\t\t  ѧ������ϵͳ");
	printf("\n\t\t\t\t*************************************************\n\n");
	printf("\t\t\t\t�������޸ĺ�����ݣ�");
	char a[10];
	scanf("%s", a);
	memset(stu[x - 1].m.coursename, '\0', sizeof(a));
	strcpy(stu[x - 1].m.coursename, a);
	printf("\t\t\t\t�޸ĳɹ����������������һ��......\n");
	getchar();
}
void ModifyType(int x)//�޸Ŀ�������
{
	system("cls");
	printf("\n\n\n\n\t\t\t\t*************************************************\n");
	printf("\t\t\t\t\t\t  ѧ������ϵͳ");
	printf("\n\t\t\t\t*************************************************\n\n");
	printf("\t\t\t\t�������޸ĺ�����ݣ�");
	char a[10];
	scanf("%s", a);
	memset(stu[x - 1].m.type, '\0', sizeof(a));
	strcpy(stu[x - 1].m.type, a);
	printf("\t\t\t\t�޸ĳɹ����������������һ��......\n");
	getchar();
}
void modify()/*�޸���Ϣ*/
{
	int x;
	do {
		system("cls");
		FILE* fp;
		if ((fp = fopen("ARecord.txt", "r")) == NULL)   //���ļ����ݶ����ڴ�
		{
			printf("\t\t�ļ���ʧ��!\n");
			system("pause");
		}
		printf("\n\n\n\n\t\t\t\t*************************************************\n");
		printf("\t\t\t\t\t\t  ѧ������ϵͳ");
		printf("\n\t\t\t\t*************************************************\n\n");
		printf("\t\t\t\t����Ϊ�Ѽ�¼�Ŀ�����Ϣ��\n\n");
		printf("\t\t\t\t���\tѧ��\t����\t����  \t����\t�γ�����\t�������\n");
		printf("\t\t\t\t----------------------------------------------------------------------\n");
		for (int i = 0; i < N; i++)
		{
			fread(&stu[i], sizeof(struct Student), 1, fp);  //��ȡ�ļ�����
			printf("\t\t\t\t%d%11d%8s%7d.%d.%d%5d%11s%16s\n", stu[i].xuhao, stu[i].xuehao, stu[i].name, stu[i].m.year, stu[i].m.month, stu[i].m.day, stu[i].m.jie, stu[i].m.coursename, stu[i].m.type);
		}
		printf("\t\t\t\t----------------------------------------------------------------------\n");
		printf("\t\t\t\t������Ҫ�޸Ŀ��ڼ�¼�����(��0�˳�)��");
		scanf("%d", &x);
		if (x != 0)
		{
			system("cls");
			printf("\n\n\n\n\t\t\t\t*************************************************\n");
			printf("\t\t\t\t\t\t  ѧ������ϵͳ");
			printf("\n\t\t\t\t*************************************************\n\n");
			printf("\t\t\t\t���\tѧ��\t����\t����  \t����\t�γ�����\t�������\n");
			printf("\t\t\t\t%d%11d%8s%7d.%d.%d%5d%11s%16s\n", stu[x - 1].xuhao, stu[x - 1].xuehao, stu[x - 1].name, stu[x - 1].m.year, stu[x - 1].m.month, stu[x - 1].m.day, stu[x - 1].m.jie, stu[x - 1].m.coursename, stu[x - 1].m.type);
			printf("\t\t\t\t������Ҫ�޸ĵ�����(1.ѧ��   2.����   3.��   4.��   5.��   6.����   7.�γ�����   8.��������)��");
			int a;
			scanf("%d", &a);
			switch (a)
			{
			case 1:ModifyXuehao(x); getchar(); break;
			case 2:ModifyName(x); getchar(); break;
			case 3:ModifyYear(x); getchar(); break;
			case 4:ModifyMonth(x); getchar(); break;
			case 5:ModifyDay(x); getchar(); break;
			case 6:ModifyJie(x); getchar(); break;
			case 7:ModifyCoursename(x); getchar(); break;
			case 8:ModifyType(x); getchar(); break;
			}
		}
		fclose(fp);
	} while (x != 0);

	getchar();
	system("cls");
	printf("\n\n\t\t\t\t��������������˵�......\n");
}
void del()/*ɾ����Ϣ*/
{
	FILE* fp;
	if ((fp = fopen("ARecord.txt", "r")) == NULL)   //���ļ����ݶ����ڴ�
	{
		printf("\t\t�ļ���ʧ��!\n");
		system("pause");
	}
	printf("\n\n\n\n\t\t\t\t*************************************************\n");
	printf("\t\t\t\t\t\t  ѧ������ϵͳ");
	printf("\n\t\t\t\t*************************************************\n\n");
	printf("\t\t\t\t���\tѧ��\t����\t����  \t����\t�γ�����\t�������\n");
	for (int i = 0; i < N; i++)
	{
		fread(&stu[i], sizeof(struct Student), 1, fp);  //��ȡ�ļ�����
		if (stu[i].xuehao != 0)printf("\t\t\t\t%d%11d%8s%7d.%d.%d%5d%11s%16s\n", stu[i].xuhao, stu[i].xuehao, stu[i].name, stu[i].m.year, stu[i].m.month, stu[i].m.day, stu[i].m.jie, stu[i].m.coursename, stu[i].m.type);
	}
	printf("\t\t\t\t������Ҫɾ����¼����ţ�");
	int a;
	scanf("%d", &a);
	for (int i = a - 1; i < N; i++)//Ӧ��ȫ�ֱ���N
	{
		stu[i].xuehao = stu[i + 1].xuehao;
		strcpy(stu[i].name, stu[i + 1].name);
		stu[i].m.year = stu[i + 1].m.year;
		stu[i].m.month = stu[i + 1].m.month;
		stu[i].m.day = stu[i + 1].m.day;
		stu[i].m.jie = stu[i + 1].m.jie;
		strcpy(stu[i].m.coursename, stu[i + 1].m.coursename);
		strcpy(stu[i].m.type, stu[i + 1].m.type);
	}
	int c = 0;
	for (int i = 0; i < N; i++)//Ӧ��ȫ�ֱ���N
	{
		if (stu[i].xuehao != 0)c += 1;
	}
	N = c;
	system("cls");
	fclose(fp);
	getchar();
	printf("\n\n\t\t\t\tɾ����ϣ���������������˵�......\n");
}
void count()/*ͳ����Ϣ*/
{
	FILE* fp;
	if ((fp = fopen("ARecord.txt", "r")) == NULL)   //���ļ����ݶ����ڴ�
	{
		printf("\t\t�ļ���ʧ��!\n");
		system("pause");
	}
	printf("\n\n\n\n\t\t\t\t*************************************************\n");
	printf("\t\t\t\t\t\t  ѧ������ϵͳ");
	printf("\n\t\t\t\t*************************************************\n\n");
	printf("\t\t\t\t����Ϊ�Ѽ�¼�Ŀ�����Ϣ��\n");
	printf("\t\t\t\t���\tѧ��\t����\t����  \t����\t�γ�����\t�������\n");
	for (int i = 0; i < N; i++)
	{
		fread(&stu[i], sizeof(struct Student), 1, fp);  //��ȡ�ļ�����
		printf("\t\t\t\t%d%11d%8s%7d.%d.%d%5d%11s%16s\n", stu[i].xuhao, stu[i].xuehao, stu[i].name, stu[i].m.year, stu[i].m.month, stu[i].m.day, stu[i].m.jie, stu[i].m.coursename, stu[i].m.type);
	}
	printf("\t\t\t\t������Ҫͳ��ѧ����ѧ�ţ�");
	int x, message = 0, cd = 0, zt = 0, qj = 0, kk = 0;
	scanf("%d", &x);
	system("cls");
	for (int i = 0; i < N; i++)//Ӧ��ȫ�ֱ���N
	{
		if (stu[i].xuehao == x)
		{
			message += 1;
			if (strcmp(stu[i].m.type, "�ٵ�") == 0) cd += 1;
			if (strcmp(stu[i].m.type, "����") == 0) zt += 1;
			if (strcmp(stu[i].m.type, "���") == 0) qj += 1;
			if (strcmp(stu[i].m.type, "����") == 0) kk += 1;
		}
	}
	printf("\n\n\t\t\t\t������ͳ����Ϣ��\n");
	printf("\n\n\t\t\t\t��ѧ������%d�����ڼ�¼\n", message);
	printf("\n\n\t\t\t\t�ٵ���%d��\n", cd);
	printf("\n\n\t\t\t\t���ˣ�%d��\n", zt);
	printf("\n\n\t\t\t\t��٣�%d��\n", qj);
	printf("\n\n\t\t\t\t���Σ�%d��\n", kk);
	fclose(fp);
	getchar();
	printf("\n\n\t\t\t\tͳ����ϣ���������������˵�......\n");
}
int main()//������
{
	start();
	int x;
	do {
		system("cls"); x = menu();
		switch (x)
		{
		case 1:system("cls");
			input(); getchar(); break;
		case 2:system("cls");
			find(); getchar(); break;
		case 3:system("cls");
			modify(); getchar(); break;
		case 4:system("cls");
			del(); getchar(); break;
		case 5:system("cls");
			count(); getchar(); break;
		}
	} while (x != 6);
	getchar();//��ֹ��6�˳�ϵͳ��ֱ���˳�����
	system("cls");
	printf("\n\n\n\n\t\t\t\t��лʹ��!\n\n");
	_sleep(2500);
	return 0;
}