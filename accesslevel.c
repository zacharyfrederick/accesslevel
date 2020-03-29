#include <linux/types.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdlib.h>

#include "accesslevel.h"

#define SYS_GET_ACCESS_LEVEL 335
#define SYS_SET_ACCESS_LEVEL 336

int set_access_level(int pid, int new_level) {
	long error_code = syscall(SYS_SET_ACCESS_LEVEL, pid, new_level);

	if (error_code != 0) {
		return -1;
	} else {
		return new_level;
	}
}

int get_access_level(int pid) {
	long access_level = syscall(SYS_GET_ACCESS_LEVEL, pid);
	return access_level;
}

int *retrieve_set_access_params(int pid, int new_level){
	int *params = malloc(sizeof(*params)*4);
	params[0] = SYS_SET_ACCESS_LEVEL;
	params[1] = 2;
	params[2] = pid;
	params[3] = new_level;
	return params;
}

int *retrieve_get_access_params(int pid) {
	int *params = malloc(sizeof(*params) * 3);
	params[0] = SYS_GET_ACCESS_LEVEL;
	params[1] = 1;
	params[2] = pid;
	return params;
}

int interpret_set_access_result(int ret_value) {
	if (ret_value == 0) {
		return ret_value;
	} else {
		return -1;
	}
}

int interpret_get_access_result(int ret_value) {
	return ret_value;
}
