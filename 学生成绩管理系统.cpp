#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include <string>
using namespace std;

int sum[10] = { 0 };

typedef struct student
{
    int num;
    int cla;
    int score[3][3];
    char name[100];
    struct student* next;
}Lstu;

//创建学生链表
Lstu* creat()
{
    return NULL;
}

//输入学生姓名、班级
void input(Lstu*& L)
{
    Lstu* t, * s;
    s = (Lstu*)malloc(sizeof(Lstu));
    t = L;
    cout << "请输入学生姓名：" << endl;
    cin >> s->name;
    cout << "请输入学生学号：" << endl;
    cin >> s->num;
    cout << "请输入学生班级：" << endl;
    cin >> s->cla;
    sum[s->cla]++;
    s->next = t->next;
    t->next = s;

    return;
}

//按班级学期录入学生成绩
void input1(Lstu*& L)
{
    int n, k, j;
    int a[3];
    Lstu* t;
    t = L;
B:
    cout << "请输入学生学号：";
    cin >> k;
    cout << "请输入学生班级：";
    cin >> j;
C:
    while (t != NULL && t->num != k)
    {
        t = t->next;
    }
    if (t == NULL)
    {
        cout << "输入有误，请重新输入：";
        t = L;
        goto B;
    }
    if (t->cla != j) {
        t = t->next;
        goto C;
    }

A:
    cout << "请输入学期（1或2）\n" << endl;
    cin >> n;
    if (n != 1 && n != 2)
    {
        cout << "输入错误，请再次输入\n";
        goto A;
    }
    cout << "请输入语文成绩\n" << endl;
    cin >> a[0];
    cout << "请输入数学成绩\n" << endl;
    cin >> a[1];
    cout << "请输入外语成绩\n" << endl;
    cin >> a[2];
    for (int i = 0; i < 3; i++)
    {
        t->score[n - 1][i] = a[i];
    }

    return;
}

//修改学生成绩
void data(Lstu*& L)
{
    cout << "请修改改学生成绩\n" << endl;
    input1(L);
    return;
}

//班级平均分排序
void sort(int a[], int N)
{
    int i, j, k;
    for (i = 0; i <= N - 1; i++)
    {
        for (j = 0; j < N - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                k = a[j];
                a[j] = a[j + 1];
                a[j + 1] = k;
            }
        }
    }
}

void print3(Lstu* head, int j)
{
    Lstu* p;
    system("cls");
    p = head;
    printf("\n************************LinkList***************\n");
    printf("-------------------------------------------------\n");
    printf("|  班级  | 学号  |   姓名  |  语文 |  数学  |  英语  | \n");
    printf("-------------------------------------------------\n");
    while (p != NULL)
    {
        printf("|  %d  | %d   |   %-4s  |  %3d  |  %3d  |  %3d  |\n", p->cla, p->num, p->name, p->score[j - 1][0], p->score[j - 1][1], p->score[j - 1][2]);
        p = p->next;
    }
    printf("-------------------------------------------------\n");
    printf("***********************END***********************\n");
}
void sort0(Lstu* head) {
    Lstu* p, * p1, * p2, * p3, * p4;
    int t[100];
    int k = 0;
    int n, j, l;
    p = head;
    p2 = (Lstu*)malloc(sizeof(Lstu));
    p4 = (Lstu*)malloc(sizeof(Lstu));
    printf("请输入班级");
    scanf("%d", &n);
    printf("按什么进行排序：语文输入0 数学输入1 外语输入2");
    scanf("%d", &j);
    printf("请输入学期");
    scanf("%d", &l);
    while (1) {
        if (p->cla == n) {
            t[k] = p->score[l - 1][j];
            k++;
        }
        p = p->next;
        if (p == NULL) {
            break;
        }
    }
    sort(t, k);
    int w = 0;
    p3 = head;
    p1 = p4;
    p1->next = NULL;
    while (w < k) {
        while (p3->score[n - 1][j] != t[w]) {
            p3 = p3->next;
        }
        p2->num = p3->num;
        p2->score[l - 1][0] = p3->score[l - 1][0];
        p2->score[l - 1][1] = p3->score[l - 1][1];
        p2->score[l - 1][2] = p3->score[l - 1][2];
        p2->cla = p3->cla;
        strcpy(p2->name, p3->name);
        p4->next = p2;
        p4 = p4->next;
        p2 = (Lstu*)malloc(sizeof(Lstu));
        p3 = head;
        w++;
    }
    p4->next = NULL;
    print3(p1->next, l);

    return;
}

