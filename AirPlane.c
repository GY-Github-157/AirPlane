#include "AirPlane.h"


//全部变量
User_Linklist *user_linklist=NULL;
AirPlane_Linklist *airplane_linklist=NULL;
Current_User_information current_user_information;

int main(){
    //创建用户表头
    user_linklist = creat_User_Linklist();
    if(user_linklist == NULL){
        printf("creat_User_Linklist is NULL");
        return -1;
    }

    //创建用户链表表头
    airplane_linklist = creat_AirPlane_Linklist();
    if(airplane_linklist == NULL){
        printf("creat_AirPlane_Linklist is NULL");
        return -1;
    }
    
    main_menu();
    return 0;
}
/***********************界面函数实现*******************************/

/*display  */
void main_menu_display(void)
{
    printf("**********************机票购买系统**************\n");
    printf("*********************1.会员入口*****************\n");
    printf("********************2.管理员入口****************\n");
    printf("*********************0.退出系统*****************\n");
    printf("你的选择:"); 
}
void huiyuan_menu_display(void){
    printf("****************1.会员登陆****************\n");
    printf("****************2.会员注册****************\n");
    printf("****************0.退出********************\n");
    printf("你的选择:"); 
}
void huiyuan_caozuo_display(void){
    printf("****************1.查询航班信息****************\n");
    printf("****************2.查询个人信息****************\n");
    printf("****************3.购买机票****************\n");
    printf("****************0.退出********************\n");
    printf("你的选择:"); 
}
void guanliyuan_menu_display(void){
    printf("****************1.查看会员信息****************\n");
    printf("****************2.录入航班信息****************\n");
    printf("****************3.查询所有航班信息****************\n");
    printf("****************4.查询航班信息（通过航班号）****************\n");
    printf("****************5.删除航班信息（通过航班号）****************\n");
    printf("****************0.退出********************\n");
    printf("你的选择:"); 
}

void main_menu(void){
    int main_menu_choose_number=10;
    while(main_menu_choose_number!=0)           //输入0 退出
    {
        
        main_menu_display();
        scanf("%d",&main_menu_choose_number);   //不会处理回车
        getchar();
        switch (main_menu_choose_number)
        {
            case 1:             //会员入口
                huiyuan_menu();
            break;
            case 2:             //管理员入口
                
                guanliyuan_menu();
 
            break; 
            case 0:             //退出界面
                main_menu_choose_number = 0;
            break;
            default:
                printf("输入无效,请重新输入！！！\n");
                main_menu_choose_number =10;    //
            break;
        }
        printf("\n\n");
    }
    return ; 
}


void huiyuan_menu(void){
    int huiyuan_menu_number=10;

    char huiyuan_password[20];
    char huiyuan_name[20];

    while(huiyuan_menu_number!=0){
        
        huiyuan_menu_display();
        scanf("%d",&huiyuan_menu_number);
        getchar();
        switch (huiyuan_menu_number)
        {
            case 1:                 //会员登陆
                huiyuan_login();
            break;
            case 2:                 //会员注册
                User_Linklist_insert(user_linklist);
            break;
            case 0:                 //退出
                huiyuan_menu_number =0;
            break;   
            default:
                system("cls");
                printf("输入无效,请重新输入！！！\n");
                huiyuan_menu_number =10;    //
            break;
        }
        printf("\n\n");
    }
    return ;
}

