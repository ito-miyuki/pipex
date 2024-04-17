#include "pipex_bonus.h"


int word_count(char *str)
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

static size_t	ft_word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			s++;
			i++;
		}
		else
			return (i);
	}
	return (i);
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

static char	**split(char const *s, char c, char **array, size_t words_count)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < words_count)
	{
		while (*(s + j) && *(s + j) == c)
			j++;
		array[i] = ft_substr(s, j, ft_word_len(&*(s + j), c));
		if (!array[i])
		{
			free_array(i, array);
			return (NULL);
		}
		while (*(s + j) && *(s + j) != c)
			j++;
		i++;
	}
	*(array + i) = NULL;
	return (array);
}

char	**split_singlequote(char *str, char c)
{
	char	**result;
	size_t	words_num;

	if (!str)
		return (NULL);
	words_num = count_words(str, c);
	result = (char **)malloc(sizeof(char *) * (words_num + 1));
	if (!result)
		return (NULL);
	result = split(str, c, result, words_num);
	return (result);
}

// char    **split_singlequote(char *str)
// {

// 	int word_len = word_count(str);
// 	printf("word_len is %d\n", word_len);
// 	int arr_i = 0;
// 	int i = 0;
// 	int res_i = 0;
// 	int word_pos = 0;
// 	char **res = malloc(sizeof(char *) * (word_len + 1));
// 	if (!res)
// 		return (NULL);
// 	while (str[i] != '\0') //strでループ
// 	{
// 		while (str[i] == ' ' || str[i] == '\t') //空白文字は飛ばす
// 			i++;
// 		if (str[i] != '\0')
// 		{
// 			word_pos = i;
// 			while (str[word_pos] != '\0' && str[word_pos] != ' ' && str[word_pos] != '\t') //文字が続いている間word_posを進める
// 				word_pos++; //単語の区切りを見つけたらword potion - 1分のメモリを確保
// 			res[arr_i] = malloc(sizeof(char) * (word_pos - i + 1)); //iから区切り文字を見つけるまでどれくらい移動したか
// 			if (!res[arr_i])
// 				return (NULL);
// 			while (i < word_pos)
// 			{
// 				res[arr_i][res_i] = str[i];
// 				res_i++;
// 				i++;
// 			}
// 			res[arr_i][res_i] = '\0';
// 			arr_i++;
// 			res_i = 0;
// 		}
// 	}
// 	res[arr_i] = (NULL);
// 	return (res);
// }


int main(void)
{
	char str[] = "awk '{count++} END {print count}'";
	//char str[] = "awk {count++} END {print count}";
	// char **cmd = ft_split(str, ' ');

	// int i = 0;
	// while (cmd && cmd[i] != NULL)
	// {
	// 	ft_printf("%s\n", cmd[i]);
	// 	i++;
	// }

	int res = word_count(str);
	printf("%i\n", res);
}

/*
split the string like this:
"./pipex "input" "grep Hello" "awk '{count++} END {print count}'" outfile

and expected result is like this:
"awk"
"'{count++} END {print count}'"

then after that, creat a function to remove ' '.
*/