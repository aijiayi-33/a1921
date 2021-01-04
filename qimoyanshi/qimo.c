#include "qimo.h"


void InitStack(seqstack *S1){	//栈初始化
	S1->top=-1;
}
int StackEmpty(seqstack *S1){	//判断栈是否空
	if(S1->top==-1) return 1;
	else return 0;
}
int StackFull(seqstack *S1){	//判断栈是否满
	if(S1->top==size-1)return 1;
	else return 0;
}

void push(seqstack *S1,seqstack *S2){	
	int i,n,m,j=0;
	time_t t;
   	struct tm * lt;
   	time (&t);//获取Unix时间戳。
   	lt = localtime (&t);//转为时间结构。
	struct Data p;
	m=(lt->tm_year+1900)*365+(lt->tm_mon)*30+lt->tm_mday;
	printf("------------欢迎进入仓库入库界面！------------\n\n\n");
	if(StackFull(S1))printf("\t*仓库已满，无法入库！");
	else{
	printf("该仓库最大容量为%d!,仓库已有%d件货物！\n\n",size,S1->top+1);


	
	do{
		fflush(stdin);
		printf("\n请输入本次入库的件数：");	
		scanf("%d",&n);
		if(n+S1->top+1>size) printf("\n该货架最大容量为%d且货架已有%d件货物！请重新输入！\n\n",size,S1->top+1);
	}while(n+S1->top+1>size);  
	for(j=0;j<n;j++){
		printf("\n请输入第%d件货物的信息：\n",j+1);
		printf("货物名称：");
		scanf("%s",p.name);
		printf("\n\t货物编号：");
		scanf("%d",&p.num_1); 
	do{
		printf("\n\t***生产日期：");	
		scanf("%d.%d.%d",&p.year,&p.month,&p.day);
		if((p.year*365+(p.month-1)*30+p.day)>m||p.year<=0||p.year<(lt->tm_year+1890)||p.month<=0||p.month>12||p.day<=0||p.day>30)
		printf("\n输入的生产日期不对！请重新输入！\n");
		}while((p.year*365+(p.month-1)*30+p.day)>m||p.year<=0||p.year<(lt->tm_year+1890)||p.month<=0||p.month>12||p.day<=0||p.day>30);
	do{
		printf("\n\t***货物数量:");
		scanf("%d",&p.num);
		if(p.num<=0) printf("\n输入出错！请重新输入！\n");
	}while(p.num<=0);  
		printf("\n\t***保质期(天)：");
		scanf("%d",&p.data);
		i=1;
	while(S1->top!=-1&&((p.year*365+(p.month-1)*30+p.day)-(S1->sp[S1->top].year*365+(S1->sp[S1->top].month-1)*30+S1->sp[S1->top].day))>0){		
		S2->top++;
		S2->sp[S2->top]=S1->sp[S1->top];
		S1->top--;				
	}
	S1->top++;
	S1->sp[S1->top]=p;
	for(;S2->top>-1;S2->top--){
		S1->top++;
		S1->sp[S1->top]=S2->sp[S2->top];
		} 
	}
	if(i==1) printf("\n货物入库成功"); 
 }printf("\n\n\n返回上一级菜单");
 system("pause");
system("cls");
}

/*void paixu(seqstack *S1){
	int i,j;
	for(i=1;i<size;i++){
		for(j=1;j<size-1;j++){
			if(num_1 
*/
		


