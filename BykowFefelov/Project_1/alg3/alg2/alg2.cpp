// alg2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
class queue//класс очередь
{
public:
	char name[255];
	int val;
	queue *next;
	queue *head;
	void add(int x,char *s);
	int get(int *x,char *s);
	void display();
	queue();
};
//методы класса очередь
queue::queue()//конструктор
{
	val=0;
	next=NULL;
	head=this;
	for(int i=0;i<255;i++)
	{
		name[i]=0;
	}
}
void queue::display()
{
	printf("\nqueue:\n");
	queue *y;
	y=this->next;
	for(;y!=NULL;)
	{
		printf("%d %s\n",y->val,y->name);
		y=y->next;
	}
}
int queue::get(int *x,char *s)
{
	if(this->head->next!=NULL)
	{
		head=this->head->next;
		*x=this->head->val;
		strcpy(s,this->head->name);
		return 0;
	}
	else
	{
		return 1;
	}
}
void queue::add(int x, char *s)
{
	queue *y=new queue();
	queue *yy=this->head;//чтобы не портить указатель на голову списка
	y->val=x;
	strcpy(y->name,s);//теперь в y новый элемент в очереди
		if(yy->next==NULL)
		{
			y->next=yy->next;
			yy->next=y;
			goto end;
		}//конец списка, записываем элемент на первое место и выходим из цикла		
		if(x<=yy->next->val)//проверяем очередное число пока не найдем конец списка или место для вставки
		{
			do
			{
				yy=yy->next;
				if(yy->next==NULL)
				{
					goto end2;
				}
			}
			while(x<=yy->next->val);
			end2:;
			y->next=yy->next;
			yy->next=y;
			goto end;
		}
		if(x>yy->next->val)//если очередной приоритет элемента больше всех то его на первое место
		{
			y->next=yy->next;
			this->head->next=y;
			goto end;
		}	
	end:;
}


int _tmain(int argc, _TCHAR* argv[])
{
	queue *q=new queue();//очередь
	char s[255];
	int i,x;
	FILE *f;
	i=1;
	f=fopen ("in.txt", "r"); // Инициализация файлового потока
	if(f==NULL)
	{
		printf("error");
	}
	for(;feof(f)==0;)
	{
		fscanf(f,"%d %s",&x,s);
		q->add(x,s);
		i=0;
	}
	q->display();
	fclose(f);
	f=fopen ("out.txt", "w"); // Инициализация файлового потока
	if(f==NULL)
	{
		printf("error");
	}
	for(;i==0;)
	{
		i=q->get(&x,s);
		if(i==0)
		{
			fprintf(f,"%d %s\n",x,s);
		}
	}
	fclose(f);
	system("pause");//пауза
	return 0;
}

