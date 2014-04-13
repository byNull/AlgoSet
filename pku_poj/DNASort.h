#ifndef _DNA_SORT_H__
#define _DNA_SORT_H__

#pragma once

#include "stdafx.h"

struct DNANode{
	string dna;
	int    numOfInversions;

	operator string()const{
		return dna;
	}
};

int numOfInversions(string str)
{
	int cnt = 0;
	for (string::size_type i = 0; i < str.length(); i++){
		for (string::size_type j = i + 1; j < str.length(); j++){
			if((toupper(str[i]) - toupper(str[j])) > 0)
				cnt++;
		}
	}

	return (cnt);
}

bool DANCompare(DNANode dna1, DNANode dna2)
{
	return (dna1.numOfInversions < dna2.numOfInversions);
}

ostream &operator<< (ostream &out, DNANode &dn){
	out << dn.dna;
	return (out);
}
#endif