void find(seqstack *S1){	//查询界面
	int n,j;
	printf("************欢迎进入仓库货物查询界面！*********\n\n");
	if(StackEmpty(S1)) printf("\n\t****仓库为空,无法查询,请先添加货物！*****\n"); 	
	else{
	do{
		printf("\n【按** 生产日期年月日 **查询输入1】\n【按年月查询输入2】\n【按** 数量 **查询输入3】\n【退出查询界面输入0】"); 
		printf("\n\n\n****请选择您的选项：");
		scanf("%d",&n);	
		switch(n){ 
			case 1: {		//按生产日期查询
				int i = 0;
				int year,month,day;
				printf("\n**************请输入要查询的日期：");
				scanf("%d.%d.%d",&year,&month,&day); 
				for(j=S1->top;j>=0;j--){
				if(S1->sp[j].year==year&&S1->sp[j].month==month&&S1->sp[j].day==day){
				if(i==0) printf("\n%d年%d月%d日生产的货物如下：\n\n",year,month,day); 	//存在该货件
				if(i==0) printf("\t货物名称\t货物编号\t生产日期\t保质期(天)\t货物数量**\n\n");
				printf("\t%s",S1->sp[j].name);
				printf("\t%d",S1->sp[j].num_1); 
				printf("\t\t%d.%d.%d",S1->sp[j].year,S1->sp[j].month,S1->sp[j].day);
				printf("\t%d",S1->sp[j].data);
				printf("\t\t%d",S1->sp[j].num);
				printf("\n\n");
				i=1;
				}	
			}
				if(i==0) printf("\n\n\t无%d.%d.%d生产的货物\n",year,month,day);
                                printf("\n\n-------------\n\n");
                                break;	
				}
			case 2:{
				int i=0;
				int year,month;
				printf("%d.%d",year,month);
				scanf("%d.%d",&year,&month);
				for(j=S1->top;j>=0;j--){
				if(S1->sp[j].year==year&&S1->sp[j].month){
				if(i==0) printf("\n%d年%d月生产的货物如下：\n\n",year,month);
				if(i==0) printf("\t货物名称\t货物编号\t生产日期\t保质期(天)\t货物数量**\n\n");
				printf("\t%s",S1->sp[j].name);
				printf("\t%d",S1->sp[j].num_1);
				printf("\t\t%d.%d.%d",S1->sp[j].year,S1->sp[j].month,S1->sp[j].day);
				printf("\t%d",S1->sp[j].data);
				printf("\t\t%d",S1->sp[j].num);
				printf("\n\n");
				i=1;
				}
			}
				if(i==0) printf("\n\n\t无%d年%d月生产的货物\n",year,month);
				printf("\n\n-------------\n\n");
				break;
				}

			case 3:
				{int num1,num2;		//按数量查询
				int i=0;
				printf("\n请输入要查询的数量：(少于）");
				scanf("%d",&num1); 
				printf("\n请输入要查询的数量:（多于）");
				scanf("%d",&num2);
				for(j=S1->top;j>=0;j--){
				if(S1->sp[j].num<=num1&&S1->sp[j].num>=num2){
				if(i==0) printf("\n货架上%d件以下%d以上的货物如下：\n\n",num1,num2);  
				if(i==0) printf("\t货物名称\t货物编号\t生产日期\t保质期(天)\t货物数量**\n\n");		//存在该区间的货物
				printf("\t%s",S1->sp[j].name);
				printf("\t%d",S1->sp[j].num_1); 
				printf("\t%d.%d.%d",S1->sp[j].year,S1->sp[j].month,S1->sp[j].day);
				printf("\t%d",S1->sp[j].data);
				printf("\t%d",S1->sp[j].num);
				printf("\n\n");
				i=1;
				}
			}
				if(i==0) printf("\n\n\t无 %d 件以下 %d件以上的货物!\n",num1,num2); 		//无此类货物
				printf("\n******************************************\n\n"); 
				break;
			}
		}
		}while(n!=0);
	}printf("\n\n返回上一级菜单"); 
	system("pause");
	system("cls");		
}
//void sort(){
void Print(seqstack *S1){		//仓库的货物信息
	int j;
	printf("***********欢迎进入仓库清单界面！**********\n\n\n");
	if(StackEmpty(S1)) printf("\t*仓库为空,请先添加货物！*\n"); 	//仓库空
	else{
		print1(S1);
	}
	printf("\n\n返回上一级菜单");
	system("pause");
	system("cls"); 
}

