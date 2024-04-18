/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_space_quote.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:03:32 by mito              #+#    #+#             */
/*   Updated: 2024/04/18 12:07:55 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// static size_t	ft_word_len(char const *str, char space, char quote)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] != space && str[i] != quote)
// 			i++;
// 		else if ()
// 		else
// 			return (i);
// 	}
// 	return (i);
// }

// // static void	free_array(size_t i, char **array)
// // {
// // 	while (i > 0)
// // 	{
// // 		i--;
// // 		free(array[i]);
// // 	}
// // 	free(array);
// // }

// static char	**split(char const *str, char space, char quote, char **array, size_t words_count)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	j = 0;
// 	while (i < words_count)
// 	{
// 		while (*(str + j) && *(str + j) == space)
// 			j++;
// 		array[i] = ft_substr(str, j, ft_word_len(&*(str + j), space, quote));
// 		if (!array[i])
// 		{
// 			free_array(i, array);
// 			return (NULL);
// 		}
// 		while (*(str + j) && *(str + j) != space)
// 			j++;
// 		i++;
// 	}
// 	*(array + i) = NULL;
// 	return (array);
// }

// char	**split_space_quote(char *str)
// {
// 	char	**result;
// 	size_t	wc;

// 	if (!str)
// 		return (NULL);
// 	wc = count_words(str);
// 	result = (char **)malloc(sizeof(char *) * (wc + 1));
// 	if (!result)
// 		return (NULL);
// 	result = split(str, ' ', result, wc);
// 	return (result);
// }

static char **remove_quote(char **commands, int wc)
{
	char **res;

	res = malloc(sizeof(char *) * (wc + 1));
	
	//scan the whole 2d array
	//allocate memory for the length without ''
	// check if there is quote
	// if yes, create
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


int count_words(char *str)
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
	//printf("wc is %d\n", wc);
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
	return (final);
}


int main(void)
{
	char str[] = "awk '{count++} END {print count}'";
	//char str[] = "awk {count++} END {print count}";
	char **cmd = split_space_quote(str);

	int i = 0;
	while (cmd && cmd[i] != NULL)
	{
		printf("%s\n", cmd[i]);
		i++;
	}
}

/*
split the string like this:
"./pipex "input" "grep Hello" "awk '{count++} END {print count}'" outfile

and expected result is like this:
"awk"
"'{count++} END {print count}'"

then after that, creat a function to remove ' '.
*/