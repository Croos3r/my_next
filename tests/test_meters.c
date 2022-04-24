#include <criterion/criterion.h>
#include "my_meters.h"
#include <limits.h>

Test(meters_string, all)
{
    cr_expect_eq(my_strlen(""), 0);
    cr_expect_eq(my_strlen("Hello World!"), 12);
    cr_expect_eq(my_strlen("a"), 1);
    cr_expect_eq(my_strlen("\0"), 0);
    cr_expect_eq(my_strlen("\\0"), 2);
    cr_expect_eq(
        my_strlen(
            "aaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaa"
        ),
        260);
}

Test(meters_integer_common, binary)
{
    cr_expect_eq(my_intlen_base(0, "01"), 1);
    cr_expect_eq(my_intlen_base(42, "01"), 6);
    cr_expect_eq(my_intlen_base(-42, "01"), 7);
    cr_expect_eq(my_intlen_base(INT_MAX, "01"), 31);
    cr_expect_eq(my_intlen_base(INT_MIN, "01"), 33);
    cr_expect_eq(my_intlen_base(69, "01"), 7);
    cr_expect_eq(my_intlen_base(42694269, "01"), 26);
    cr_expect_eq(my_intlen_base(1, "01"), 1);
    cr_expect_eq(my_intlen_base(-1, "01"), 2);
    cr_expect_eq(my_intlen_base(777, "01"), 10);
}

Test(meters_integer_common, octal)
{
    cr_expect_eq(my_intlen_base(0, "01234567"), 1);
    cr_expect_eq(my_intlen_base(42, "01234567"), 2);
    cr_expect_eq(my_intlen_base(-42, "01234567"), 3);
    cr_expect_eq(my_intlen_base(INT_MAX, "01234567"), 11);
    cr_expect_eq(my_intlen_base(INT_MIN, "01234567"), 12);
    cr_expect_eq(my_intlen_base(69, "01234567"), 3);
    cr_expect_eq(my_intlen_base(42694269, "01234567"), 9);
    cr_expect_eq(my_intlen_base(1, "01234567"), 1);
    cr_expect_eq(my_intlen_base(-1, "01234567"), 2);
    cr_expect_eq(my_intlen_base(777, "01234567"), 4);
}

Test(meters_integer_common, decimal)
{
    cr_expect_eq(my_intlen(0), 1);
    cr_expect_eq(my_intlen(42), 2);
    cr_expect_eq(my_intlen(-42), 3);
    cr_expect_eq(my_intlen(INT_MAX), 10);
    cr_expect_eq(my_intlen(INT_MIN), 11);
    cr_expect_eq(my_intlen(69), 2);
    cr_expect_eq(my_intlen(42694269), 8);
    cr_expect_eq(my_intlen(1), 1);
    cr_expect_eq(my_intlen(-1), 2);
    cr_expect_eq(my_intlen(777), 3);
}

Test(meters_integer_common, hexadecimal)
{
    cr_expect_eq(my_intlen_base(0, "0123456789ABCDEF"), 1);
    cr_expect_eq(my_intlen_base(42, "0123456789ABCDEF"), 2);
    cr_expect_eq(my_intlen_base(-42, "0123456789ABCDEF"), 3);
    cr_expect_eq(my_intlen_base(INT_MAX, "0123456789ABCDEF"), 8);
    cr_expect_eq(my_intlen_base(INT_MIN, "0123456789ABCDEF"), 9);
    cr_expect_eq(my_intlen_base(69, "0123456789ABCDEF"), 2);
    cr_expect_eq(my_intlen_base(42694269, "0123456789ABCDEF"), 7);
    cr_expect_eq(my_intlen_base(1, "0123456789ABCDEF"), 1);
    cr_expect_eq(my_intlen_base(-1, "0123456789ABCDEF"), 2);
    cr_expect_eq(my_intlen_base(777, "0123456789ABCDEF"), 3);
}

Test(meters_integer_special, empty_base)
{
    cr_expect_eq(my_intlen_base(0, ""), 0);
}

Test(meters_integer_special, singleton_base)
{
    cr_expect_eq(my_intlen_base(45, "a"), 45);
    cr_expect_eq(my_intlen_base(0, "a"), 1);
}
