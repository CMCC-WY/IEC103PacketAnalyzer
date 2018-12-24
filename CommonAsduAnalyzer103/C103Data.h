#ifndef _C103Data_H
#define _C103Data_H

#pragma once
#include "103DataDefine.h"
#include <vector>
class CC103Data
{
public:
	CC103Data(void);
	virtual ~CC103Data(void);

public:
	std::vector<Asdu103_1> vec_Asdu103_1;
	std::vector<Asdu103_2> vec_Asdu103_2;
	std::vector<Asdu103_3> vec_Asdu103_3;
	std::vector<Asdu103_4> vec_Asdu103_4;
	std::vector<Asdu103_5> vec_Asdu103_5;
	std::vector<Asdu103_6> vec_Asdu103_6;
	
	std::vector<Asdu103_8> vec_Asdu103_8;
	std::vector<Asdu103_9> vec_Asdu103_9;
	std::vector<Asdu103_10> vec_Asdu103_10;
	std::vector<Asdu103_11> vec_Asdu103_11;
	
	std::vector<Asdu103_23> vec_Asdu103_23;
	std::vector<Asdu103_26> vec_Asdu103_26;
	std::vector<Asdu103_27> vec_Asdu103_27;
	std::vector<Asdu103_28> vec_Asdu103_28;
	std::vector<Asdu103_29> vec_Asdu103_29;

	std::vector<Asdu103_30> vec_Asdu103_30;
	std::vector<Asdu103_31> vec_Asdu103_31;
};
#endif
