/**
@(#)$Id$
* @(#)
*
* (c)  XIAOTING PRIVATE PERSON  2014
* All Rights Reserved.
*/

/**
@brief   commmon check function

@Author $Author$
@Date $Date$
@Revision $Revision$
@URL $URL$
@Header $Header$
*/
#include "stdafx.h"

#ifndef CXX_COMMONFUNCTION_H
#include "CommonFuncion.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

CommonFuncion::CommonFuncion()
{
	
}

CommonFuncion::~CommonFuncion()
{

}

bool 
CommonFuncion::CheckUserName(const char* chUserName)
{
	//check user name
	//用户名 6-16个字符，可使用字母、数字、下划线
	int iUserNameLen = strlen(chUserName);
	if ((0x06 > iUserNameLen) || (0x0f < iUserNameLen)) {
		return false;
	}

	for (int iCout=0x00; iCout<iUserNameLen; iCout++) {
		if (('a' <= (*(chUserName+iCout))) && ('z' >= (*(chUserName+iCout)))) {
			continue;
		}
		else if (('A' <= (*(chUserName+iCout))) && ('Z' >= (*(chUserName+iCout)))) {
			continue;
		}
		else if (('0' <= (*(chUserName+iCout))) && ('9' >= (*(chUserName+iCout)))) {
			continue;
		}
		else if ('_' <= (*(chUserName+iCout))) {
			continue;
		}
		else {
			return false;
		}
	}
	return true;
}

bool 
CommonFuncion::CheckPassword(const char* chPassword)
{
	//check password
	//用户名 6-16个字符，可使用字母、数字、下划线
	int iPasswordLen = strlen(chPassword);
	if ((0x06 > iPasswordLen) || (0x0f < iPasswordLen)) {
		return false;
	}
	for (int iCout=0x00; iCout<iPasswordLen; iCout++) {
		if (('a' <= (*(chPassword+iCout))) && ('z' >= (*(chPassword+iCout)))) {
			continue;
		}
		else if (('A' <= (*(chPassword+iCout))) && ('Z' >= (*(chPassword+iCout)))) {
			continue;
		}
		else if (('0' <= (*(chPassword+iCout))) && ('9' >= (*(chPassword+iCout)))) {
			continue;
		}
		else {
			return false;
		}
	}
	return true;
}

bool 
CommonFuncion::CheckRealName(const char* chRealName)
{
	//check real name
	if (0x00 == strlen(chRealName)) {
		return false;
	}
	return true;
}

bool 
CommonFuncion::CheckIdentityID(const char* chIdentityID)
{
	//check identity id
	if ((false == judgeformat(chIdentityID)) || (false == judge17bit(chIdentityID))) {
		return false;
	}
	return true;
}

bool 
CommonFuncion::CheckEmail(const char* chEmail)
{
	//check email
	if (false == judgeemail(chEmail)) {
		return false;
	}
	return true;
}

bool 
CommonFuncion::CheckTelePhone(const char* chTelePhone)
{
	int iTelePhoneLen = strlen(chTelePhone);
	if (0x0b != iTelePhoneLen) {
		//中国的手机11位
		return false;
	}

	if ('1' != chTelePhone[0]) {
		//中国的手机1开头
		return false;
	}

	return true;
}

bool 
CommonFuncion::CheckNumber0_9(const char* chNumber0_9)
{
	int iPasswordLen = strlen(chNumber0_9);
	if (0 == iPasswordLen) {
		return false;
	}
	for (int iCout=0x00; iCout<iPasswordLen; iCout++) {
		if (('0' <= (*(chNumber0_9+iCout))) && ('9' >= (*(chNumber0_9+iCout)))) {
			continue;
		}
		else {
			return false;
		}
	}
	return true;
}
/////////////////////////////////身份证简单判别/////////////////////////////////////////
bool 
CommonFuncion::judgeday(int day,int mouth,int year)
{
	int dayArray[12]={31,28,31,30,31,30,31,31,30,31,30,31};

	if(year%400==0||year%4==0&&year%100!=0)
		dayArray[1]=29;
	if(day>dayArray[mouth-1])
		return false;
	else
		return true;
}
bool 
CommonFuncion::judgeformat(const char *str)
{ 
	for(int i=0;i<=16;i++) {
		if(str[i]<'0'||str[i]>'9') {
			//			cout<<"error!非法身份证号:前17位数字!"<<endl;
			return false;
		}
		else
			if(str[17]<'0'||str[17]>'9'&&str[17]!='X') {
				//				cout<<"error!非法身份证号:第十八位数字或'X'"<<endl;
				return false;
			} 
	}
	int year,mouth,day;
	year=((int)str[6]-48)*1000+((int)str[7]-48)*100+((int)str[8]-48)*10+((int)str[9]-48);
	mouth=((int)str[10]-48)*10+((int)str[11]-48);
	day=((int)str[12]-48)*10+((int)str[13]-48);
	if(year>2010||year<1910||mouth>12||judgeday(day,mouth,year)==false) {
		//		cout<<"error!非法身份证号:请输入正确出生年月!"<<endl;
		return false;
	}

	return true;
}

