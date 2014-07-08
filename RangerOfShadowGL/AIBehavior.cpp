#include "AIBehavior.h"

int CSimpleAI::useMind(int arr[], int sz, int xx, int yy)
{
	int irand = -1;
	int max = 1000;
	int i = 0;
	while(arr[irand] != 0 && i < max){ irand = rand()%8; ++i;};
	if(i < max)
		return irand;
	/*for(i = 0; i < sz; ++i)
		if(arr[i] == 0)
			return i;*/
	return -1;
}