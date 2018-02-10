#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	int m;
	int i=0;
	while(i<10)
	{

	m=rand()%2+1;
	printf(" %d",m);
	i++;
	}

return 0;
}
