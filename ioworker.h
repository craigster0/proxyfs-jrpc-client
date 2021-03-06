// Copyright (c) 2015-2021, NVIDIA CORPORATION.
// SPDX-License-Identifier: Apache-2.0

#ifndef __PFS_IOWORKER_H__
#define __PFS_IOWORKER_H__

#include <stdio.h>
#include <stdlib.h>
#include <proxyfs.h>

int io_workers_start(char *server, int port, int count);
void io_workers_stop();
int schedule_io_work(proxyfs_io_request_t *req);

int proxyfs_read_req(proxyfs_io_request_t *req, int sock_fd);
int proxyfs_write_req(proxyfs_io_request_t *req, int sock_fd);

#endif
