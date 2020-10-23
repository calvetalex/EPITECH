#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <string>
#include <iostream>
#include "../Priest.hpp"

Test(Priest, test_init)
{
    Priest s("Roger", 1);
    cr_assert_str_eq(s.getName().c_str(), "Roger");
    cr_assert_eq(s.getPv(), 100);
    cr_assert_eq(s.getPower(), 100);
    cr_assert_eq(s.getLvl(), 1);
    cr_assert_eq(s.getStrength(), 4);
    cr_assert_eq(s.getStamina(), 4);
    cr_assert_eq(s.getIntelligence(), 42);
    cr_assert_eq(s.getSpirit(), 21);
    cr_assert_eq(s.getAgility(), 2);
}

Test(Priest, test_close_attack)
{
    Priest s("Bob", 1);
    cr_assert_eq(s.CloseAttack(), 31);
}

Test(Priest, test_no_mana)
{
    Priest s("D", 1);
    for (int i = 0; i < 11; i++)
        s.RangeAttack();
    cr_assert_eq(s.CloseAttack(), 0);
    cr_assert_eq(s.RangeAttack(), 0);
}