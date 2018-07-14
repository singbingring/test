#include<iostream>
using namespace std;
typedef struct Node //定义结点结构
{
	int data;
	struct Node *next;
}*Pointer;
void printlist(Pointer Head) //输出一个链表
{
	Pointer p=Head->next;
	while(p!=NULL)
	{
		cout<<p->data<<"";
		p=p->next;
	}
	cout<<endl;
}
void creatlist(int n,int m) 
{
	cout<<"顺序表为:"<<endl;
	int i=1;          //建立一个从1到n的链表
	Pointer Head=new Node;
	Head->next=NULL;
	Pointer p=Head;
	while(i<=n)
	{
		Pointer q=new Node;
		q->data=i;
		q->next=NULL;
		p->next=q;
		p=q;
		i++;
	}                 
	printlist(Head);   //调用printlist函数输出这个链表
	cout<<"出队序列:"<<endl;
	p->next=Head->next;//构成循环链表
	p=Head->next;      //构建约瑟夫环
	Pointer r=Head;
	int j;
	while(p->next!=p)
	{
		j=1;
		while(j<m)
		{
			r=r->next;
			p=p->next;
			j++;
		}
		cout<<p->data<<"";
		r->next=p->next;  //修改指针，删除以输出结点
		delete(p);    
		p=r->next;
	}
	cout<<p->data<<endl;
}
void main()
{
	int m=4;
	int n=8;
	creatlist(n,m);
	system("pause");
}
	

