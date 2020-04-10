#include<iostream>
#include<malloc.h>
#include<string>
using namespace std;
unsigned int lunartable[199] = {
    0x04AE53,0x0A5748,0x5526BD,0x0D2650,0x0D9544,0x46AAB9,0x056A4D,0x09AD42,0x24AEB6,0x04AE4A,
    0x6A4DBE,0x0A4D52,0x0D2546,0x5D52BA,0x0B544E,0x0D6A43,0x296D37,0x095B4B,0x749BC1,0x049754,
    0x0A4B48,0x5B25BC,0x06A550,0x06D445,0x4ADAB8,0x02B64D,0x095742,0x2497B7,0x04974A,0x664B3E,
    0x0D4A51,0x0EA546,0x56D4BA,0x05AD4E,0x02B644,0x393738,0x092E4B,0x7C96BF,0x0C9553,0x0D4A48,  
    0x6DA53B,0x0B554F,0x056A45,0x4AADB9,0x025D4D,0x092D42,0x2C95B6,0x0A954A,0x7B4ABD,0x06CA51,
    0x0B5546,0x555ABB,0x04DA4E,0x0A5B43,0x352BB8,0x052B4C,0x8A953F,0x0E9552,0x06AA48,0x7AD53C,
    0x0AB54F,0x04B645,0x4A5739,0x0A574D,0x052642,0x3E9335,0x0D9549,0x75AABE,0x056A51,0x096D46,
    0x54AEBB,0x04AD4F,0x0A4D43,0x4D26B7,0x0D254B,0x8D52BF,0x0B5452,0x0B6A47,0x696D3C,0x095B50,
    0x049B45,0x4A4BB9,0x0A4B4D,0xAB25C2,0x06A554,0x06D449,0x6ADA3D,0x0AB651,0x093746,0x5497BB,
    0x04974F,0x064B44,0x36A537,0x0EA54A,0x86B2BF,0x05AC53,0x0AB647,0x5936BC,0x092E50,0x0C9645,
    0x4D4AB8,0x0D4A4C,0x0DA541,0x25AAB6,0x056A49,0x7AADBD,0x025D52,0x092D47,0x5C95BA,0x0A954E,
    0x0B4A43,0x4B5537,0x0AD54A,0x955ABF,0x04BA53,0x0A5B48,0x652BBC,0x052B50,0x0A9345,0x474AB9,
    0x06AA4C,0x0AD541,0x24DAB6,0x04B64A,0x69573D,0x0A4E51,0x0D2646,0x5E933A,0x0D534D,0x05AA43,
    0x36B537,0x096D4B,0xB4AEBF,0x04AD53,0x0A4D48,0x6D25BC,0x0D254F,0x0D5244,0x5DAA38,0x0B5A4C,
    0x056D41,0x24ADB6,0x049B4A,0x7A4BBE,0x0A4B51,0x0AA546,0x5B52BA,0x06D24E,0x0ADA42,0x355B37,
    0x09374B,0x8497C1,0x049753,0x064B48,0x66A53C,0x0EA54F,0x06B244,0x4AB638,0x0AAE4C,0x092E42,
    0x3C9735,0x0C9649,0x7D4ABD,0x0D4A51,0x0DA545,0x55AABA,0x056A4E,0x0A6D43,0x452EB7,0x052D4B,
    0x8A95BF,0x0A9553,0x0B4A47,0x6B553B,0x0AD54F,0x055A45,0x4A5D38,0x0A5B4C,0x052B42,0x3A93B6,
    0x069349,0x7729BD,0x06AA51,0x0AD546,0x54DABA,0x04B64E,0x0A5743,0x452738,0x0D264A,0x8E933E,
    0x0D5252,0x0DAA47,0x66B53B,0x056D4F,0x04AE45,0x4A4EB9,0x0A4D4C,0x0D1541,0x2D92B5          };
