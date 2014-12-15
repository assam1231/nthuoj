#include <stdio.h>
#include <string.h>
int main(void)
{
#ifdef DEBUG
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w+", stdout);
#endif	
	int i, flg, num, len;
	while (EOF != scanf("%d", &len))
	{
		flg = 1;
		num = 1;
		for (i = 1; ; ++i)
		{
			if (num < (len / 2 + 1))
				num *= 2;
			else
				num = (num - (len/2)) * 2 -1;
			if (1 == num)
				break;
		}
		printf("%d\n", i);
	}
	return 0;
}
