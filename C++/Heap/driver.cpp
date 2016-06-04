#include <iostream>
#include "heap.h"
using namespace std;

int main()
{
	MinHeap hObject(7);
	hObject.InsertKey(7);
	hObject.InsertKey(6);
	hObject.InsertKey(5);
	// hObject.DisplayHeap();

	hObject.InsertKey(4);
	hObject.InsertKey(3);
	hObject.InsertKey(2);
	hObject.InsertKey(1);
	hObject.DisplayHeap();

	cout << "Smallest element: " << hObject.GetMin() << endl;
	hObject.ExtractMin();
	hObject.DisplayHeap();

	hObject.DeleteKey(3);
	hObject.DisplayHeap();

	return 0;
}