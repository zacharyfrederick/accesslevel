#pragma once
#include <sys/syscall.h>
#include <stdio.h>
#include <linux/kernel.h>
#include <linux/types.h>

//library functions
int set_access_level(int pid, int new_level);
int get_access_level(int pid);

//harness functions
int *retrieve_set_access_params(int pid, int new_level);
int *retrieve_get_access_params(int pid);
int interpret_set_access_result(int ret_value);
int interpret_get_access_result(int ret_value);
