#pragma once

class CIntArray
{
public:
	CIntArray(void);
	virtual ~CIntArray(void);
	// get int array size
	int GetSize();
	// get data in array
	int GetAt(unsigned int index);
	// set data at array

private:
	int *intArry;	// int array point
	int size;		// int array size
};
