#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <string>
#include <iostream>
#include "../Mage.hpp"

Test(Mage, test_init)
{
    Mage s("Roger", 1);
    cr_assert_str_eq(s.getName().c_str(), "Roger");
    cr_assert_eq(s.getPv(), 100);
    cr_assert_eq(s.getPower(), 100);
    cr_assert_eq(s.getLvl(), 1);
    cr_assert_eq(s.getStrength(), 6);
    cr_assert_eq(s.getStamina(), 6);
    cr_assert_eq(s.getIntelligence(), 12);
    cr_assert_eq(s.getSpirit(), 11);
    cr_assert_eq(s.getAgility(), 7);
}

Test(Mage, test_close_attack)
{
    Mage s("Bob", 1);
    cr_assert_eq(s.CloseAttack(), 0);
}

Test(Mage, test_range_attack)
{
    Mage s("B", 99);
    cr_assert_eq(s.RangeAttack(), 31);
}

Test(Mage, test_no_mana)
{
    Mage s("D", 1);
    for (int i = 0; i < 4; i++)
        s.RangeAttack();
    cr_assert_eq(s.CloseAttack(), 0);
    cr_assert_eq(s.RangeAttack(), 0);
}