void guanliyuan_menu(void){
    int guanliyuan_menu_number=10;
    char guanliyuan_password[20];
    char Flight[20];
    AirPlane_Linklist *p;
    printf("请输入管理员密码:");gets(guanliyuan_password);
    if(strcmp(guanliyuan_password,"1")==0){

        while(guanliyuan_menu_number !=0){
//           system("cls");
            guanliyuan_menu_display();
            scanf("%d",&guanliyuan_menu_number);
            getchar();
            switch (guanliyuan_menu_number)
            {
                case 1:         //查看会员信息    
                    User_Linklist_display(user_linklist);
                break;
                case 2:         //录入航班信息
                    AirPlane_Linklist_insert(airplane_linklist);
                break;
                case 3:         //所有航班信息
                    AirPlane_Linklist_display(airplane_linklist);
                break;
                case 4:         //查询航班信息（通过航班号）
                    printf("请输入航班号：");gets(Flight);
                    p=AirPlane_Linklist_Flight_seek(airplane_linklist,Flight);
                    if(p!=NULL){
                        printf("航班号：      %s\n",    p->Flight);
                        printf("起飞时间：    %s\n",    p->TakeOffTime);
                        printf("降落时间：    %s\n",    p->ReverceTime);
                        printf("出发地：      %s\n",    p->Origin);
                        printf("目的地：      %s\n",    p->Dest);
                        printf("票价：        %.2f\n",  p->Price);
                        printf("折扣：        %s\n",    p->Disscount);
                        printf("票价：        %d\n",    p->iNum);
                        printf("\n");
                    }else
                    {
                        printf("未查询到相关信息！！\n");
                    }
                    
 
                break;
                case 5:         //删除航班信息（通过航班号）
                    AirPlane_Linklist_Flight_delet(airplane_linklist);
                break;
                case 0:         //退出
                    guanliyuan_menu_number = 0; 
                return ;
                break;   
                default:
                    system("cls");
                    printf("输入无效,请重新输入！！！\n");
                    guanliyuan_menu_number =10;    //
                    
                break;
            }
            printf("\n");
        }
    }else{
         printf("密码错误\n");
    }
    return ;
}

void huiyuan_caozuo_menu(void){
    int huiyuan_caozuo_menu_number=10;
    User_Linklist*p;

    while(huiyuan_caozuo_menu_number !=0){
        huiyuan_caozuo_display();
        scanf("%d",&huiyuan_caozuo_menu_number);
        getchar();
        switch(huiyuan_caozuo_menu_number)
        {
            case 1:     //查询航班信息
                AirPlane_Linklist_display(airplane_linklist);
            break;
            case 2:     //查询个人信息 并显示
                p = User_Linklist_Name_seek(user_linklist,current_user_information.Name);
                if(p!=NULL){
                    printf("会员编号：  %d\n",    p->huiyuan_number);
                    printf("姓名：      %s\n",    p->Name);
                    printf("密码：      %s\n",    p->Password);
                    printf("生日：      %s\n",    p->Brithday);
                    printf("邮箱：      %s\n",    p->PostBox);
                    printf("航班号：    %s\n",    p->Flight); 
                }else
                {
                    printf("未查询到相关信息！！\n");
                }
            break;
            case 3:   //购买机票
                Buy_Flight();
            break;
            case 0:         //退出
                huiyuan_caozuo_menu_number = 0; 
            return ;
            default:
                printf("输入无效,请重新输入！！！\n");
                huiyuan_caozuo_menu_number =10;    //
                
            break;
        }

    }
}
/*display  */

void huiyuan_login(void)
{
    char huiyuan_name[20];
    char huiyuan_password[20];
    User_Linklist*p=NULL;
    printf("请输入用户名:");gets(huiyuan_name);
    //通过名字查找
    p = User_Linklist_Name_seek(user_linklist,huiyuan_name);
    if(p ==NULL){
            printf("未注册，请注册！！\n");
            return ;
    }
    printf("请输入密码:");gets(huiyuan_password);
    if(strcmp(huiyuan_password,p->Password)==0)
    {
        printf("登陆成功！！！！\n");

        //记录当前登陆的用户信息
        strcpy(current_user_information.Name,huiyuan_name);
        strcpy(current_user_information.Password,huiyuan_password);
        // printf("%s\n",current_user_information.Name);
        // printf("%s\n",current_user_information.Password);
        //进入用户操作界面
        huiyuan_caozuo_menu();
    }else
    {
        printf("密码错误\n");
    }
}


void Buy_Flight(void){

    char Flight[20];
    char i[10];
    User_Linklist *p;
    AirPlane_Linklist *q;
    
    printf("输入需购买的航班号：\r");gets(Flight);//输入需要购买的航班号
    //查找相应航班
    q=AirPlane_Linklist_Flight_seek(airplane_linklist,Flight);
    if(p!=NULL){
        printf("航班号：      %s\n",    q->Flight);
        printf("起飞时间：    %s\n",    q->TakeOffTime);
        printf("降落时间：    %s\n",    q->ReverceTime);
        printf("出发地：      %s\n",    q->Origin);
        printf("目的地：      %s\n",    q->Dest);
        printf("票价：        %.2f\n",  q->Price);
        printf("折扣：        %s\n",    q->Disscount);
        printf("票数：        %d\n",    q->iNum);
        printf("\n");
    }else
    {
        printf("未查询到相关信息！！\n");
    }
    printf("是否购买(1:买 0:不买并退出):\r");gets(i);
    if(strcmp(i,"1")==0){
        p=User_Linklist_Name_seek(user_linklist,current_user_information.Name);
        //返回航班信息，票数
        if(q->iNum!=0){
            strcat(p->Buy_jilu,Flight);  
            strcpy(p->Flight,Flight);
            q->iNum -=1;
            printf("购买成功\n");
        }else{
            if(q->iNum==0)
            {
                printf("购买不成功，卖完了\n");
            }
        }
    }else
    {
            return ;
    }
    
}

