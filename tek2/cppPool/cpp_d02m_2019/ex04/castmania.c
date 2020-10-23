/*
** EPITECH PROJECT, 2020
** castmania
** File description:
** main file
*/

#include <stdio.h>
#include "castmania.h"

void exec_operation(instruction_type_t instruction_type, void *data)
{
    instruction_t *inst = (instruction_t *) data;
    if (instruction_type == ADD_OPERATION) {
        exec_add((addition_t*) inst->operation);
        if (inst->output_type == VERBOSE) {
            printf("%i\n", ((addition_t*)inst->operation)->add_op.res);
        }
    } else if (instruction_type == DIV_OPERATION) {
        exec_div((division_t*)inst->operation);
        if (inst->output_type == VERBOSE) {
            if (((division_t*)inst->operation)->div_type == INTEGER) {
                printf("%i\n",
                ((integer_op_t*)((division_t*)inst->operation)->div_op)->res);
            } else
                printf("%f\n",
                ((decimale_op_t*)((division_t*)inst->operation)->div_op)->res);
        }
    }
}

void  exec_instruction(instruction_type_t  instruction_type , void *data)
{
    if (instruction_type == PRINT_INT) {
        printf("%i\n", *((int *)data));
    } else if (instruction_type == PRINT_FLOAT) {
        printf("%f\n", *(float*)data);
    } else {
        exec_operation(instruction_type, data);
    }
}