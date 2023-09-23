#include <stdlib.h>
#include <stdio.h>

char **ft_split(char *str, char *charset);
int count_words(char *str, char charset);
int check_delim(char c, char delim);
int str_len(char *str);
int word_len(char *str, char delim);


int main(void)
{
    int i = 0;
    char **test_string_array;
    int word_count = 0;
    char delim = '-';
    char str[] = "What-is-going-on";
    word_count = count_words(str, '-');
    test_string_array = ft_split(str, &delim);
    if (test_string_array == NULL)
    {
        return (0);
    }
    printf("%d\n", word_count);
    printf("%s\n", test_string_array[4]);
    while (i < word_count)
    {
        free(test_string_array[i]);
        i++;
    }
    free(test_string_array);
}

char **ft_split(char *str, char *charset)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int word_count = count_words(str, *charset);
    char **string_array = (char **)malloc((word_count + 1) * sizeof(char*));
    if (string_array == NULL)
    {
        return (0);
    }
    while (str[i] != '\0')
    {
        while (check_delim(str[i], *charset) == 1 && str[i] != '\0') // Skip the delimiters
        {
            i++;
        }
        if (str[i] != '\0') // If there is a word
        {
            int len = word_len(&str[i], *charset); // Calculate the word length
            string_array[j] = (char *)malloc((len + 1) * sizeof(char)); // Allocate memory for the word + null terminating character
            if (string_array[j] == NULL) // Check for allocation failure
            {
                return (NULL);
            }
            k = 0;
            while (check_delim(str[i], *charset) == 0 && str[i] != '\0')
            {
                string_array[j][k] = str[i];
                k++;
                i++;
            }
            string_array[j][k] = '\0';
            j++;
        }
    }
    string_array[j] = NULL;
    return (string_array);
}

int count_words(char *str, char charset)
{
    int i = 0;
    int word_count = 0;

    while (str[i] != '\0')
    {
        while (check_delim(str[i], charset) == 0 && str[i] != '\0')
        {
            if(check_delim(str[i + 1], charset) == 1)
            {
                word_count++;
            }
            i++;
        }
        i++;
    }
    if (check_delim(str[i - 1], charset) == 0)
    {
        word_count++;
    }
    return(word_count);
}

int check_delim(char c, char delim)
{
    int i = 0;
    if (c == delim)
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

int word_len(char *str, char delim)
{
    int i = 0;
    while (str[i] != '\0' && str[i] != delim)
    {
        i++;
    }
    return (i);
}