#include<iostream>
using namespace std;
typedef struct Node //������ṹ
{
	int data;
	struct Node *next;
}*Pointer;
void printlist(Pointer Head) //���һ������
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
	cout<<"˳���Ϊ:"<<endl;
	int i=1;          //����һ����1��n������
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
	printlist(Head);   //����printlist��������������
	cout<<"��������:"<<endl;
	p->next=Head->next;//����ѭ������
	p=Head->next;      //����Լɪ��
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
		r->next=p->next;  //�޸�ָ�룬ɾ����������
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
	

