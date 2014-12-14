#include <stdio.h>
int stack[1010];
char line[100000];
int main(void)
{

	int ptr, num, tmp, erro, i, j;
#ifdef DEBUG
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w+", stdout);
#endif
	while (EOF != scanf("%d", &num))
	{
		ptr = 0;
		j = 1;
		for (i = 0; i < num; ++i)
		{
			scanf("%d", &tmp);
			if (tmp == j)
			{
				++j;
				continue;
			}
			else if (0 != ptr && tmp == stack[ptr - 1])
			{
				++j;
				ptr--;
				continue;
			}
			else
				stack[ptr++] = tmp;
		}
		for (;j < num + 1;++j)
		{
			if (j != stack[ptr - 1])
				break;
			ptr--;
		}
		if (0 != ptr)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
