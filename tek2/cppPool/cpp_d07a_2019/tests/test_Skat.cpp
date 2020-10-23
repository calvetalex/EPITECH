#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <string>
#include <iostream>
#include "../ex00/Skat.hpp"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Skat, test_ctor) {
    Skat s("Junior", 5);
    cr_assert_str_eq(s.name().c_str(), "Junior");
    cr_assert_eq(s.stimPaks(), 5);
}

Test(Skat, test_share_function)
{
    Skat s("Junior", 5);
    int16_t stock = 3;

    s.shareStimPaks(2, stock);
    cr_assert_eq(s.stimPaks(), 3);
    cr_assert_eq(stock, 5);
}

Test(Skat, test_share_function_greedy)
{
    Skat s("Junior", 1);
    int16_t stock = 3;

    s.shareStimPaks(2, stock);
    cr_assert_eq(s.stimPaks(), 1);
    cr_assert_eq(stock, 3);
}

Test(Skat, test_addStimPaks_null)
{
    Skat s("Junior", 1);

    s.addStimPaks(0);
    cr_assert_eq(s.stimPaks(), 1);
}

Test(Skat, test_add_stimPacks)
{
    Skat s("Junior", 2);
    s.addStimPaks(3);
    cr_assert_eq(s.stimPaks(), 5);
}

Test(Skat, use_stimpacks)
{
    Skat s("Junior", 1);
    s.useStimPaks();
    cr_assert_eq(s.stimPaks(), 0);
}

Test(Skat, use_stimpacks_fail)
{
    Skat s("Junior", 0);
    s.useStimPaks();
    cr_assert_eq(s.stimPaks(), 0);
}