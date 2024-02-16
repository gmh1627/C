#include<stdio.h>
#include<math.h>
float u_or_d(float x,float y,float x1,float y1,float x2,float y2)   //���������жϵ���ֱ���Ϸ������·� 
{
	if(x2!=x1)
	{
		float l=(x-x1)*(y2-y1)/(x2-x1)-(y-y1);
	    if(l>0&&abs(l-0)>1e-6) return 1;
	    else if(l<0&&abs(l-0)>1e-6) return -1; //������ֻ�������жϣ�����ֱ��дl!=0  
	    else return 0;//�жϵ���ֱ����
	}
	else if(x<x1&&x1-x>1e-6) return -1;   //����б�ʲ����� 
	else if(x>x1&&x-x1>1e-6) return 1;
	else return 0;
}
float length(float a1,float a2,float b1,float b2)   //���� 
{
	return sqrt((b2-a2)*(b2-a2)+(b1-a1)*(b1-a1));
}
float area(float a1,float a2,float b1,float b2,float c1,float c2)   //��� 
{
	float l=(length(a1,a2,b1,b2)+length(a1,a2,c1,c2)+length(b1,b2,c1,c2))/2;
	return sqrt(l*(l-length(a1,a2,b1,b2))*(l-length(a1,a2,c1,c2))*(l-length(b1,b2,c1,c2)));
}
int main()
{
    float a[2][5];
	printf("input x y:\n");
	for(int i=0;i<5;i++)
	{
		scanf("%f",&a[0][i]);
		scanf("%f",&a[1][i]);
	}
	int bian=0,m[4]={0},f,g=0;
	float s=0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = i + 1; j < 5; j++)      //i��j���������ӳɵ�����ֱ�� 
		{
			f = 0;
			for (int k = 0; k < 5; k++)
			{
				if (k != i && k != j)
					f += u_or_d(a[0][k], a[1][k], a[0][i], a[1][i], a[0][j], a[1][j]);
			}
			if (abs(f) == 3)     //����ͬ��������εı� 
				bian++;
			if (abs(f) == 1 && i == 0)   //���һ�����Ӧ�������Խ��� 
				m[j - 1] = f;
		}
	}//��������������+-3����������+-1 
	if(bian==5)   //��������͹������� ���������������Ե�һ����Ϊ��׼�ָ������������ 
	{
		for(int i=1;i<5;i++)
		{
			if(abs(m[i-1])==1) //Ѱ�ҸղŴ�ĶԽ��� 
			{
				for(int k=1;k<5;k++)
				{
					if(u_or_d(a[0][k],a[1][k],a[0][i],a[1][i],a[0][0],a[1][0])*m[i-1]==-1&&k!=i) //�Խ���һ��ֻ��k��һ���㣬��������Χ�������ε���� 
					 s+=area(a[0][k],a[1][k],a[0][i],a[1][i],a[0][0],a[1][0]);
					if(abs(m[k-1])==1&&k>i)   //�����Խ���Χ�������ε���� 
					 s+=area(a[0][k],a[1][k],a[0][i],a[1][i],a[0][0],a[1][0]);
				}
			}
		}
		printf("result:%f",s);
	}
	else printf("false input");
	return 0;
}