//输出(按学生查询）
void print(Lstu* L)
{
    int n;
    printf("请输入学生学号");
    scanf("%d", &n);
    Lstu* t;
    t = L;
A:
    while (t != NULL && t->num != n)
    {
        t = t->next;
    }
    if (t == NULL)
    {
        return;
    }
    cout << "班级：";
    cout << t->cla << endl;
    cout << "姓名：";
    cout << t->name << endl;
    cout << "语文：";
    cout << t->score[0][0] << endl;
    cout << "数学：";
    cout << t->score[0][1] << endl;
    cout << "外语：";
    cout << t->score[0][2] << endl;
    printf("\n");
    t = t->next;
    goto A;

    return;
}

//输出（按班级）
void print1(Lstu* L)
{
    int n;
    printf("请输入班级");
    scanf("%d", &n);
    Lstu* t;
    t = L;
    while (t != NULL)
    {
        if (t->cla == n)
        {
            cout << "姓名：";
            cout << t->name << endl;
            cout << "语文：";
            cout << t->score[0][0] << endl;
            cout << "数学：";
            cout << t->score[0][1] << endl;
            cout << "外语：";
            cout << t->score[0][2] << endl;
        }
        t = t->next;
    }
    return;
}

//按科目输出不及格学生
void print2(Lstu* L)
{
    int n;
    Lstu* t;
    t = L;
    int j;
    printf("请输入学期");
    scanf("%d", &j);
    cout << "请问您想查询哪门课程的不及格的人：" << endl;
    cout << "语文请按0，数学请按1，外语请按2." << endl;
    cin >> n;
    t = t->next;
    while (t != NULL)
    {
        if (n == 0 && t->score[j - 1][0] < 60)
        {
            printf("%s不及格 %d班\n", t->name, t->cla);
        }
        if (n == 1 && t->score[j - 1][1] < 60)
        {
            printf("%s不及格 %d班\n", t->name, t->cla);
        }
        if (n == 2 && t->score[j - 1][2] < 60)
        {
            printf("%s不及格 %d班\n", t->name, t->cla);
        }
        t = t->next;
    }

    return;
}

void menu()
{
    Lstu* L;
    L = (Lstu*)malloc(sizeof(Lstu));
    L->next = NULL;
    int n, k = 0;
    while (1)
    {
        printf("                      请选择操作\n");
        printf("--------------------------------------------------------\n");
        printf("                  1、输入学生姓名、班级\n");
        printf("                  2、按学期、班级录入学生成绩\n");
        printf("                  3、修改学生成绩\n");
        printf("                  4、按班级平均分对学生进行排序\n");
        printf("                  5、按班级输出学生的成绩单\n");
        printf("                  6、按科目输出不及格学生名单\n");
        printf("                  7、查询学生成绩单\n");
        printf("                  8、退出系统\n");
        printf("---------------------------------------------------------\n");
        cout << "请选择您的操作:" << endl;
        cin >> n;
        switch (n)
        {
        case 1:input(L); break;
        case 2:input1(L); break;
        case 3:data(L); break;
        case 4:sort0(L); break;
        case 5:print1(L); break;
        case 6:print2(L); break;
        case 7:print(L); break;
        case 8:exit(1);
        }
    }
}

int main()
{
    menu();

    return 0;
}