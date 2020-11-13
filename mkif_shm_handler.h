// SPDX-License-Identifier: (MIT)
/*
 * Copyright (c) 2020 Institute for Control Engineering of Machine Tools and Manufacturing Units, University of Stuttgart
 * Author: Philipp Neher <philipp.neher@isw.uni-stuttgart.de>
 */

/*
 * This interfaces the shared memory.
 */

#ifndef _MKIF_SHMHANDLER_H_
#define _MKIF_SHMHANDLER_H_

#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "demoapps_common/mk_shminterface.h"

/* opens the shared memory (read writeonly) with the information from the control */
struct mk_mainoutput* opnShM_mainout();

/* opens the shared memory (read writeonly) with the information from the control */
struct mk_additionaloutput* opnShM_addout();

/* opens the shared memory (read only) with the information from the axises */
struct mk_maininput* opnShM_mainin();

/* closes opened shared memories */
void clsmainoutShM(struct mk_mainoutput** mk_mainout);
void clsaddoutShM(struct mk_additionaloutput** mk_addout);
void clsmaininShM(struct mk_maininput** mk_mainin);

#endif /* _MKIF_SHMHANDLER_H_ */