int main (void)
{
	int year,month,day;
	cout << "please inuput he date " << endl;
	cin >> year >> month >> day;
	string branch(int iyear);
	string zodiac(int iyear);
	int run(int iyear);
	int mon(int imonth,int si);
	int lunarmonth,lunarday,luwday,lusi;
	string week(int iyear,int imonth,int iday);
	string bran;
	string zodi;
	string wen;
	bran=branch(year);
	zodi=zodiac(year);
	wen=week(year,month,day);
	int mos[12] = {0,31,59,90,120,151,181,212,243,273,304,334};
	int springday,nowday,siyear;
	siyear=year-1901;
	if((lunartable[siyear]&0x0060>>5)==1)
		springday=(lunartable[siyear]&0x001F)-1;
	else 
		springday=(lunartable[siyear]&0x001F)-1+31;
	nowday=mos[month-1]+day-1;
	 if((run(year)==1)&&(month>2))
		 nowday=nowday+1;
	 if(nowday>=springday)
	 {
		 int siday,lumon=1,luday;
		 int simon=1;
		 int sirun=0;
		 int dayofmonth;
		 siday=nowday-springday;
		 luwday=siday+1;
		 if((lunartable[siyear] & 0x80000) >> (simon-1)==0)
			 dayofmonth=29;
		 else 
			 dayofmonth=30;
		 int i;
		 for(i=0;siday>dayofmonth;i++)
		 {	
			siday=siday-dayofmonth;
			simon++;
			if(lumon==((lunartable[siyear] & 0xF00000) >> 20))
			{
			sirun=~sirun;
			if(sirun==0)
			lumon++;
			}
			else
			lumon++;
			if((lunartable[siyear] & 0x80000) >> (simon-1)==0)
			dayofmonth=29;
			else 
			dayofmonth=30;
		 }
		 luday=siday+1;
		 lunarmonth=lumon;
		 lunarday=luday;
		 lusi=sirun;
	}

	 else
	 {
	 	int siday,lumon=1,luday;
		int sirun=0,simon=1;
		int dayofmonth,sidayofmonth;
		siday=springday-nowday;
		siyear--;
		int si,i,sum=0;
		if(((lunartable[siyear] & 0xF00000) >> 20) == 0)
			si=0;
		else 
			si=1;
		if(si==0)
		{
			for(i=0;i<12;i++)
			{
				if(((lunartable[siyear] & 0x80000) >> i ) ==0)
					sidayofmonth=29;
				else
					sidayofmonth=30;
				sum=sum+sidayofmonth;
			}
		}
		if(si==1)
		{
			for(i=0;i<13;i++)
			{
				if(((lunartable[siyear] & 0x80000) >> i ) ==0)
					sidayofmonth=29;
				else
					sidayofmonth=30;
				sum=sum+sidayofmonth;
			}
		}
		siday=sum-siday;
		luwday=siday+1;
		 if((lunartable[siyear] & 0x80000) >> (simon-1)==0)
			 dayofmonth=29;
		 else 
			 dayofmonth=30;
		 for(i=0;siday>dayofmonth;i++)
		 {	
			siday=siday-dayofmonth;
			simon++;
			if(lumon==((lunartable[siyear] & 0xF00000) >> 20))
			{
			sirun=~sirun;
			if(sirun==0)
			lumon++;
			}
			else
			lumon++;
			if((lunartable[siyear] & 0x80000) >> (simon-1)==0)
			dayofmonth=29;
			else 
			dayofmonth=30;
		 }
		 luday=siday+1;
		 lunarmonth=lumon;
		 lunarday=luday;
		 lusi=sirun;
	 }
	 string lud[30]={"��һ","����","����","����","����","����","����","����","����","��ʮ","ʮһ","ʮ��","ʮ��","ʮ��","ʮ��","ʮ��",
		 "ʮ��","ʮ��","ʮ��","��ʮ","إһ","إ��","إ��","إ��","إ��","إ��","إ��","إ��","إ��","��ʮ"};
	 string lum[24]={"����","����","����","����","����","����","����","����","����","ʮ��","����","����",
		 "��һ��","�����","������","������","������","������","������","�����","�����","��ʮ��","����","������"};
	 string luda,lumo;
	 luda=lud[lunarday-1];
	 if(lusi==0)
		 lumo=lum[lunarmonth-1];
	 else
		 lumo=lum[12+lunarmonth-1];
	 cout << "������ " << lumo << " " << luda << endl;
	 cout << "�����Ǹ�ũ����ĵ� " << luwday << " ��" << endl;
	 cout << "����Ϊ" << bran << "��" << endl;
     cout << "����Ϊ" << zodi << "��" << endl;
	 cout << "��һ����" << wen << endl;
}
//�����֧�ĺ����������������ݣ������������֧���ַ�����
string branch(int iyear)
{
	int i;
	i=iyear%60-4;
	string nx;
	string sx;
	string branch;
	int m,n;
	m=i%10;
	n=i%12;
	switch (m)
	{
	case 0:nx="��";break;
	case 1:nx="��";break;
	case 2:nx="��";break;
	case 3:nx="��";break;
	case 4:nx="��";break;
	case 5:nx="��";break;
	case 6:nx="��";break;
	case 7:nx="��";break;
	case 8:nx="��";break;
	case 9:nx="��";break;
	}
	switch(n)
	{
	case 0:sx="��";break;
	case 1:sx="��";break;
	case 2:sx="��";break;
	case 3:sx="î";break;
	case 4:sx="��";break;
	case 5:sx="��";break;
	case 6:sx="��";break;
	case 7:sx="δ";break;
	case 8:sx="��";break;
	case 9:sx="��";break;
	case 10:sx="��";break;
	case 11:sx="��";break;
	}
	branch=nx+sx;
	return branch;
}

