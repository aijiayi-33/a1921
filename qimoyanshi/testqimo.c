#include "qimo.h"
int main(){
	seqstack A,B;
	InitStack(&A);
	InitStack(&B);
//值等于栈顶 
	int i;
//	initscr();
	do{
		menu();
//		printw("\n\n");
		printf("  please input(0 - 7):");
		scanf("%d",&i);
//		clear();
		printf("\n\n");
		switch(i){
			case 1:push(&A,&B);
				   	break;  //创建top 
			case 2:pop(&A);
					break;
			case 3:find(&A);
					break;	
			case 4:outdata(&A);
					break;
			case 5:Print(&A);
					break;
			case 6:del(&A,&B);
					break;
			case 7:save(&A);
					break; 
			case 0:
			       printf("正在退出该系统，欢迎下次使用！\n\n");
					for(int i=0;i<30;i++){
						printf("<<"); 
					}
					system("cls");
					break; 
			default:
		//			move(40,60);
				printf("请输入正确的选项！\n\n");
					system("pause");
					system("cls");;
					break; 
		}
	}while(i!=0);
//	getch();
//	endwin();
	return 0;
}
