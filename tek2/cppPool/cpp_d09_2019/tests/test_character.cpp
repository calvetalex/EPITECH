#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <string>
#include <iostream>
#include "../Character.hpp"

Test(Character, test_ctor) {
    Character s("Junior", 5);
    cr_assert_str_eq(s.getName().c_str(), "Junior");
    cr_assert_eq(s.getPv(), 100);
    cr_assert_eq(s.getPower(), 100);
    cr_assert_eq(s.getLvl(), 5);
    cr_assert_eq(s.getStrength(), 5);
    cr_assert_eq(s.getStamina(), 5);
    cr_assert_eq(s.getIntelligence(), 5);
    cr_assert_eq(s.getSpirit(), 5);
    cr_assert_eq(s.getAgility(), 5);
}

Test(Character, test_close_attack)
{
    Character s("Bob", 1);
    cr_assert_eq(s.CloseAttack(), 15);
}

Test(Character, test_range_attack)
{
    Character s("Bob", 1);
    cr_assert_eq(s.RangeAttack(), 10);
}

Test(Character, test_take_damage)
{
    Character s("Pouet", 1);
    s.TakeDamage(40);
    cr_assert_eq(s.getPv(), 60);
}

Test(Character, test_heal)
{
    Character s("Truk", 1);
    s.TakeDamage(70);
    s.Heal();
    cr_assert_eq(s.getPv(), 80);
}

Test(Character, test_max_power_and_heal)
{
    Character s("José", 1);
    s.Heal();
    s.RestorePower();
    cr_assert_eq(s.getPv(), 100);
    cr_assert_eq(s.getPower(), 100);
}

Test(Character, test_no_more_life)
{
    Character s("J", 1);
    s.TakeDamage(200);
    cr_assert_eq(s.getPv(), 0);
}

Test(Character, test_no_power)
{
    Character s("K", 1);
    for (int i = 0; i < 9; i++)
        s.CloseAttack();
    s.RangeAttack();
    s.CloseAttack();
    s.RangeAttack();
    cr_assert_eq(s.getPower(), 0);
}