//��������ĺ����������������ݣ����������������ַ�����
string zodiac(int iyear)
{
	int i;
	i=(iyear-1900)%12;
	string zodi;
	switch(i)
	{
	case 0: zodi="��";break;
	case 1: zodi="ţ";break;
	case 2: zodi="��";break;
	case 3: zodi="��";break;
	case 4: zodi="��";break;
	case 5: zodi="��";break;
	case 6: zodi="��";break;
	case 7: zodi="��";break;
	case 8: zodi="��";break;
	case 9: zodi="��";break;
	case 10: zodi="��";break;
	case 11: zodi="��";break;
	}
	return zodi;
}

//�ж����꺯���������������ݣ����������1����0,1��Ӧ�����꣬0��Ӧ�������ꡣ
int run(int iyear)
{
int m;
if(iyear%4!=0) {m=0;return(m);}
else 
{
	if(iyear%100==0)
	{
		if(iyear%400!=0) {m=0;return(m);}
		else {m=1;return(m);}
	}
	else {m=1;return(m);}
}

}

//����ĳ��ǰ�湲�ж�����ĺ���������������·ݣ������жϲ������������������ǰ��һ���е�������
int mon(int imonth,int si)
{
	int p;
	if(si==0)
	{
	switch(imonth)
	{
	case 1:p=0;break;
	case 2:p=31;break;
	case 3:p=59;break;
	case 4:p=90;break;
	case 5:p=120;break;
	case 6:p=151;break;
	case 7:p=181;break;
	case 8:p=212;break;
	case 9:p=243;break;
	case 10:p=273;break;
	case 11:p=304;break;
	case 12:p=334;break;
	}
		}
	else 
	{
	switch(imonth)
	{
	case 1:p=0;break;
	case 2:p=31;break;
	case 3:p=60;break;
	case 4:p=91;break;
	case 5:p=121;break;
	case 6:p=152;break;
	case 7:p=182;break;
	case 8:p=213;break;
	case 9:p=244;break;
	case 10:p=274;break;
	case 11:p=305;break;
	case 12:p=335;break;
	}
	}
	return(p);
}

//�������ڵĺ���������������꣬�£��գ�������������ڼ����ַ�����
string week(int iyear,int imonth,int iday)
{
	int i,da,simo;
	int we;
	string wen;
	if(run(iyear)==0)
	i=(iyear+iyear/4-iyear/100+iyear/400)%7;
	else
	i=(iyear-1+iyear/4-iyear/100+iyear/400)%7;
	if(i==0) i=7;
	simo=mon(imonth,run(iyear));
	da=simo+iday;
	we=da%7-1+i;
	switch(we)
	{
	case 1:wen="����һ";break;
	case 2:wen="���ڶ�";break;
	case 3:wen="������";break;
	case 4:wen="������";break;
	case 5:wen="������";break;
	case 6:wen="������";break;
	default:wen="������";break;
	}
	return wen;
}