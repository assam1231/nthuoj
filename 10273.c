#include <stdio.h>
#include <string.h>
char *ch_string = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

char outstr[100];
int end_pos;
void gen_str(int pos, int len, int out_pos)
{
	if (0 == len)
	{
		outstr[out_pos] = 0;
		printf("%s\n", outstr);
		return;
	}
	int i;
	for (i = pos; i < end_pos - len + 1;i++)
	{
		outstr[out_pos] = ch_string[i];
		gen_str(i + 1, len - 1, out_pos + 1);
	}
	return;
}

int main(void)
{
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w+", stdout);
	int count;
	int test_num;
	int len;
	while (1 == scanf("%d", &test_num))
	{
		memset(outstr, 0, sizeof(outstr));
		
		while (test_num != 0)
		{
			scanf("%d%d", &end_pos, &len);
			gen_str(0 , len, 0);
			test_num--;
			printf("\n");
		}
	}
	return 0;
}


