#ifndef _487_3279_H__
#define _487_3279_H__

#include "stdafx.h"

//////////////////////////////////////////////////////////////////////////
//
// The standard form of TUT-GLOP is 888-4567
//
//////////////////////////////////////////////////////////////////////////

string sstr[8] = {"ABC", "DEF", "GHI", "JKL", "MNO", "PRS", "TUV", "WXY"};

string str2StandardForm(string str)
{
	string ret;

	for (string::size_type i = 0; i < str.length(); i++){
		/*if(str[i] == 'A' || str[i] == 'B' || str[i] == 'C'){
			ret[i] = 2 + '0';
		}else if (str[i] == 'D' || str[i] == 'E' || str[i] == 'F'){
			ret[i] = 3 + '0';
		}else if(string("GHI").find(str[i]) != string::npos){
			ret[i] = 4 + '0';
		}else if(string("JKL").find(str[i]) != string::npos){
			ret[i] = 5 + '0';
		}else if(string("MNO").find(str[i]) != string::npos){
			ret[i] = 6 + '0';
		}else if(string("PRS").find(str[i]) != string::npos){
			ret[i] = 7 + '0';
		}else if(string("TUV").find(str[i]) != string::npos){
			ret[i] = 8 + '0';
		}else if(string("WXY").find(str[i]) != string::npos){
			ret[i] = 9 + '0';
		}*/
		if(isdigit(str[i]) || str[i] == '-'){
			ret.push_back(str[i]);
		}else{
			for (int j = 0; j < 8; j++)	{
				if(sstr[j].find(toupper(str[i])) != string::npos){
					char ch = j + 2 + '0';
					ret.push_back(ch);
					break;
				}
			}// end for [j]
		}// end else
	}// end for [i]

	return (ret);
}

string str2Hyphens(string str)
{
	int nElem = 0, j = 0;
	string ret;
	for (string::size_type i = 0; i < str.length(); i++){
		if(isalnum(str[i])){
			if(j != 3){
				ret.push_back(str[i]);
				j++;
			}else{
				ret.push_back('-');
				ret.push_back(str[i]);
				j++, nElem++;
			}
			nElem++;
		}// end if
	}// end for
	
	return ((nElem == 8) ? ret : string());
}

#endif