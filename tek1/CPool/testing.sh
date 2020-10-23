#!/bin/sh

echo -e "\e[1;95m
#########################################################################################
                                      TESTING
#########################################################################################
\e[0m"

echo -e "\e[1;95m
To make tests, enter the cmd to be test in the command variable and the output expected.
Then execute testing.sh


Made by CALVET Alexandre
\e[0m"

silent=$(make)

good_com=0
wrong_com=0

checkin_cmd() {
    echo -e "\e[1;4;2;35mCmd launched is :\e[0m" $command
    var=$($command 2>&1)
    echo -e "\e[1;36mOutput:\e[2;37m" $var "\e[0m"
    echo -e "\e[1;36mExpected:\e[2;37m" $exp "\e[0m"
    if [ "$var" == "$exp" ]
        then
            echo -e "\e[92mExec OK\e[0m\n"
            ((good_com++))
        else
            echo -e "\e[5;1;91mExec failed\e[0m\n"
            ((wrong_com++))
    fi
}

command=""
exp=""
checkin_cmd $command $exp

echo -e "\n\e[1;4;2;32mTotal test passed :\e[0m" $good_com
echo -e "\n\e[1;4;2;91mTotal test failed :\e[0m" $wrong_com

silent=$(make fclean)
