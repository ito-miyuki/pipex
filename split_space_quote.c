/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_space_quote.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:03:32 by mito              #+#    #+#             */
/*   Updated: 2024/04/19 16:10:06 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char **remove_quote(char **commands, int wc)
{
	char **res;
	int i;
	int str_len;

	res = malloc(sizeof(char *) * (wc + 1));
	i = 0;
	str_len = 0;
	
	while (commands[i] != NULL)
	{
		str_len = ft_strlen(commands[i]);
		if (commands[i][0] == 39 && commands[i][str_len - 1] == 39)
		{
			res[i] = malloc(sizeof(char) * (str_len - 1));
			if (!res)
			{
				free_grid(res);
				return (NULL);	
			}
			//res[i] = ft_memmove(res[i], commands[i][1], str_len - 1);	
			res[i] = ft_strndup(&commands[i][1], str_len - 2);
			if (!res)
			{
				free_grid(res);
				return (NULL);
			}
		}
		else
		{
			res[i] = ft_strdup(commands[i]);
			if (!res)
			{
				free_grid(res);			
				return (NULL);	
			}
		}
		i++;
	}
	return (res);
}

static void	free_array(size_t i, char **array)
{
	while (i > 0)
	{
		i--;
		free(array[i]);
	}
	free(array);
}


static int count_words(char *str)
{
    int i = 0;
    int wc = 0;
    while (str[i] !='\0')
    {
        while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')) //空白だったら飛ばす
            i++;
        if (str[i] == 39) //  39 is '
        {
            wc++;
            i++;
            while (str[i] != '\0' && (str[i] != 39)) // ' まで飛ばす
                i++;
            i++;
        }
        else if (str[i]) //文字を見つかたらカウントする
        {wc++;
        while (str[i] != '\0' && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')) //次の空白までiを進める
            i++;
        }
    }
    return (wc);
}

char    **split_space_quote(char *str)
{
	int wc = count_words(str);
	int arr_i = 0;
	int i = 0;
	int res_i = 0;
	int word_pos = 0;
	char **res = malloc(sizeof(char *) * (wc + 1));
	char **final;
	if (!res)
		return (NULL);
	while (str[i] != '\0')
	{
		while (str[i] == ' ' || str[i] == '\t') //空白文字は飛ばす
			i++;
		if (str[i] != '\0')
		{
			word_pos = i;
			if (str[word_pos] == 39)
			{
				word_pos++;
				while (str[word_pos] != '\0' && str[word_pos] != 39)
					word_pos++;
				word_pos++;
			}
			else
			{
				while (str[word_pos] != '\0' && str[word_pos] != ' ' && str[word_pos] != '\t') //文字が続いている間word_posを進める
				word_pos++; //単語の区切りを見つけたらword potion - 1分のメモリを確保
			}
			res[arr_i] = malloc(sizeof(char) * (word_pos - i + 1)); //iから区切り文字を見つけるまでどれくらい移動したか
			if (!res[arr_i])
			{
				free_array(i, res);
				return (NULL);
			}
			while (i < word_pos)
			{
				res[arr_i][res_i] = str[i];
				res_i++;
				i++;
			}
			res[arr_i][res_i] = '\0';
			arr_i++;
			res_i = 0;
		}
	}
	res[arr_i] = (NULL); 
	final = remove_quote(res, wc);
	if (!final)
		return (NULL);
	return (final);
}

// int main(void)
// {
// 	char str[] = "awk '{count++} END {print count}' 'abx asd casd' ";
// 	//char str[] = "awk {count++} END {print count}";
// 	char **cmd = split_space_quote(str);

// 	int i = 0;
// 	while (cmd && cmd[i] != NULL)
// 	{
// 		printf("%s\n", cmd[i]);
// 		i++;
// 	} 
// }
