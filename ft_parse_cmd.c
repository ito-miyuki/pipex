/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:40:18 by mito              #+#    #+#             */
/*   Updated: 2024/04/29 13:53:11 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	ft_trim_quotes(char	*str)
{
	size_t	length;
	size_t	start;
	size_t	end;

	length = ft_strlen(str);
	if (length < 2)
		return ;
	start = 0;
	end = length - 1;
	if ((str[start] == 34 || str[start] == 39) && str[end] == str[start])
	{
		start++;
		end--;
	}
	if (start == 0)
		return ;
	if (start > end)
		*str = '\0';
	else
	{
		ft_memmove(str, str + start, end - start + 1);
		str[end - start + 1] = '\0';
	}
}

static void	ft_replace(char *str, size_t size, const char *chars, int c)
{
	size_t	str_idx;
	size_t	i;

	if (*str == '\0' || size == 0 || chars[0] == '\0')
		return ;
	str_idx = 0;
	while (str_idx < size)
	{
		i = 0;
		while (chars[i] != '\0')
		{
			if (str[str_idx] == chars[i])
				str[str_idx] = c;
			i++;
		}
		str_idx++;
	}
}

static void	handle_quote(char *str)
{
	char	*open_quote;
	char	*end_quote;

	open_quote = find_quote(str);
	if (open_quote == NULL)
		return ;
	end_quote = find_quote(open_quote + 1);
	while (end_quote != NULL && *end_quote != *open_quote)
		end_quote = find_quote(end_quote + 1);
	if (end_quote == NULL)
		handle_quote(open_quote + 1);
	str = end_quote + 1;
	ft_replace(open_quote, end_quote - open_quote + 1, "\f\n\r\t\v ", 31);
	handle_quote(str);
}

static char	**split_cmd(char *cmd)
{
	char	**tokens;
	int		i;

	handle_quote(cmd);
	ft_replace(cmd, ft_strlen(cmd), "\f\n\r\t\v", ' ');
	tokens = ft_split(cmd, ' ');
	if (tokens != NULL)
	{
		i = 0;
		while (tokens[i] != NULL)
		{
			ft_trim_quotes(tokens[i]);
			ft_trim(tokens[i], '\\');
			ft_replace(tokens[i], ft_strlen(tokens[i]), "\x1F", ' ');
			i++;
		}
	}
	return (tokens);
}

char	**ft_parse_cmd(const char *cmd)
{
	char	*dup;
	char	**tokens;

	if (cmd == NULL)
		return (NULL);
	dup = ft_strdup(cmd);
	if (dup == NULL)
		return (NULL);
	if (*dup == '\0' || ft_has_spaces_only(dup))
	{
		tokens = (char **)ft_calloc(2, sizeof(char *));
		if (tokens == NULL)
			return (NULL);
		tokens[0] = dup;
		return (tokens);
	}
	tokens = split_cmd(dup);
	free(dup);
	if (tokens == NULL)
		return (NULL);
	return (tokens);
}

// int main(void)
// {
// 	//const char str[] = "awk '{count++} END {print count}' 'abx asd casd'    ";
// 	//char str[] = "awk "{count++} END {print count}""; //これは出来ない
// 	//char str[] = "";
// 	// const char str[] = 'sed "s/And/But/"' 'awk '"'"'{count++} END {print count}'"'"'';
// 	// const char str[] = "'sed \"s/And/But/"'";
// 	const char *abc = "'sed \"s/And/But/\"' 'awk \"{count++} END {printf \"count: %i\\\" , count}\"' outfile.txt";
// 	char **cmd = ft_parse_cmd(abc);

// 	int i = 0;
// 	while (cmd && cmd[i] != NULL)
// 	{
// 		printf("%s\n", cmd[i]);
// 		i++;
// 	}
// }
