#pragma once

class MyArray
{
private:
	int size;
	float* arrayPtr;

public:
	MyArray(int arraySize);
	~MyArray();
	void StoreNum(int index, float value);
	void RetrieveNum();
	void HighestNum();
	void LowestNum();
	void Average();
};

