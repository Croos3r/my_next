#include <criterion/criterion.h>
#include "my_strings.h"

Test(string_manipulation, copy_simple)
{
    char const *source = "test";
    char *destination = malloc(sizeof(char) * (strlen(source) + 1));

    cr_expect_str_eq(my_strcpy(destination, source), source);
    cr_expect_str_eq(destination, source);
    free(destination);
}

Test(string_manipulation, copy_empty)
{
    char const *source = "";
    char *destination = malloc(sizeof(char) * (strlen(source) + 1));

    cr_expect_str_eq(my_strcpy(destination, source), source);
    cr_expect_str_eq(destination, source);
    free(destination);
}

Test(string_manipulation, copy_n_simple)
{
    char const *source = "test";
    char *destination = malloc(sizeof(char) * (strlen(source) + 1));

    cr_expect_str_eq(my_strncpy(destination, source, 3), "tes");
    cr_expect_str_eq(destination, "tes");
    free(destination);
}

Test(string_manipulation, copy_n_empty)
{
    char const *source = "";
    char *destination = malloc(sizeof(char) * (strlen(source) + 1));

    cr_expect_str_eq(my_strncpy(destination, source, 3), source);
    cr_expect_str_eq(destination, "");
    free(destination);
}

Test(string_manipulation, copy_n_zero)
{
    char const *source = "test";
    char *destination = malloc(sizeof(char) * (strlen(source) + 1));

    cr_expect_str_eq(my_strncpy(destination, source, 0), "");
    cr_expect_str_eq(destination, "");
    free(destination);
}

Test(string_manipulation, copy_n_overflow)
{
    char const *source = "test";
    char *destination = malloc(sizeof(char) * (strlen(source) + 1));

    cr_expect_str_eq(my_strncpy(destination, source, strlen(source) + 1),
        source);
    cr_expect_str_eq(destination, source);
    free(destination);
}

Test(string_manipulation, cat_simple)
{
    char *destination = malloc(sizeof(char) * (strlen("Hello World!") + 1));

    my_strcpy(destination, "Hello");
    cr_expect_str_eq(my_strcat(destination, " World!"), "Hello World!");
    cr_expect_str_eq(destination, "Hello World!");
    free(destination);
}

Test(string_manipulation, cat_empty_destination)
{
    char *destination = malloc(sizeof(char) * (strlen("test") + 1));

    my_strcpy(destination, "");
    cr_expect_str_eq(my_strcat(destination, "test"), "test");
    cr_expect_str_eq(destination, "test");
    free(destination);
}

Test(string_manipulation, cat_empty_source)
{
    char *destination = malloc(sizeof(char) * (strlen("test") + 1));

    my_strcpy(destination, "test");
    cr_expect_str_eq(my_strcat(destination, ""), "test");
    cr_expect_str_eq(destination, "test");
    free(destination);
}

Test(string_manipulation, cat_empty_both)
{
    char *destination = malloc(sizeof(char) * (strlen("") + 1));

    my_strcpy(destination, "");
    cr_expect_str_eq(my_strcat(destination, ""), "");
    cr_expect_str_eq(destination, "");
    free(destination);
}

Test(string_manipulation, cat_n_simple)
{
    char *destination = malloc(sizeof(char) * (strlen("Hello World!") + 1));

    my_strcpy(destination, "Hello");
    cr_expect_str_eq(my_strncat(destination, " World!", 3), "Hello Wo");
    cr_expect_str_eq(destination, "Hello Wo");
    free(destination);
}

Test(string_manipulation, cat_n_zero)
{
    char *destination = malloc(sizeof(char) * (strlen("Hello World!") + 1));

    my_strcpy(destination, "Hello");
    cr_expect_str_eq(my_strncat(destination, " World!", 0), "Hello");
    cr_expect_str_eq(destination, "Hello");
    free(destination);
}

Test(string_manipulation, cat_n_empty_source)
{
    char *destination = malloc(sizeof(char) * (strlen("test") + 1));

    my_strcpy(destination, "test");
    cr_expect_str_eq(my_strncat(destination, "", 3), "test");
    cr_expect_str_eq(destination, "test");
    free(destination);
}

Test(string_manipulation, cat_n_empty_destination)
{
    char *destination = malloc(sizeof(char) * (strlen("test") + 1));

    my_strcpy(destination, "");
    cr_expect_str_eq(my_strncat(destination, "test", 3), "tes");
    cr_expect_str_eq(destination, "tes");
    free(destination);
}

Test(string_manipulation, cat_n_empty_both)
{
    char *destination = malloc(sizeof(char) * (strlen("") + 1));

    my_strcpy(destination, "");
    cr_expect_str_eq(my_strncat(destination, "", 3), "");
    cr_expect_str_eq(destination, "");
    free(destination);
}

Test(string_manipulation, cat_n_overflow)
{
    char *destination = malloc(sizeof(char) * (strlen("Hello World!") + 1));

    my_strcpy(destination, "Hello");
    cr_expect_str_eq(my_strncat(destination, " World!", strlen(" World!") +
    1), "Hello World!");
    cr_expect_str_eq(destination, "Hello World!");
    free(destination);
}

Test(string_manipulation, duplication_simple)
{
    char const *source = "Hello World!";
    char *destination = my_strdup(source);

    cr_expect_str_eq(destination, "Hello World!");
    free(destination);
}

Test(string_manipulation, duplication_empty)
{
    char const *source = "";
    char *destination = my_strdup(source);

    cr_expect_str_eq(destination, "");
    free(destination);
}

