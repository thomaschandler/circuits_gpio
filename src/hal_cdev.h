#ifndef HAL_CDEV_H
#define HALCDEV_H

#include <erl_nif.h>

struct cdev_priv {
  int chip_fd;
};

#endif