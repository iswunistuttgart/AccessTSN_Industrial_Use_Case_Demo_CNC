// SPDX-License-Identifier: (MIT)
/*
 * Copyright (c) 2020 Institute for Control Engineering of Machine Tools and Manufacturing Units, University of Stuttgart
 * Author: Philipp Neher <philipp.neher@isw.uni-stuttgart.de>
 */

#include "mkif_shm_handler.h"

struct mk_mainoutput* opnShM_mainout()
{
        int fd;
        struct mk_mainoutput* shm;
        fd = shm_open(MK_MAINOUTKEY, O_RDWR | O_CREAT, 700);
        if (fd == -1) {
                perror("SHM Open failed");
                return(NULL);
        }
        ftruncate(fd,sizeof(struct mk_mainoutput));
        shm = mmap(NULL, sizeof(struct mk_mainoutput), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
        if (MAP_FAILED == shm) {
                perror("SHM Map failed");
                shm = NULL;
                shm_unlink(MK_MAINOUTKEY);
        }
        return shm;
}

struct mk_additionaloutput* opnShM_addout()
{
        int fd;
        struct mk_additionaloutput* shm;
        fd = shm_open(MK_ADDAOUTKEY, O_RDWR | O_CREAT, 700);
        if (fd == -1) {
                perror("SHM Open failed");
                return(NULL);
        }
        ftruncate(fd,sizeof(struct mk_additionaloutput));
        shm = mmap(NULL, sizeof(struct mk_additionaloutput), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
        if (MAP_FAILED == shm) {
                perror("SHM Map failed");
                shm = NULL;
                shm_unlink(MK_ADDAOUTKEY);
        }
        return shm;
}


struct mk_maininput* opnShM_mainin()
{
        int fd;
        struct mk_maininput* shm;
        fd = shm_open(MK_MAININKEY, O_RDONLY | O_CREAT, 700);
        if (fd == -1) {
                perror("SHM Open failed");
                return(NULL);
        }
        ftruncate(fd,sizeof(struct mk_maininput));
        shm = mmap(NULL, sizeof(struct mk_maininput), PROT_READ, MAP_SHARED, fd, 0);
        if (MAP_FAILED == shm) {
                perror("SHM Map failed");
                shm = NULL;
                shm_unlink(MK_MAININKEY);
        }
        return shm;
}

void clsmainoutShM(struct mk_mainoutput** mk_mainout)
{
        shm_unlink(MK_MAINOUTKEY);
        mk_mainout = NULL;
}

void clsaddoutShM(struct mk_additionaloutput** mk_addout)
{
        shm_unlink(MK_ADDAOUTKEY);
        mk_addout = NULL;
}

void clsmaininShM(struct mk_maininput** mk_mainin)
{
       shm_unlink(MK_MAININKEY);
       mk_mainin = NULL;
}