#include "push_swap.h"

char	*ft_strdup(const char *s)
{
	char	*s_dup;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	s_dup = (char *)malloc(sizeof(char) * (len + 1));
	if (s_dup == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		s_dup[i] = s[i];
		i++;
	}
	s_dup[i] = '\0';
	return (s_dup);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	sub_s = (char *)malloc(sizeof(char) * (len + 1));
	if (sub_s == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub_s[i] = s[start + i];
		i++;
	}
	sub_s[i] = '\0';
	return (sub_s);
}

t_stack	*ft_lstnew_addlast(t_stack **lst, t_stack *last, int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return (last);
	new_node->value = value;
	new_node->next = NULL;
	if (last == NULL)
		*lst = new_node;
	else
		last->next = new_node;
	return (new_node);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if ((*str == '-') || (*str == '+'))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		result = (result * 10) + (*str - 48);
		str++;
	}
	return ((int)(result * sign));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	len1;
	size_t	len2;
	size_t	i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	joined = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (joined == NULL)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		joined[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len2)
	{
		joined[len1 + i] = s2[i];
		i++;
	}
	joined[len1 + len2] = '\0';
	return (joined);
}

static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*get_word(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (ft_substr(s, 0, len));
}

static void	free_words(char **words, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(words[i]);
		i++;
	}
	free(words);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	int		count;
	int		i;

	count = count_words(s, c);
	words = (char **)malloc(sizeof(char *) * (count + 1));
	if (words == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		while (*s == c)
			s++;
		words[i] = get_word(s, c);
		if (words[i] == NULL)
		{
			free_words(words, i);
			return (NULL);
		}
		while (*s && *s != c)
			s++;
		i++;
	}
	words[i] = NULL;
	return (words);
}

char	**join_and_split(char **argv, int start)
{
	int	i;
	char	*space;
	char	*str;
	char	**arr;

	i = start;
	str = NULL;
	arr = NULL;
	space = malloc(2);
	if (!space)
		return (NULL);
	space = " ";
	while (argv[i])
	{
		str = ft_strjoin(str, space);
		str = ft_strjoin(str, argv[i]);
		i++;
	}
	arr = ft_split(str, ' ');
	if (!arr)
		return (NULL);
	return (arr);
}