/*******************用户链表功能函数实现*************************/
//创建用户链表
User_Linklist *creat_User_Linklist(void){
    User_Linklist *node;
    node = (User_Linklist*)malloc(sizeof(User_Linklist));       //申请内存空间
    if(node==NULL){
        printf("creat_User_Linklist error\n");
        return NULL;
    }
    memset(node, 0, sizeof(User_Linklist)); //清空
    node->huiyuan_number=-1;        //初始的会员编号
    node->next = NULL;
    return node;
}

//增加用户
void User_Linklist_insert (User_Linklist*list){
    User_Linklist *node;
    User_Linklist *p;

    /*判断list链表是否为空*/
    if(list==NULL){
        printf("User_Linklist_insert error\n");
        return ;
    }

    p=list;

    /*将指针指向链表的尾部，在链表尾部添加用户信息*/
    while(p->next != NULL){
        p=p->next; 
    }

    //创建新节点
    node = (User_Linklist*)malloc(sizeof(User_Linklist));           
    if(node==NULL){     //判断是否申请内存成功
        printf("User_Linklist_insert creat_User_Linklist error\n");
        return ;
    }

    memset(node, 0, sizeof(User_Linklist));     //清空数据

    /*输入注册信息*/
    printf("名字:\t");gets(node->Name);
    printf("密码:\t");gets(node->Password);
    printf("生日:\t");gets(node->Brithday);
    printf("邮箱:\t");gets(node->PostBox);

    //设置会员编号
    node->huiyuan_number = p->huiyuan_number+1; 

    //使链表尾部指向新节点，添加新节点
    p->next = node;
    node->next = NULL;
    printf("注册成功！\n");
    return ;
}

int User_Linklist_delete(User_Linklist*list,char *Name){
    User_Linklist *p,*q;
    /*判断list链表是否为空*/
    if(list==NULL){
        printf("User_Linklist_insert error\n");
        return -1;
    }
    q = list;
    p = q->next;
    if(p==NULL)
    {
        printf("当前链表没有用户！！\n");
        return -1 ;
    }
    while(p!=NULL)
    {
        if(strcmp(Name,p->Name)==0) /*作比较,并显示*/
        {
            q->next = p->next;
            free(p);                //释放内存空间
            p =  q->next;
        }else{
            q=p;
            p=p->next;
        }
    }
    printf("删除成功！！！\n");
    return 0;
}


//显示用户列表（管理员）
void User_Linklist_display(User_Linklist*list){
    User_Linklist *p,*q;
    /*判断list链表是否为空*/
    if(list==NULL){
        printf("User_Linklist_insert error\n");
        return -1;
    }
    q = list;
    p = q->next;
    printf("会员信息如下：\n");
    printf("--------------------------------\n");
    while(p!=NULL)
    {
        /*输出信息*/
        printf("会员编号：  %d\n",    p->huiyuan_number);
        printf("姓名：      %s\n",    p->Name);
        printf("密码：      %s\n",    p->Password);
        printf("生日：      %s\n",    p->Brithday);
        printf("邮箱：      %s\n",    p->PostBox);
        printf("航班号：    %s\n",    p->Flight);
        printf("购买记录：  %s\n",    p->Buy_jilu);
        printf("\n");
        q=p;
        p=p->next;
    }
    printf("\n");
    printf("--------------------------------\n");
}


