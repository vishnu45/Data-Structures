#include <iostream>
#include "heap.h"
using namespace std;

int main()
{
	MinHeap hObject(5);
	hObject.InsertKey(17);
	hObject.InsertKey(13);
	hObject.InsertKey(6);
	hObject.DisplayHeap();

	hObject.InsertKey(18);
	hObject.DisplayHeap();
	return 0;
}