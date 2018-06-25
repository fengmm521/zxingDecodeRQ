#include "StdAfx.h"
#include "IntArray.h"

CIntArray::CIntArray(void)
{
	intArry = NULL;
	size = 0;
}

CIntArray::~CIntArray(void)
{
	if(intArry != NULL){
		free(intArry);
		intArry = NULL;
	}
}

//********************************************************************
// Function		:	GetSize
// Description	:	get int array size
// Input		:	NONE
// Output		:	NONE
// return		:	int array size
//********************************************************************
int CIntArray::GetSize()
{
	return this->size;
}

//********************************************************************
// Function		:	GetAt
// Description	:	get data in array
// Input		:	index : index must > 0 and < the array size
// Output		:	NONE
// return		:	the data in array which index is the same to input index
//********************************************************************
int CIntArray::GetAt(unsigned int index)
{
	if(index >= 0 && index < this->size){
		int *p = this->intArry;
		p += index;
		return *p;
	}

	// error array index
	return 0;
}