bool 
CommonFuncion::judge17bit(const char *str)
{
	int  quan[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	char jiaoyan[]={'1','0','X','9','8','7','6','5','4','3','2'};
	char code17bit;
	int  i,sum=0,mod;
	for(i=0;i<17;i++)
		sum+=(str[i]-48)*quan[i];
	mod=sum%11;
	code17bit=jiaoyan[mod];
	if (code17bit==str[17])
		return true;
	else {
		//		cout<<"error!校验码错误!"<<endl;
		return false;
	}
}

/////////////////////////////////Email简单判别/////////////////////////////////////////
bool 
CommonFuncion::judgeemail(const char *my)
{
	int len=0x00;
	int atindex=0x00;
	int dotindex=0x00;
	int atflat=0,dotflag=0;
	//	cout<<"pls put in email address"<<endl;
	//	cin>>my;
	len = strlen(my);
	//	cout<<len<<endl;
	for(int i=0;i<len; i++)
	{
		if(my[i]==' ')
		{
			//			cout<<"no space!"<<endl;
			return false;
		}
		if(my[i]=='@')
		{
			if(!atflat)
			{
				if(i<1||(i+4)==len)
				{
					//					cout<< "error1"<<endl;
					return false;
				}
				atindex=i;
				atflat=1;
			}
			else
			{
				//				cout<<"only one @!"<<endl;
				return false;
			}

		}
		else if(my[i]=='.')
		{
			if((i-dotindex)==1)
			{
				//				cout<<"0 space!"<<endl;
				return false;
			}
			dotindex=i;
			int a =dotindex+2;
			if(a>=len)
			{
				//				cout<<".后面不正确"<<endl;
				return false;
			}
			dotflag++;
			if(dotflag>3)
			{
				//				cout<<"can not exceed 3!"<<endl;
				return false;
			}
		}
	}
	if(dotflag && atflat)
		//		cout<<"ok!!!"<<endl;
		return true;
	else
		//		cout<<"error3"<<endl;
		return false;

	return true;
}

//////////////////////////////////////////////////////////////////////////
void 
CommonFuncion::split(char *src, const char *separator, char **dest, int *num)
{
	char *pNext;
	int count = 0;

	if (src == NULL || strlen(src) == 0) return;
	if (separator == NULL || strlen(separator) == 0) return; 

	pNext = strtok(src,separator);

	while(pNext != NULL)
	{
		*dest++ = pNext;
		++count;
		pNext = strtok(NULL,separator);
	}

	*num = count;
}

void 
CommonFuncion::split(const string& src, const string& separator, vector<string>& dest)
{
	dest.clear();
	string str = src;
	string substring;
	string::size_type start = 0, index;

	do
	{
		index = str.find_first_of(separator,start);
		if (index != string::npos)
		{    
			substring = str.substr(start,index-start);
			dest.push_back(substring);
			start = str.find_first_not_of(separator,index);
			if (start == string::npos) return;
		}
	}while(index != string::npos);

	//the last token
	substring = str.substr(start);
	dest.push_back(substring);
}

void 
CommonFuncion::split(const CString& src, const CString& separator, vector<CString>& dest)	//C++
{
	dest.clear();
	vector<string> vStrdest;
	split(LPCSTR(src), LPCSTR(separator), vStrdest);
	for (int iCnt=0x00; iCnt<(int)vStrdest.size(); iCnt++) {
		dest.push_back(vStrdest[iCnt].c_str());
	}
}


char* 
CommonFuncion::Utf8ToGBK(const char* strUtf8)
{
	int len=MultiByteToWideChar(CP_UTF8, 0, (LPCTSTR)strUtf8, -1, NULL,0); 
	unsigned short * wszGBK = new unsigned short[len+1];       
	memset(wszGBK, 0, len * 2 + 2); 
	MultiByteToWideChar(CP_UTF8, 0, (LPCTSTR)strUtf8, -1, (LPWSTR)wszGBK, len);
	len = WideCharToMultiByte(CP_ACP, 0, (LPCWSTR)wszGBK, -1, NULL, 0, NULL, NULL);
	char *szGBK=new char[len + 1]; 
	memset(szGBK, 0, len + 1); 
	WideCharToMultiByte (CP_ACP, 0, (LPCWSTR)wszGBK, -1, (LPSTR)szGBK, len, NULL,NULL);
	return szGBK; 
}

char* 
CommonFuncion::GBKToUtf8(const char* strGBK)
{ 
	int len=MultiByteToWideChar(CP_ACP, 0, (LPCTSTR)strGBK, -1, NULL,0); 
	unsigned short * wszUtf8 = new unsigned short[len+1]; 
	memset(wszUtf8, 0, len * 2 + 2); 
	MultiByteToWideChar(CP_ACP, 0, (LPCTSTR)strGBK, -1, (LPWSTR)wszUtf8, len);
	len = WideCharToMultiByte(CP_UTF8, 0, (LPCWSTR)wszUtf8, -1, NULL, 0, NULL, NULL);
	char *szUtf8=new char[len + 1]; 
	memset(szUtf8, 0, len + 1); 
	WideCharToMultiByte (CP_UTF8, 0, (LPCWSTR)wszUtf8, -1, (LPSTR)szUtf8, len, NULL,NULL);
	return szUtf8; 
}


short 
CommonFuncion::vartoi(const _variant_t& var) 
{ 
	short value = 0; 
	switch (var.vt) 
	{ 
	case VT_BOOL: 
		value = var.boolVal; 
		break; 
	case VT_UI1: 
	case VT_I1: 
		value = var.bVal; 
		break; 
	case VT_I2: 
	case VT_UI2: 
		value = var.iVal; 
		break; 
	case VT_NULL: 
	case VT_EMPTY: 
		value = 0; 
		break; 
	default: 
		TRACE(_T("Warning: 未处理的 _variant_t 类型值; 文件: %s; 行: %d\n"), __FILE__, __LINE__); 
	} 
	return value; 
} 

long 
CommonFuncion::vartol(const _variant_t& var) 
{ 
	long value = 0; 
	switch (var.vt) 
	{ 
	case VT_BOOL: 
		value = var.boolVal; 
		break; 
	case VT_UI1: 
	case VT_I1: 
		value = var.bVal; 
		break; 
	case VT_UI2: 
	case VT_I2: 
		value = var.iVal; 
		break; 
	case VT_I4: 
	case VT_UI4: 
		value = var.lVal; 
		break; 
	case VT_INT: 
		value = var.intVal; 
		break; 
	case VT_R4: 
		value = (long)(var.fltVal + 0.5); 
		break; 
	case VT_R8: 
		value = (long)(var.dblVal + 0.5); 
		break; 
	case VT_DECIMAL: 
		value = (long)var; 
		break; 
	case VT_CY: 
		value = (long)var; 
		break; 
	case VT_BSTR://字符串 
	case VT_LPSTR://字符串 
	case VT_LPWSTR://字符串 
		value = atol((LPCTSTR)(_bstr_t)var); 
		break; 
	case VT_NULL: 
	case VT_EMPTY: 
		value = 0; 
		break; 
	default: 
		TRACE(_T("Warning: 未处理的 _variant_t 类型值; 文件: %s; 行: %d\n"), __FILE__, __LINE__); 
	} 
	return value; 
} 

double 
CommonFuncion::vartof(const _variant_t& var) 
{ 
	double value = 0; 
	switch (var.vt) 
	{ 
	case VT_R4: 
		value = var.fltVal; 
		break; 
	case VT_R8: 
		value = var.dblVal; 
		break; 
	case VT_DECIMAL: 
		value = (double)var; 
		break; 
	case VT_CY: 
		value = (double)var; 
		break; 
	case VT_BOOL: 
		value = var.boolVal; 
		break; 
	case VT_UI1: 
	case VT_I1: 
		value = var.bVal; 
		break; 
	case VT_UI2: 
	case VT_I2: 
		value = var.iVal; 
		break; 
	case VT_UI4: 
	case VT_I4: 
		value = var.lVal; 
		break; 
	case VT_INT: 
		value = var.intVal; 
		break; 
	case VT_BSTR://字符串 
	case VT_LPSTR://字符串 
	case VT_LPWSTR://字符串 
		value = atof((LPCTSTR)(_bstr_t)var); 
		break; 
	case VT_NULL: 
	case VT_EMPTY: 
		value = 0; 
		break; 
	default: 
		value = 0; 
		TRACE(_T("Warning: 未处理的 _variant_t 类型值; 文件: %s; 行: %d\n"), __FILE__, __LINE__); 
	} 
	return value; 
}



CString 
CommonFuncion::VarToCString(_variant_t var)
{

	CString strValue;

	_variant_t var_t;

	_bstr_t bstr_t;

	time_t cur_time;

	CTime time_value;

	COleCurrency var_currency;

	switch(var.vt)

	{

	case VT_EMPTY:

	case VT_NULL:strValue=_T("");break;

	case VT_UI1:strValue.Format("%d",var.bVal);break;

	case VT_I2:strValue.Format("%d",var.iVal);break;

	case VT_I4:strValue.Format("%d",var.lVal);break;

	case VT_R4:strValue.Format("%f",var.fltVal);break;

	case VT_R8:strValue.Format("%f",var.dblVal);break;

	case VT_CY:

		var_currency=var;

		strValue=var_currency.Format(0);break;

	case VT_BSTR:

		var_t =var;

		bstr_t=var_t;

		strValue.Format("%s",(const char *)bstr_t);break;

	case VT_DATE:

		cur_time=(time_t)var.date;

		time_value=cur_time;

		strValue.Format("%A,%B,%d,%Y");break;

	case VT_BOOL:strValue.Format("%d",var.boolVal);break;

	default:strValue=_T("");break;

	}

	return strValue;

}
/* EOF */