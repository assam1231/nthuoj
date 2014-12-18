#include <stdio.h>
#include <string.h>
int main(void)
{
//	freopen("in1.txt", "r", stdin);
//	freopen("out1.txt", "w+", stdout);
	int size;
	char input[10000];
	int str_len;
	int i, j;
	int x, y;	//matrix position
	int dir;
	char out_str[10000];
	char matrix[100][100];
	// dir = 0: down, size = 1: right, size = 2: up, size = 3: left
	while (1 == scanf("%d", &size))
	{
        getchar();
        for (j = 0; j<100 ;++j)
            memset(matrix[j], 0, 100);
        out_str[0] = 0;
        memset(out_str, 0, sizeof(out_str));
		gets(input);
		dir = 0;
		x = 0;
		y = 0;
		str_len = strlen(input);
		for (i = 0; i < str_len; ++i)
		{
			matrix[x][y] = input[i];

			if (0 == dir)
			{
				if ((x + 1 == size) || matrix[x + 1][y] != 0)
				{
					dir ++;
				}
			}
			else if (1 == dir)
			{
				if ((y + 1 == size) || matrix[x][y + 1] != 0)
				{
					dir ++;
				}
			}
			else if (2 == dir)
			{
				if ((x == 0) || matrix[x - 1][y] != 0)
				{
					dir ++;
				}
			}
			else if (3 == dir)
			{
				if ((y == 0) || matrix[x][y - 1] != 0)
				{
					dir = 0;
				}
			}
			x += (0 == dir);
			x -= (2 == dir);
			y += (1 == dir);
			y -= (3 == dir);
		}
		for (; i < size * size; ++i)
		{
			matrix[x][y] = ' ';

			if (0 == dir)
			{
				if ((x + 1 == size) || matrix[x + 1][y] != 0)
				{
					dir ++;
				}
			}
			else if (1 == dir)
			{
				if ((y + 1 == size) || matrix[x][y + 1] != 0)
				{
					dir ++;
				}
			}
			else if (2 == dir)
			{
				if ((x == 0) || matrix[x - 1][y] != 0)
				{
					dir ++;
				}
			}
			else if (3 == dir)
			{
				if ((y == 0) || matrix[x][y - 1] != 0)
				{
					dir = 0;
				}
			}
			x += (0 == dir);
			x -= (2 == dir);
			y += (1 == dir);
			y -= (3 == dir);
		}

		for (i = 0; i < size; ++i)
		{
		    strcat(out_str, matrix[i]);
		}

        for (i = strlen(out_str) - 1; (i != 0) && (out_str[i] == ' '); i--)
            out_str[i] = 0;

		printf("%s\n",out_str);
	}
	return 0;
}
