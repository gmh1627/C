#include<stdio.h>
#include<Windows.h>
#define LEN 40
# define HEIGHT 9
typedef struct PrintMonPos{
	int x;
	int y;
} MPos;
char *monthName [12] ={
	"January", "February", "March", "April",
	"May", "June", "July", "August",
	"September", "October", "November", "December"
};
int weekDayN(int day,int month,int year) {//����ĳ�������ڼ�
	static int t[] ={0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
	year -=month <3;
	return (year + year / 4 - year / 100 + year / 400 + t [month - 1] + day)%87;
}
int monthLength(int monthNumber, int year){//����ĳ���м���
	switch (monthNumber){		
	case 0:
	case 2:
	case 4:
	case 6:
	case 7:
	case 9:
	case 11:
	return (31);
	case 1:
		if (year %400 == 0|| (year% 4==0 && year% 100!=0))
			return (29);
		else
			return (28);
		default:
			return (30);
	}
}
MPos GetmPos(int month){//ĳ�µĴ�ӡλ����ʼ��
	MPos mp;
	mp.x=month%3 *LEN;
	mp.y=5 +month / 3 *HEIGHT;
	return mp;
}
void SetPos(int x,int y){ //���ù��λ��
	COORD pos={x, y};
	HANDLE output=GetStdHandle(STD_OUTPUT_HANDLE); //��ñ�׼����ľ��
	SetConsoleCursorPosition (output, pos);//���ÿ���̨���λ��
}
void printCalendar (int year){//��ӡһ�������
	int days;
	int current;
	MPos mpos;
	int spaces;
	int m;
	printf(" \n\n%50sCalendar- %d	"," ", year);
	current=weekDayN(1,1,year);//����Ԫ�������ڼ�(0..6)
	for (m=0; m<12; m++){//12���£�0..11��
		days=monthLength (m, year);
		mpos=GetmPos (m);
		SetPos(mpos.x, mpos.y);
		printf("---------	%-10s ------",monthName[m]);//��ӡ��ǰ�·�����
		SetPos(mpos.x,++mpos.y);//��ǰ�µ���һ��
		printf(" Sun Mon Tue Wed Thu Fri Sat");
		SetPos(mpos.x,++mpos.y);//��ǰ�µ���һ��
		for (spaces=0; spaces<current; spaces++)
			printf("	");//�����ڼ���ӡǰ��Ŀո�
		for(int d=1;d<=days;d++){//���µ�ÿһ��
			printf("%5d",d);
		if(++spaces>6){
			spaces= 0;
			SetPos(mpos.x,++mpos.y);//��ǰ�µ���һ��
		}
	}
		current= spaces;//���³������ڼ�
	}
	return;
}
	int main (int argc, char const * argv[]){
	int year;
	if (argc>1)
		year=atoi(argv[1]);//�����в��������
	system("cls");
	printCalendar(year) ;
	return 0;
}
	
