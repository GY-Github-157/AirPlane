#ifndef __AIRPLANE_H__
#define __AIRPLANE_H__

#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>


//当前登录人员信息
typedef struct Current_User_information_struct{
    char Name[20]; //名
    char Password[20]; //密码
}Current_User_information;

//用户链表
typedef struct User
{
    int  huiyuan_number;
    char Name[20];          //名
    char Password[20];      //密码
    char Brithday[12];      //生日
    char PostBox[20];       //邮箱
    char Flight[20];        //航班号
    char Buy_jilu[100];     //购买记录
    struct User *next;
}User_Linklist;

//航班链表
typedef struct AirPlane
{
    char Flight[20];        //航班号
    char TakeOffTime[10];   //起飞时间
    char ReverceTime[10];   //降落时间
    char Origin[10];        //出发地
    char Dest[20];          //目的地
    float Price;            //票价
    char Disscount[4];      //折扣
    int iNum;               //剩余票数
    struct AirPlane *next;
}AirPlane_Linklist;


User_Linklist *creat_User_Linklist(void);                       //创建一个链表头部
void User_Linklist_insert (User_Linklist*list);                 //插入一个用户节点
int User_Linklist_delete(User_Linklist*list,char *Name);        //根据用户名删除用户
void User_Linklist_display(User_Linklist*list);                 //展示所有用户及用户信息
User_Linklist* User_Linklist_Name_seek(User_Linklist*list,char *Name);      //查找指定用户信息并返回


AirPlane_Linklist *creat_AirPlane_Linklist(void);               //创建一个链表头部
void AirPlane_Linklist_insert (AirPlane_Linklist*list);         //插入一个用户节点
void AirPlane_Linklist_delet(AirPlane_Linklist*list,char *Flight);
void AirPlane_Linklist_display(AirPlane_Linklist*list);

AirPlane_Linklist* AirPlane_Linklist_Flight_seek(AirPlane_Linklist*list,char *Flight);


void main_menu(void);               //主界面功能
void main_menu_display(void);           //主界面显示

void huiyuan_menu(void);
void huiyuan_menu_display(void);        

void guanliyuan_menu(void);
void guanliyuan_menu_display(void);

void huiyuan_login(void);

void Buy_Flight(void);


#endif 
