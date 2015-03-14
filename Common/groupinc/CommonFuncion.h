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

#ifndef CXX_COMMONFUNCTION_H
#define CXX_COMMONFUNCTION_H

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#ifndef CXX_COMMONDEF_H
#include "CommonDef.h"
#endif

#define random(x) (rand()%x)

class CommonFuncion
{
public:
	CommonFuncion();
	~CommonFuncion();

	static char* Utf8ToGBK(const char* strUtf8);
	static char* GBKToUtf8(const char* strGBK);
	static void split(char *src, const char *separator, char **dest, int *num);			//C
	static void split(const string& src, const string& separator, vector<string>& dest);	//C++
	static void split(const CString& src, const CString& separator, vector<CString>& dest);	//C++

	static bool CheckUserName(const char* chUserName);
	static bool CheckPassword(const char* chPassword);
	static bool CheckRealName(const char* chRealName);
	static bool CheckIdentityID(const char* chIdentityID);
	static bool CheckEmail(const char* chEmail);
	static bool CheckTelePhone(const char* chTelePhone);
	static bool CheckNumber0_9(const char* Number0_9);
protected:
private:
	static bool judgeday(int,int,int);
	static bool judgeformat(const char *);
	static bool judge17bit(const char *);
	static bool judgeemail(const char *);
};

#endif // CXX_COMMONFUNCTION_H
/* EOF */
