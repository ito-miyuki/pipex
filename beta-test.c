#include "pipex_bonus.h"

int main(void)
{
	char str[] = "awk '{count++} END {print count}'";
	char **cmd = ft_split(str, ' ');

	int i = 0;
	while (cmd && cmd[i] != NULL)
	{
		ft_printf("%s\n", cmd[i]);
		i++;
	}
	
}

/*
this is the expected one
"awk"
"'{count++} END {print count}'"

then after that, creat a function to remove ' '.
*/