#ifndef qimo_h
#define qimo_h

#include <stdio.h>
#include <string.h>//字符串 
#include<time.h>//时间 
#include<stdlib.h>


#define size 1000    //仓库最大容量
//货物信息结构体
struct Data{
	char name[20];  //货物名称
    	int year;	//年份
    	int month;	//月份
    	int day;	//日期
	int num;	//数量 
	int data;	//保质期 
	int num_1; 	//货件编号
};
//定义顺序栈 
typedef struct{
	struct Data sp[size];
	int top;//栈顶 
}seqstack; 

void InitStack(seqstack *S1);
int StackEmpty(seqstack *S1);
int StackFull(seqstack *S1);
void push(seqstack *S1,seqstack *S2);
void pop(seqstack *S1);
void find(seqstack *S1);
void Print(seqstack *S1);
void outdata(seqstack *S1);
void print1(seqstack *S1);
void del(seqstack *S1,seqstack *S2);
void save(seqstack *S1);
void menu();

#endif