//登陆时使用返回类用户信息
User_Linklist* User_Linklist_Name_seek(User_Linklist*list,char *Name){
    User_Linklist *p,*q;
    /*判断list链表是否为空*/
    if(list==NULL){
        printf("User_Linklist_insert error\n");
        return -1;
    }
    q = list;
    p = q->next;
    if(p==NULL)
    {
        printf("当前链表没有用户！！\n");
        return NULL ;
    }
    while(p!=NULL)
    {
        if(strcmp(Name,p->Name)==0) /*作比较,并显示*/
        {
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}

/*******************用户链表功能函数实现*************************/
/*******************航班链表功能函数实现*************************/

//创建航班链表
AirPlane_Linklist* creat_AirPlane_Linklist(void){
    AirPlane_Linklist *node;
    node = (AirPlane_Linklist*)malloc(sizeof(AirPlane_Linklist));
    if(node==NULL){
        printf("creat_AirPlane_Linklist error\n");
        return NULL;
    }
    memset(node, 0, sizeof(AirPlane_Linklist));
    node->next = NULL;
    return node;
}

//增加航班信息
void AirPlane_Linklist_insert (AirPlane_Linklist*list){
    AirPlane_Linklist *node;
    AirPlane_Linklist *p;
    if(list==NULL){
        printf("AirPlane_Linklist_insert error\n");
        return ;
    }
    p=list;
    //指针指向最后一个数据
    while(p->next != NULL){
        p=p->next;      //如果下一个数据不为空，则指向下一个数据
    }
    node = (AirPlane_Linklist*)malloc(sizeof(AirPlane_Linklist));
    if(node==NULL){
        printf("User_Linklist_insert creat_User_Linklist error\n");
        return ;
    }
    memset(node, 0, sizeof(AirPlane_Linklist));         //将node指向的空间清0
    /*输入航班信息*/
    printf("航班号:     \t");gets(node->Flight);
    printf("起飞时间:   \t");gets(node->TakeOffTime);
    printf("降落时间:   \t");gets(node->ReverceTime);
    printf("出发地:     \t");gets(node->Origin);
    printf("目的地:     \t");gets(node->Dest);
    printf("票价:       \t");scanf("%f",&node->Price);
    getchar();     //吸收多余字符
    printf("折扣:       \t");gets(node->Disscount);
    printf("剩余票数：  \t");scanf("%d",&node->iNum);
    getchar();     //吸收多余字符

    p->next = node;
    node->next = NULL;
    printf("添加成功！\n");
    printf("\n");
    return ;    
}

void AirPlane_Linklist_Flight_delet(AirPlane_Linklist*list)
{
    AirPlane_Linklist *p,*q = list;
    int i=0;
    p = q->next;
    char Flight[20]; 
    printf("请输入航班号：");gets(Flight);
    while(p!=NULL)
    {
        if(strcmp(Flight,p->Flight)==0)
        {
            q->next = p->next;
            memset(p,0,sizeof(AirPlane_Linklist));
            i++;
            p=q->next;

        }else{
            q=p;
            p=p->next;
        }
    }   
    printf("已删除个数：%d\n",i);
}
//显示航班信息
void AirPlane_Linklist_display(AirPlane_Linklist*list){
    AirPlane_Linklist *p,*q = list;
    p = q->next;
    if(p==NULL)
    {
        printf("没有航班信息\n");
        return ;
    }
    printf("所有航班信息如下：\n");
    printf("----------------------------------------------------\n");
    while(p!=NULL)
    {
        /*输出信息*/
        printf("航班号：      %s\n",    p->Flight);
        printf("起飞时间：    %s\n",    p->TakeOffTime);
        printf("降落时间：    %s\n",    p->ReverceTime);
        printf("出发地：      %s\n",    p->Origin);
        printf("目的地：      %s\n",    p->Dest);
        printf("票价：        %.2f\n",  p->Price);
        printf("折扣：        %s\n",    p->Disscount);
        printf("数量：        %d\n",    p->iNum);
        printf("\n");
        q=p;
        p=p->next;
    }
    printf("----------------------------------------------------\n");
    printf("\n");
    return ;
}

//通过航班号    查询航班信息
AirPlane_Linklist* AirPlane_Linklist_Flight_seek(AirPlane_Linklist*list,char *Flight)
{
    AirPlane_Linklist *p,*q = list;
    p = q->next;
    if(p==NULL)
    {
        printf("没有航班信息\n");
        return NULL;
    }
    
    while(p!=NULL)
    {
        if(strcmp(Flight,p->Flight)==0)
        {
           
        }else if(p->next == NULL)
        {
            printf("未查询到该航班信息\n");
            return NULL;
        }
        q=p;
        p=p->next;
    }
    printf("----------------------------------------------------\n");
    return 0;
}
/*******************航班链表功能函数实现*************************/
/*********************************用户链表及航班链表相关功能函数实现*************************/

