// duquwenjian.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>


#include <stdlib.h>
#include <string.h>

int count[27]; //0-25代表a-z,26代表其它字符
char s[1001];

int main()
{
	int i;
	FILE *fp;
	fp = fopen("F:\test.txt", "r");
	while (fgets(s, 1000, fp))
	{
		for (i = 0; s[i]; i++) {
			if (s[i] <'A' || s[i] > 'z' || (s[i] > 'Z' && s[i] < 'a')) //证明是其它字符
				count[26] ++;
			else if (s[i] < 'a') //大写字符
				count[s[i] - 'A'] ++;
			else
				count[s[i] - 'a'] ++;
		}
	}

	for (i = 0; i < 26; i++) {
		printf("%c 或者 %c:%d次\n", 'A' + i, 'a' + i, count[i]);
	}
	printf("其他字符:%d次\n", count[26]);

	return 0;
}