Test(string_manipulation, duplication_n_simple)
{
    char const *source = "Hello World!";
    char *destination = my_strndup(source, 3);

    cr_expect_str_eq(destination, "Hel");
    free(destination);
}

Test(string_manipulation, duplication_n_empty)
{
    char const *source = "";
    char *destination = my_strndup(source, 3);

    cr_expect_str_eq(destination, "");
    free(destination);
}

Test(string_manipulation, duplication_n_overflow)
{
    char const *source = "Hello World!";
    char *destination = my_strndup(source, strlen("Hello World!") + 1);

    cr_expect_str_eq(destination, "Hello World!");
    free(destination);
}

Test(string_manipulation, duplication_n_zero)
{
    char const *source = "Hello World!";
    char *destination = my_strndup(source, 0);

    cr_expect_str_eq(destination, "");
    free(destination);
}

Test(string_comparison, compare_same)
{
    char const *str1 = "Hello World!";
    char const *str2 = "Hello World!";

    cr_expect_eq(my_strcmp(str1, str2), 0);
}

Test(string_comparison, compare_different)
{
    char const *str1 = "Dorian";
    char const *str2 = "Bryan";

    cr_expect_eq(my_strcmp(str1, str2), 2);
}

Test(string_comparison, compare_also_different)
{
    char const *str1 = "Bryan";
    char const *str2 = "Dorian";

    cr_expect_eq(my_strcmp(str1, str2), -2);
}

Test(string_comparison, compare_empty)
{
    char const *str1 = "";
    char const *str2 = "Hello World!";

    cr_expect_eq(my_strcmp(str1, str2), -72);
}

Test(string_comparison, compare_empty_empty)
{
    char const *str1 = "";
    char const *str2 = "";

    cr_expect_eq(my_strcmp(str1, str2), 0);
}

Test(string_comparison, compare_n_same)
{
    char const *str1 = "Hello World!";
    char const *str2 = "Hello World!";

    cr_expect_eq(my_strncmp(str1, str2, 3), 0);
}

Test(string_comparison, compare_n_different)
{
    char const *str1 = "Dorian";
    char const *str2 = "Bryan";

    cr_expect_eq(my_strncmp(str1, str2, 3), 2);
}

Test(string_comparison, compare_n_also_different)
{
    char const *str1 = "Bryan";
    char const *str2 = "Dorian";

    cr_expect_eq(my_strncmp(str1, str2, 3), -2);
}

Test(string_comparison, compare_n_empty)
{
    char const *str1 = "";
    char const *str2 = "Hello World!";

    cr_expect_eq(my_strncmp(str1, str2, 3), -72);
}

Test(string_comparison, compare_n_empty_empty)
{
    char const *str1 = "";
    char const *str2 = "";

    cr_expect_eq(my_strncmp(str1, str2, 3), 0);
}

Test(string_comparison, compare_n_overflow)
{
    char const *str1 = "Hello World!";
    char const *str2 = "Hello World!";

    cr_expect_eq(my_strncmp(str1, str2, strlen("Hello World!") + 1), 0);
}

Test(string_comparison, compare_n_overflow_different)
{
    char const *str1 = "Dorian";
    char const *str2 = "Bryan";

    cr_expect_eq(my_strncmp(str1, str2, strlen("Dorian") + 1), 2);
}

Test(string_search, chr_simple)
{
    cr_expect_str_eq(my_strchr(strdup("Hello World!"), 'o'), "o World!");
}

Test(string_search, chr_not_found)
{
    cr_expect_null(my_strchr(strdup("Hello World!"), 'z'));
}

Test(string_search, chr_empty)
{
    cr_expect_null(my_strchr(strdup(""), 'z'));
}

Test(string_search, chr_first)
{
    cr_expect_str_eq(my_strchr(strdup("Hello World!"), 'H'), "Hello World!");
}

Test(string_search, chr_last)
{
    cr_expect_str_eq(my_strchr(strdup("Hello World!"), '!'), "!");
}

Test(string_search, chrr_simple)
{
    cr_expect_str_eq(my_strrchr(strdup("Hello World!"), 'o'), "orld!");
}

Test(string_search, chrr_not_found)
{
    cr_expect_null(my_strrchr(strdup("Hello World!"), 'z'));
}

Test(string_search, chrr_first)
{
    cr_expect_str_eq(my_strrchr(strdup("Hello World!"), '!'), "!");
}

Test(string_search, chrr_last)
{
    cr_expect_str_eq(my_strchr(strdup("Hello World!"), 'H'), "Hello World!");
}

Test(string_search, chrr_empty)
{
    cr_expect_null(my_strrchr(strdup(""), 'z'));
}

Test(string_search, strstr_simple)
{
    cr_expect_str_eq(my_strstr(strdup("Hello World!"), "World!"), "World!");
}

Test(string_search, strstr_simple_not_found)
{
    cr_expect_null(my_strstr(strdup("Hello World!"), "Test"));
}

Test(string_search, strstr_empty_haystack)
{
    cr_expect_str_eq(my_strstr(strdup("Hello World!"), "Hello"), "Hello World!");
}

Test(string_search, strstr_empty_needle)
{
    cr_expect_str_eq(my_strstr(strdup("Hello World!"), ""), "Hello World!");
}

Test(string_search, strstr_empty_both)
{
    cr_expect_str_eq(my_strstr(strdup(""), ""), "");
}

Test(string_search, strstr_needle_bigger_than_haystack)
{
    cr_expect_null(my_strstr(strdup("Hello World!"), "Hello World! This is me!"));
}