void print1(seqstack *S1){
	int j;
	printf("*****仓库清单如下：*****\n\n");
	printf("\t货物名称\t货物编号\t生产日期\t保质期(天)\t货物数量\n\n");

	for(j=S1->top;j>=0;j--){
		printf("\t%s",S1->sp[j].name);
		printf("\t%d",S1->sp[j].num_1); 
		printf("\t\t%d/%d/%d",S1->sp[j].year,S1->sp[j].month,S1->sp[j].day);
		printf("\t%d",S1->sp[j].data);
		printf("\t\t%d",S1->sp[j].num);
		printf("\n\n");
		}
} 

void pop(seqstack *S1){		//货物出库
	int j,num_1,num;
	printf("------------欢迎进入仓库出货界面！------------\n\n\n");
	if(StackEmpty(S1)) printf("\t*仓库为空,请先添加货物！\n");	///仓库空
	else{
		print1(S1);
		printf("请输入您要出库的货物的编号：");
		scanf("%d",&num_1);
		for(j=S1->top;j>=0;j--){
		if(S1->sp[j].num_1==num_1){
		do{
			fflush(stdin);		//输入的出库件数需小于该货件原本有的货件数量
			printf("\n请输入该货物出库数量：");
			scanf("%d",&num);
			if(num>S1->sp[j].num)
			printf("输入出错,请重新输入！\n"); 
			}while(num>S1->sp[j].num);
		S1->sp[j].num-=num;
		printf("\n\t出库成功！");
		if(S1->sp[j].num<20) printf("该货物数量小于20！\n");	//出库后数量小于20会提示入库
		break;
			}
	}
	}printf("\n\n*****返回上一级菜单*****"); 
	system("pause");
	system("cls");
} 

void del(seqstack *S1,seqstack *S2){	//删除货件
	char name[20];
	int num_1,T,j;
	struct Data p1;
	printf("------------欢迎进入货物删除界面！------------\n\n\n");
	if(StackEmpty(S1)) printf("\t*仓库为空,请先添加货物！\n");	//仓库空
	else{
	print1(S1);
	printf("请输入您要删除货物的编号：");
	scanf("%d",&num_1); 
	for(j=S1->top;j>=0;j--){
		if(S1->sp[j].num_1==num_1){
			while(S1->top>j){
				S2->top++;
				S2->sp[S2->top]=S1->sp[S1->top];
				S1->top--;
			}
			p1=S1->sp[S1->top];
			S1->top--;
			for(;S2->top>-1;S2->top--){
				S1->top++;
				S1->sp[S1->top]=S2->sp[S2->top];
			}
			printf("\n\n\t********删除成功！*****\n");
			break;}
		}
		}
	printf("\n\n返回上一级菜单");
	system("pause");
	system("cls"); 
}

