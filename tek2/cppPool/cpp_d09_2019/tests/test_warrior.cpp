#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <string>
#include <iostream>
#include "../Warrior.hpp"

Test(warrior, test_init)
{
    Warrior s("Roger", 1, "sword");
    cr_assert_str_eq(s.getName().c_str(), "Roger");
    cr_assert_eq(s.getPv(), 100);
    cr_assert_eq(s.getPower(), 100);
    cr_assert_eq(s.getLvl(), 1);
    cr_assert_eq(s.getStrength(), 12);
    cr_assert_eq(s.getStamina(), 12);
    cr_assert_eq(s.getIntelligence(), 6);
    cr_assert_eq(s.getSpirit(), 5);
    cr_assert_eq(s.getAgility(), 7);
}

Test(warrior, test_close_attack)
{
    Warrior s("Bob", 1);
    cr_assert_eq(s.CloseAttack(), 32);
}

Test(warrior, test_range_attack)
{
    Warrior s("B", 99);
    cr_assert_eq(s.RangeAttack(), 0);
}

Test(warrior, test_no_mana)
{
    Warrior s("D", 1);
    for (int i = 0; i < 4; i++)
        s.CloseAttack();
    cr_assert_eq(s.CloseAttack(), 0);
    cr_assert_eq(s.RangeAttack(), 0);
}