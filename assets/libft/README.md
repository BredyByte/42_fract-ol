# 42_LIbft Documentation:

<b>isalpha</b> - <mark>int ft_isalpha(int c);</mark> Function returns 1 if it is any letter of the Latin alphabet, otherwise 0. Takes as an argument a number - the character code.

<b>isdigit</b> - <mark>int ft_isdigit(int c);</mark> Function returns 1 if the number is prime, otherwise 0. Takes a number as an argument.

<b>isalnum</b> - <mark>int	ft_isalnum(int c);</mark> Function returns 1 if the argument element is a letter of the Latin alphabet (does not matter lower or upper case), or a prime number. Otherwise 0. Takes a number as an argument.

<b>isascii</b> - <mark>int	ft_isascii(int c);</mark> Function returns 1 if the argumen is ASCII, otherwise 0. Take a number as an argument.

<b>isprint</b> - <mark>int	ft_isprint(int c);</mark> Function returns 1 if the argument element is printable (the ASCII table elements with digit code from 32 to 126 inclusive), otherwise 0. Takes a number as an argument.

<b>strlen</b> - <mark>size_t	ft_strlen(const char *s);</mark> Function returns the length of the string. Takes as an argument pointer to the first element of the string.

<b>memset</b> - <mark>void	*ft_memset(void *b, int c, size_t len);</mark> Function returns a pointer to an array of any type. Takes 1 - pointer to the first element of an array of any type, 2 - element with which we want to replace the elements in the string, 3 - length - how many elements we want to replace.

<b>bzero</b> - <mark>void	ft_bzero(void *s, size_t n);</mark> Function returns nothing. Takes 1 - pointer to the first element of an array of any type, 2 - length, how many elements need to be replaced by zeros.

<b>memcpy</b> - <mark>void	*ft_memcpy(void *dest, const void *src, size_t len);</mark> Function returns a pointer to the first element of an array of any type. Takes as arguments  1 - pointer to the first element of an array of any type, an array whose elements will be replaced, 2 - pointer to the first element of an array of any type, an array whose elements will replace the elements of the first array, 3 - length - how many elements need to be replaced.

<b>memmove</b> - <mark>void	*ft_memmove(void *dest, const void *src, size_t len);</mark> Function is similar to memcpy, but with one difference, it can handle cases when the memory areas indicated by src and dest intersect.

<b>strlcpy</b> - <mark>size_t	ft_strlcpy(char *dest, const char *src, size_t len);</mark> Function returns the length of the src string. Takes as arguments 1 - pointer to the first element of the characters array - dest. 2 - pointer constant to the first element of character array - src, 3 - the length - how many characters should be placed from the src string into the dest string.
The function copies the contents of the src string to a dst buffer of data size bytes, while it is guaranteed that the dst will end with a null character.

<b>strlcat</b> - <mark>size_t	ft_strlcat(char *dest, const char *src, size_t len);</mark> Function returns the length of the dest string + the length of the src string. Takes as arguments  1 - char *dest - an array where the src string will be placed, 2 - const char *src - a string that will be placed in dest, 3 - unsigned char len - the buffer size.
The function is designed to safely combine two dst and src strings. It adds the contents of the src string to the end of the dst string, and it is guaranteed that the dst will end with a null character.

<b>toupper</b> - <mark>int	ft_toupper(int c);</mark> Function returns the modified character, Takes as an argument a lowercase Latin alphabet character and conwert it to uppercase.

<b>tolower</b> - <mark>int	ft_tolower(int c);</mark> Function returns the modified character, Takes as an argument a uppercase Latin alphabet character and conwert it to lowercase.

<b>strchr</b> - <mark>char	*ft_strchr(const char *s, int c);</mark> Function returns a pointer to the first found character c in the string s. or NULL

<b>strrchr</b> - <mark>char *strrchr(const char *s, int c);</mark> Function returns the last found character c in the string s, or NULL otherwise.

<b>strncmp</b> - <mark>int strncmp(const char *s1, const char *s2, size_t n);</mark> Function returns the difference between s1 and s2 comparing strings until either the characters are different or the index of the characters being compared is greater than n.

<b>memchar</b> - <mark>void *ft_memchr(const void *s, int c, size_t n);</mark> Function is very similar to strchr, but in this case the received and returned values are pointers to the first element of the array without a specific type.

<b>memcmp</b> - <mark>int	ft_memcmp(const void *s1, const void *s2, size_t n);</mark> Function is very similar to strcmp, but in this case, the pointers that the function compares come into it as pointers to an array of indeterminate type.

<b>strnstr</b> - <mark>char *ft_strnstr(const char *haystack, const char *needle, size_t len);</mark> Function takes as arguments: haystack string in which to perform the check. needle - pointer to the string to be found. len is the maximum number of characters to search . The function is used to search for the first occurrence of the needle substring in the haystack string with a length of no more than len characters.

<b>atoi</b> - <mark>int atoi(const char *str);</mark> Function converts a string to a number. At the same time, the function ignores all the characters \f, \n, \r, \t, \v, ‘ ’,with a single minus sign, it changes the sign to the opposite, the next sign + or - ignores, and then if the element is not a prime number returns 0 otherwise the number is according to this formula res = res * 10 + (*str++ - ‘0’);

