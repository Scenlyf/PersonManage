// stdafx.cpp : source file that includes just the standard includes
//	Personal.pch will be the pre-compiled header
//	stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"
CString UserName;
void SetUserName(CString name)
{
	UserName = name;
}
CString GetUserName()
{
	return UserName;
}