/*void paixu(seqstack *S1){
	int j;
	int a[size];
	int i,k,q;
	for(j=S1->top;j>=0;j--)
		a[size] = S1->sp[j].num_1;
	for(i=1;i<size;i++){
		for(k=1;k<size-1;k++){
			if(a[k]>a[k+1]){
				q =a[k];
			       a[k] = a[k+1];
		       a[k+1] = q ;}
		}
	}
	for(j=S1->top;j<=size;j++){
printf("\t**货物编号\t生产日期\t保质期(天)\t货物数量**\n\n");
        printf("\t%d",S1->sp[j].num_1);
	        printf("\t\t%d/%d/%d",S1->sp[j].year,S1->sp[j].month,S1->sp[j].day);
		        printf("\t%d",S1->sp[j].data);
			        printf("\t\t%d",S1->sp[j].num);
				        printf("\n\n");}
}

*/
void outdata(seqstack *S1){		//打印过期货件
	int m,i=0,j;
	time_t t;
   	struct tm * lt;
   	time (&t);//获取Unix时间戳。
   	lt = localtime (&t);//转为时间结构。
    m=(lt->tm_year+1900)*365+(lt->tm_mon)*30+lt->tm_mday;	//当前系统时间
    if(StackEmpty(S1)) printf("\t*仓库为空,请先添加货物！\n");	//仓库空
    else{
	for(j=S1->top;j>=0;j--){
	if((S1->sp[j].year*365+(S1->sp[j].month-1)*30+S1->sp[j].day+S1->sp[j].data)<m){
	if(i==0) printf("**已过期的货物如下(今日日期为：%d.%d.%d)*:\n\n",lt->tm_year+1900,lt->tm_mon+1,lt->tm_mday);
	if(i==0) printf("\t货物名称\t货物编号\t生产日期\t保质期(天)\t货物数量**\n\n");
	printf("\t%s",S1->sp[j].name);
	printf("\t%d",S1->sp[j].num_1); 
	printf("\t\t%d/%d/%d",S1->sp[j].year,S1->sp[j].month,S1->sp[j].day);
	printf("\t%d",S1->sp[j].data);
	printf("\t\t%d",S1->sp[j].num);
	printf("\n\n");
	i=1;
		}
	}
	if(i==0) printf("\n\t仓库里无过期的货物!\n"); }
	printf("\n\n返回上一层,");
	system("pause");
	system("cls");
} 

void save(seqstack *S1){	//保存仓库内的货物信息
	int i,j;
	FILE *fp; 
	if(StackEmpty(S1)) printf("\t**仓库为空,请先添加货物！\n");   //仓库空
	else{
	fp=fopen("goods.txt","w");
	if(!fp){
		printf("文件不存在\n");
		return;
	}
	//将仓库货物信息写入文件
    fprintf(fp,"*************************货物信息一览表************************\n");
    fprintf(fp,"\n");
   	fprintf(fp,"货物名称\t货物编号\t\t生产日期\t\t保质期(天)\t\t货物数量\n\n");
   	for(j=S1->top;j>=0;j--){
		fprintf(fp,"\t%s",S1->sp[j].name);
		fprintf(fp,"\t%d",S1->sp[j].num_1); 
		fprintf(fp,"\t\t%d/%d/%d",S1->sp[j].year,S1->sp[j].month,S1->sp[j].day);
		fprintf(fp,"\t\t%d",S1->sp[j].data);
		fprintf(fp,"\t\t%d",S1->sp[j].num);
		fprintf(fp,"\n\n");
		}
    fclose(fp); 
    printf("****************数据已成功导入\n"); 
	printf("\n   ************保存成功！");
	}
   	printf("\n\n返回上一级菜单");
	system("pause");
	system("cls");
} 
void menu(){
	printf("\n\n\n");
	printf("************************* 仓库 ********************\n");
	printf("\n\n");
	system("color DF"); 
	printf("\t\t\t *********仓库管理系统*******************\n");
    printf("\t\t\t *****************************************\n");
    printf("\t\t\t **********请选择您要执行的操作   \n");
    printf("\t\t\t                                  \n");
    printf("\t\t\t *************1 货物入库         \n");
    printf("\t\t\t                                  \n");
    printf("\t\t\t *************2 货物出库          \n");
    printf("\t\t\t                                  \n");
    printf("\t\t\t *************3 查询货物          \n");
    printf("\t\t\t                                  \n");
    printf("\t\t\t *************4 过期货物          \n");
    printf("\t\t\t                                  \n");
    printf("\t\t\t *************5 仓库清单          \n");
    printf("\t\t\t                                  \n");
    printf("\t\t\t *************6 删除货物          \n");
    printf("\t\t\t                                  \n");
    printf("\t\t\t *************7 保存操作          \n");
    printf("\t\t\t                                  \n");
    printf("\t\t\t *************0 退出              \n");
    printf("\t\t\t                                  \n");
    printf("\t\t\t ******************************************\n");

}