<b>calloc</b> - <mark>void *calloc(size_t num, size_t size)</mark> Function takes as arguments: num - the number of elements for which memory needs to be allocated, size - the size of each element in bytes. The function returns the pointer to the allocated memory using malloc, but unlike malloc, the calloc function fills all memory cells with a null element, and does not leave them empty.

<b>strdup</b> - <mark>char *strdup(const char *s1); </mark> Function creates a new array using malloc, copies data from s1 to a new array,the function returns a pointer to the first element of the new array. The last element of the new array must always be NULL.

<b>ft_substr </b> - <mark>char *ft_substr(char const *s, unsigned int start, size_t len); </mark>  Function reserves space for a new string and returns the substring ”s”, the substring starts with the index start. The substring must have a length of len characters of the string

<b>ft_strjoin</b> - <mark>char *ft_strjoin(char const *s1, char const *s2);</mark> Function reserves memory using malloc and returns a new string - concatenation s1 + s2.

<b>ft_strtrim</b> - <mark>char *ft_strtrim(char const *s1, char const *set);</mark> Function takes two strings, s1 is the string that we will work with, set is a string of characters that need to be removed. The function removes from the beginning and end of the s1 string, elements from set, and returns s1 without set characters.

<b>ft_split</b> - <mark>char **ft_split(char const *s, char c);</mark> Function takes two arguments s - a string of characters with which we will work, and c - a character by which we will divide the string into substrings. The function reserves memory for an array of strings, and splits the string by the separator ’c’ into substrings, putting them in this memory. The function returns an array of string, or NULL in case of a memory allocation error.

<b>ft_itoa</b> - <mark>char *ft_itoa(int n);</mark> Function takes a number and should return it in string format. Returns either a string of numbers or NULL if there is a problem with memory reservation.

<b>ft_strmapi</b> - <mark>char *ft_strmapi(char const *s, char (*f)(unsigned int, char));</mark> Function takes as arguments string and a function. The function returns a new string, with the elements of the string s, each character of which has passed through the function f.

<b>ft_striteri</b> - <mark>void ft_striteri(char *s, void (*f)(unsigned int, char*));</mark> Function does not return anything, it just passes through the function f, each character of the string s.

<b>ft_putchar_fd</b> - <mark>void	ft_putchar_fd(char c, int fd);</mark> Function returns nothing. Takes as arguments a character to be output to the console, and a file descriptor.

<b>ft_putstr_fd</b> - <mark>void ft_putstr_fd(char *s, int fd); </mark> Function returns nothing. Takes as arguments  a string and a file descriptor. The function must use the write function for each element of the array, with the file descriptor that is given to it.

<b>ft_putendl_fd </b> - <mark>void ft_putendl_fd(char *s, int fd);</mark> Function returns nothing. Takes as arguments a string and a file descriptor.The same as ft_putstr_fd, but should output “\n” at the end.

<b>ft_putnbr_fd </b> - <mark>void ft_putendl_fd(char *s, int fd);</mark> Function returns nothing. Takes as argumetns a numberand  a file descriptor. The function should print the number using the write function, with the file descriptor given to it.

Bonus Part:

<b>ft_lstnew</b> - <mark>t_list *ft_lstnew(void *content);</mark> Function takes as arguments a pointer to the content that needs to be placed in the newly created node. The function creates a new node with content that the function accepts. Don't forget to do this new->next = NULL.

<b>ft_lstadd_front</b> - <mark>void	ft_lstadd_front(t_list **lst, t_list *new);</mark> Function takes as arguments a list of nodes, and a new node. The function returns nothing. The function should place the new accepted node at the first position of the list of taken nodes. 

<b>ft_lstsize</b> - <mark>int	ft_lstsize(t_list *lst);</mark> Function takes as arguments a pointer to the first node  in the list of nodes. The function should return the length of the list of nodes.

<b>ft_lstlast </b> - <mark>t_list *ft_lstlast(t_list *lst); </mark> Function takes as arguments a pointer to the first node of the array of nodes. The function should return the pointer to the last item of the array of nodes.

<b>ft_lstadd_back</b> - <mark>ft_lstadd_back(t_list **lst, t_list *new); </mark> Function takes as arguments an array of nodes, and a new node. The function returns nothing. The function should place the new node at the end of the list of nodes.

<b>ft_lstdelone</b> - <mark>void ft_lstdelone(t_list *lst, void (*del)(void *));</mark> The function takes as arguments a pointer to the node and the function that will return data of the node. The function returns nothing. The function should delete using del function the content of the node, and clear the memory it.

<b>ft_lstclear </b> - <mark>void ft_lstclear(t_list **lst, void (*del)(void*));</mark> Function takes as arguments the pointer to the first node in the list of nodes, and the function that removes the content of the node. The function does not return anything. The function must delete the content and memory of each node in the list of nodes, and at the end set 0 as the first element of the node to avoid memory leakage.

<b>ft_lstiter </b> - <mark>void ft_lstiter(t_list *lst, void (*f)(void *));</mark> Function takes as arguments a pointer to the first node of the last of nodes, and the function. The function returns nothing. The function must apply given function to each node in the list of nodes.

<b>ft_lstmap </b> - <mark>t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));</mark> Function takes as arguments a pointer to the first node from the list of nodes, a function that needs to be applied to the content of each node, and a function that, in case of an error during memory allocation, will clear the content of the nodes. The function returns a pointer to a new array of nodes whose content has been changed by the function f, or NULL, in case of an error when allocating memory. The function should create a new array of nodes and apply the function f to the content of each node.
