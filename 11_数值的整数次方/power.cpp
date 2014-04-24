#include <iostream>
using namespace std;
bool g_invalidinput=false;
bool equal(double num1,double num2);
double power_with_unsigned_exponent(double base,unsigned int absexponent);
double power(double base, int exponent){
	g_invalidinput=false;
	if(equal(base,0.0)&&exponent<0){
		g_invalidinput=true;
		return 0.0;
	}
	unsigned int absexponent=(unsigned int)(exponent);
	if(exponent<0){
		absexponent=(unsigned int)(-exponent);
	}
	double result=power_with_unsigned_exponent(base,absexponent);
	if (exponent<0)
	{
		result=1.0/result;
	}
	return result;
}

double power_with_unsigned_exponent(double base,unsigned int absexponent){
	double result=1.0;
	for (int i=0;i<absexponent;i++)
	{
		result*=base;
	}
	return result;
}
//����Ч��һ���㷨a^n=a^n/2*a^n/2(nΪż��)or a^n=a^(n-1)/2*a^(n-1)/2*a��nΪ������
double power_with_unsigned_exponent2(double base,unsigned int absexponent){
	if(absexponent==0){
		return 1;
	}
	if(absexponent==1){
		return base;
	}
	double result=power_with_unsigned_exponent2(base,absexponent>>1);
	result*=result;
	if(absexponent&0x1==1)
		result*=base;
	return result;
}
bool equal(double num1,double num2){
	if(num1-num2>-0.0000001&&num1-num2<0.0000001){//double�����ڴ洢ʱ��������num1==num2���ж�����double�Ƿ����
		return true;
	}
	return false;
}


void main(){
	double base1=2.3;
	int exponent1=2;
	int exponent2=0;
	int exponent3=-2;
	cout<<base1<<"'s exponent"<<exponent1<<" is "<<power(base1,exponent1)<<endl;
	cout<<base1<<"'s exponent"<<exponent2<<" is "<<power(base1,exponent2)<<endl;
	cout<<base1<<"'s exponent"<<exponent3<<" is "<<power(base1,exponent3)<<endl;
}m                          