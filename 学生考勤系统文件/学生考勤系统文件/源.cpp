#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int N = 0;//定义全局变量N(  N代表考勤信息的总条数  )
struct Student //定义学生考勤信息结构体
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
	printf("\n\n\n\t\t\t\t\t   欢迎使用学生考勤系统");
	printf("\n\n\n\n\t\t\t\t\t<-------------------------->");
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t   by 2121806--袁恺翔");
	_sleep(1500);
}
int menu()//主菜单
{
	printf("\n\n\n\n\t\t\t\t*************************************************\n");
	printf("\t\t\t\t\t\t  学生考勤系统");
	printf("\n\t\t\t\t*************************************************\n\n");
	printf("\t\t\t\t\t    1.输入学生考勤信息\n");
	printf("\t\t\t\t\t    2.查询学生考勤信息\n");
	printf("\t\t\t\t\t    3.修改学生考勤信息\n");
	printf("\t\t\t\t\t    4.删除学生考勤信息\n");
	printf("\t\t\t\t\t    5.统计学生考勤信息\n");
	printf("\t\t\t\t\t    6.退出系统\n\n");
	printf("\t\t\t\t*************************************************\n");
	printf("\t\t\t        请输入您的选择：");
	int x;
	scanf("%d", &x);
	return x;
}
void input()/*输入信息*/
{
	int n, k = N;
	printf("\n\n\n\n\t\t\t\t*************************************************\n");
	printf("\t\t\t\t\t\t  学生考勤系统");
	printf("\n\t\t\t\t*************************************************\n");
	printf("\n\n\t\t\t\t请输入要记录的考勤信息的条数：");
	scanf("%d", &n);
	N += n;//实现在原来的信息上增加新的信息
	FILE* fp;
	if ((fp = fopen("ARecord.txt", "w")) == NULL)
	{
		printf("\t\t文件打开失败!\n");
		system("pause");
	}
	for (int i = k; i < N; i++)
	{
		system("cls");
		printf("\n\n\n\n\t\t\t\t*************************************************\n");
		printf("\t\t\t\t\t\t  学生考勤系统");
		printf("\n\t\t\t\t*************************************************\n\n");
		printf("\t\t\t\t   正在输入第%d条考勤信息......\n", i + 1);
		printf("\t\t\t\t请在下方输入学生的个人信息(学号/姓名)：\n");
		stu[i].xuhao = i + 1;
		printf("\t\t\t\t学号：");
		scanf("%d", &stu[i].xuehao);
		printf("\n\t\t\t\t姓名：");
		scanf("%s", stu[i].name);
		printf("\n\t\t\t\t日期（年/月/日）：");
		scanf("%d%d%d", &stu[i].m.year, &stu[i].m.month, &stu[i].m.day);
		printf("\n\t\t\t\t节数：");
		scanf("%d", &stu[i].m.jie);
		printf("\n\t\t\t\t课程名称：");
		scanf("%s", stu[i].m.coursename);
		printf("\n\t\t\t\t考勤情况(迟到/早退/请假/旷课)：");
		scanf("%s", stu[i].m.type);
		if (fwrite(&stu[i], sizeof(struct Student), 1, fp) != 1)
		{
			printf("文件写入错误\n");
			system("pause");
		}
	}
	getchar();//吸收回车符
	system("cls");
	printf("\n\n\t\t\t\t输入完毕！按任意键返回主菜单......\n");
}
void find()/*查找信息*/
{
	printf("\n\n\n\n\t\t\t\t*************************************************\n");
	printf("\t\t\t\t\t\t  学生考勤系统");
	printf("\n\t\t\t\t*************************************************\n\n");
	printf("\t\t\t\t请输入要查询的学号：");
	FILE* fp;
	if ((fp = fopen("ARecord.txt", "r")) == NULL)   //将文件内容读入内存
	{
		printf("\t\t文件打开失败!\n");
		system("pause");
	}
	int x, i, num = 0;
	scanf_s("%d", &x);
	printf("\t\t\t\t查询结果如下：\n");
	printf("\t\t\t\t序号\t学号\t姓名\t日期  \t节数\t课程名称\t考勤情况\n");
	for (i = 0; i < N; i++)
	{
		fread(&stu[i], sizeof(struct Student), 1, fp);  //读取文件内容
		if (stu[i].xuehao == x)
		{
			printf("\t\t\t\t%d%11d%8s%7d.%d.%d%5d%11s%16s\n", stu[i].xuhao, stu[i].xuehao, stu[i].name, stu[i].m.year, stu[i].m.month, stu[i].m.day, stu[i].m.jie, stu[i].m.coursename, stu[i].m.type);
			num += 1;
		}
	}
	if (num == 0)printf("\n\t\t\t\t记录不存在！");
	fclose(fp);
	getchar();
	printf("\n\n\t\t\t\t查询完毕！按任意键返回主菜单......\n");
}
void ModifyXuehao(int x)//修改学号
{
	system("cls");
	printf("\n\n\n\n\t\t\t\t*************************************************\n");
	printf("\t\t\t\t\t\t  学生考勤系统");
	printf("\n\t\t\t\t*************************************************\n\n");
	printf("\t\t\t\t请输入修改后的数据：");
	int a;
	scanf("%d", &a);
	stu[x - 1].xuehao = a;
	printf("\t\t\t\t修改成功！按任意键返回上一步......\n");
	getchar();
}
void ModifyName(int x)//修改姓名
{
	system("cls");
	printf("\n\n\n\n\t\t\t\t*************************************************\n");
	printf("\t\t\t\t\t\t  学生考勤系统");
	printf("\n\t\t\t\t*************************************************\n\n");
	printf("\t\t\t\t请输入修改后的数据：");
	char a[10];
	scanf("%s", a);
	memset(stu[x - 1].name, '\0', sizeof(a));
	strcpy(stu[x - 1].name, a);
	printf("\t\t\t\t修改成功！按任意键返回上一步......\n");
	getchar();
}
void ModifyYear(int x)//修改年份
{
	system("cls");
	printf("\n\n\n\n\t\t\t\t*************************************************\n");
	printf("\t\t\t\t\t\t  学生考勤系统");
	printf("\n\t\t\t\t*************************************************\n\n");
	printf("\t\t\t\t请输入修改后的数据：");
	int a;
	scanf("%d", &a);
	stu[x - 1].m.year = a;
	printf("\t\t\t\t修改成功！按任意键返回上一步......\n");
	getchar();
}
void ModifyMonth(int x)//修改月份
{
	system("cls");
	printf("\n\n\n\n\t\t\t\t*************************************************\n");
	printf("\t\t\t\t\t\t  学生考勤系统");
	printf("\n\t\t\t\t*************************************************\n\n");
	printf("\t\t\t\t请输入修改后的数据：");
	int a;
	scanf("%d", &a);
	stu[x - 1].m.month = a;
	printf("\t\t\t\t修改成功！按任意键返回上一步......\n");
	getchar();
}
void ModifyDay(int x)//修改day
{
	system("cls");
	printf("\n\n\n\n\t\t\t\t*************************************************\n");
	printf("\t\t\t\t\t\t  学生考勤系统");
	printf("\n\t\t\t\t*************************************************\n\n");
	printf("\t\t\t\t请输入修改后的数据：");
	int a;
	scanf("%d", &a);
	stu[x - 1].m.day = a;
	printf("\t\t\t\t修改成功！按任意键返回上一步......\n");
	getchar();
}
void ModifyJie(int x)//修改节数
{
	system("cls");
	printf("\n\n\n\n\t\t\t\t*************************************************\n");
	printf("\t\t\t\t\t\t  学生考勤系统");
	printf("\n\t\t\t\t*************************************************\n\n");
	printf("\t\t\t\t请输入修改后的数据：");
	int a;
	scanf("%d", &a);
	stu[x - 1].m.jie = a;
	printf("\t\t\t\t修改成功！按任意键返回上一步......\n");
	getchar();
}
void ModifyCoursename(int x)//修改课程名称
{
	system("cls");
	printf("\n\n\n\n\t\t\t\t*************************************************\n");
	printf("\t\t\t\t\t\t  学生考勤系统");
	printf("\n\t\t\t\t*************************************************\n\n");
	printf("\t\t\t\t请输入修改后的数据：");
	char a[10];
	scanf("%s", a);
	memset(stu[x - 1].m.coursename, '\0', sizeof(a));
	strcpy(stu[x - 1].m.coursename, a);
	printf("\t\t\t\t修改成功！按任意键返回上一步......\n");
	getchar();
}
void ModifyType(int x)//修改考勤类型
{
	system("cls");
	printf("\n\n\n\n\t\t\t\t*************************************************\n");
	printf("\t\t\t\t\t\t  学生考勤系统");
	printf("\n\t\t\t\t*************************************************\n\n");
	printf("\t\t\t\t请输入修改后的数据：");
	char a[10];
	scanf("%s", a);
	memset(stu[x - 1].m.type, '\0', sizeof(a));
	strcpy(stu[x - 1].m.type, a);
	printf("\t\t\t\t修改成功！按任意键返回上一步......\n");
	getchar();
}
void modify()/*修改信息*/
{
	int x;
	do {
		system("cls");
		FILE* fp;
		if ((fp = fopen("ARecord.txt", "r")) == NULL)   //将文件内容读入内存
		{
			printf("\t\t文件打开失败!\n");
			system("pause");
		}
		printf("\n\n\n\n\t\t\t\t*************************************************\n");
		printf("\t\t\t\t\t\t  学生考勤系统");
		printf("\n\t\t\t\t*************************************************\n\n");
		printf("\t\t\t\t以下为已记录的考勤信息：\n\n");
		printf("\t\t\t\t序号\t学号\t姓名\t日期  \t节数\t课程名称\t考勤情况\n");
		printf("\t\t\t\t----------------------------------------------------------------------\n");
		for (int i = 0; i < N; i++)
		{
			fread(&stu[i], sizeof(struct Student), 1, fp);  //读取文件内容
			printf("\t\t\t\t%d%11d%8s%7d.%d.%d%5d%11s%16s\n", stu[i].xuhao, stu[i].xuehao, stu[i].name, stu[i].m.year, stu[i].m.month, stu[i].m.day, stu[i].m.jie, stu[i].m.coursename, stu[i].m.type);
		}
		printf("\t\t\t\t----------------------------------------------------------------------\n");
		printf("\t\t\t\t请输入要修改考勤记录的序号(按0退出)：");
		scanf("%d", &x);
		if (x != 0)
		{
			system("cls");
			printf("\n\n\n\n\t\t\t\t*************************************************\n");
			printf("\t\t\t\t\t\t  学生考勤系统");
			printf("\n\t\t\t\t*************************************************\n\n");
			printf("\t\t\t\t序号\t学号\t姓名\t日期  \t节数\t课程名称\t考勤情况\n");
			printf("\t\t\t\t%d%11d%8s%7d.%d.%d%5d%11s%16s\n", stu[x - 1].xuhao, stu[x - 1].xuehao, stu[x - 1].name, stu[x - 1].m.year, stu[x - 1].m.month, stu[x - 1].m.day, stu[x - 1].m.jie, stu[x - 1].m.coursename, stu[x - 1].m.type);
			printf("\t\t\t\t请输入要修改的数据(1.学号   2.姓名   3.年   4.月   5.日   6.节数   7.课程名称   8.考勤类型)：");
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
	printf("\n\n\t\t\t\t按任意键返回主菜单......\n");
}
void del()/*删除信息*/
{
	FILE* fp;
	if ((fp = fopen("ARecord.txt", "r")) == NULL)   //将文件内容读入内存
	{
		printf("\t\t文件打开失败!\n");
		system("pause");
	}
	printf("\n\n\n\n\t\t\t\t*************************************************\n");
	printf("\t\t\t\t\t\t  学生考勤系统");
	printf("\n\t\t\t\t*************************************************\n\n");
	printf("\t\t\t\t序号\t学号\t姓名\t日期  \t节数\t课程名称\t考勤情况\n");
	for (int i = 0; i < N; i++)
	{
		fread(&stu[i], sizeof(struct Student), 1, fp);  //读取文件内容
		if (stu[i].xuehao != 0)printf("\t\t\t\t%d%11d%8s%7d.%d.%d%5d%11s%16s\n", stu[i].xuhao, stu[i].xuehao, stu[i].name, stu[i].m.year, stu[i].m.month, stu[i].m.day, stu[i].m.jie, stu[i].m.coursename, stu[i].m.type);
	}
	printf("\t\t\t\t请输入要删除记录的序号：");
	int a;
	scanf("%d", &a);
	for (int i = a - 1; i < N; i++)//应用全局变量N
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
	for (int i = 0; i < N; i++)//应用全局变量N
	{
		if (stu[i].xuehao != 0)c += 1;
	}
	N = c;
	system("cls");
	fclose(fp);
	getchar();
	printf("\n\n\t\t\t\t删除完毕，按任意键返回主菜单......\n");
}
void count()/*统计信息*/
{
	FILE* fp;
	if ((fp = fopen("ARecord.txt", "r")) == NULL)   //将文件内容读入内存
	{
		printf("\t\t文件打开失败!\n");
		system("pause");
	}
	printf("\n\n\n\n\t\t\t\t*************************************************\n");
	printf("\t\t\t\t\t\t  学生考勤系统");
	printf("\n\t\t\t\t*************************************************\n\n");
	printf("\t\t\t\t以下为已记录的考勤信息：\n");
	printf("\t\t\t\t序号\t学号\t姓名\t日期  \t节数\t课程名称\t考勤情况\n");
	for (int i = 0; i < N; i++)
	{
		fread(&stu[i], sizeof(struct Student), 1, fp);  //读取文件内容
		printf("\t\t\t\t%d%11d%8s%7d.%d.%d%5d%11s%16s\n", stu[i].xuhao, stu[i].xuehao, stu[i].name, stu[i].m.year, stu[i].m.month, stu[i].m.day, stu[i].m.jie, stu[i].m.coursename, stu[i].m.type);
	}
	printf("\t\t\t\t请输入要统计学生的学号：");
	int x, message = 0, cd = 0, zt = 0, qj = 0, kk = 0;
	scanf("%d", &x);
	system("cls");
	for (int i = 0; i < N; i++)//应用全局变量N
	{
		if (stu[i].xuehao == x)
		{
			message += 1;
			if (strcmp(stu[i].m.type, "迟到") == 0) cd += 1;
			if (strcmp(stu[i].m.type, "早退") == 0) zt += 1;
			if (strcmp(stu[i].m.type, "请假") == 0) qj += 1;
			if (strcmp(stu[i].m.type, "旷课") == 0) kk += 1;
		}
	}
	printf("\n\n\t\t\t\t以下是统计信息：\n");
	printf("\n\n\t\t\t\t该学生共有%d条考勤记录\n", message);
	printf("\n\n\t\t\t\t迟到：%d次\n", cd);
	printf("\n\n\t\t\t\t早退：%d次\n", zt);
	printf("\n\n\t\t\t\t请假：%d次\n", qj);
	printf("\n\n\t\t\t\t旷课：%d次\n", kk);
	fclose(fp);
	getchar();
	printf("\n\n\t\t\t\t统计完毕，按任意键返回主菜单......\n");
}
int main()//主函数
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
	getchar();//防止按6退出系统后直接退出程序
	system("cls");
	printf("\n\n\n\n\t\t\t\t感谢使用!\n\n");
	_sleep(2500);
	return 0;
}