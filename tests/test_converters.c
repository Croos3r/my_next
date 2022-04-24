#include <criterion/criterion.h>
#include <limits.h>
#include "my_converters.h"

Test(converters_integer_special, empty_base)
{
    cr_expect_null(my_itoa_base(899, ""));
}

Test(converters_integer_special, singleton_base)
{
    cr_expect_str_eq(my_itoa_base(45, "a"),
                     "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    cr_expect_str_eq(my_itoa_base(-45, "a"),
                     "-aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
}

Test(converters_integer_common, binary)
{
    cr_expect_str_eq(my_itoa_base(0, "01"), "0");
    cr_expect_str_eq(my_itoa_base(1, "01"), "1");
    cr_expect_str_eq(my_itoa_base(-1, "01"), "-1");
    cr_expect_str_eq(my_itoa_base(INT_MAX, "01"),
                     "1111111111111111111111111111111");
    cr_expect_str_eq(my_itoa_base(INT_MIN, "01"),
                     "-10000000000000000000000000000000");
    cr_expect_str_eq(my_itoa_base(42, "01"), "101010");
    cr_expect_str_eq(my_itoa_base(-69, "01"), "-1000101");
    cr_expect_str_eq(my_itoa_base(42694269, "01"),
                     "10100010110111011001111101");
    cr_expect_str_eq(my_itoa_base(-42694269, "01"),
                     "-10100010110111011001111101");
}

Test(converters_integer_common, octal)
{
    cr_expect_str_eq(my_itoa_base(0, "01234567"), "0");
    cr_expect_str_eq(my_itoa_base(1, "01234567"), "1");
    cr_expect_str_eq(my_itoa_base(-1, "01234567"), "-1");
    cr_expect_str_eq(my_itoa_base(INT_MAX, "01234567"), "17777777777");
    cr_expect_str_eq(my_itoa_base(INT_MIN, "01234567"), "-20000000000");
    cr_expect_str_eq(my_itoa_base(42, "01234567"), "52");
    cr_expect_str_eq(my_itoa_base(-69, "01234567"), "-105");
    cr_expect_str_eq(my_itoa_base(42694269, "01234567"), "242673175");
    cr_expect_str_eq(my_itoa_base(-42694269, "01234567"), "-242673175");
}

Test(converters_integer_common, decimal)
{
    cr_expect_str_eq(my_itoa(0), "0");
    cr_expect_str_eq(my_itoa(1), "1");
    cr_expect_str_eq(my_itoa(-1), "-1");
    cr_expect_str_eq(my_itoa(INT_MAX), "2147483647");
    cr_expect_str_eq(my_itoa(INT_MIN), "-2147483648");
    cr_expect_str_eq(my_itoa(42), "42");
    cr_expect_str_eq(my_itoa(-69), "-69");
    cr_expect_str_eq(my_itoa(42694269), "42694269");
    cr_expect_str_eq(my_itoa(-42694269), "-42694269");
}

Test(converters_integer_common, hexadecimal)
{
    cr_expect_str_eq(my_itoa_base(0, "0123456789ABCDEF"), "0");
    cr_expect_str_eq(my_itoa_base(1, "0123456789ABCDEF"), "1");
    cr_expect_str_eq(my_itoa_base(-1, "0123456789ABCDEF"), "-1");
    cr_expect_str_eq(my_itoa_base(INT_MAX, "0123456789ABCDEF"), "7FFFFFFF");
    cr_expect_str_eq(my_itoa_base(INT_MIN, "0123456789ABCDEF"), "-80000000");
    cr_expect_str_eq(my_itoa_base(42, "0123456789ABCDEF"), "2A");
    cr_expect_str_eq(my_itoa_base(-69, "0123456789ABCDEF"), "-45");
    cr_expect_str_eq(my_itoa_base(42694269, "0123456789ABCDEF"), "28B767D");
    cr_expect_str_eq(my_itoa_base(-42694269, "0123456789ABCDEF"), "-28B767D");
}
