/*
 * Generic interface to a debug port adapter.
 *
 * Copyright (C) 2011 Serge Vakulenko
 *
 * This file is part of PIC32PROG project, which is distributed
 * under the terms of the GNU General Public License (GPL).
 * See the accompanying file "COPYING" for more details.
 */
#include <stdarg.h>

typedef struct _adapter_t adapter_t;

struct _adapter_t {
    unsigned user_start;                /* Start address of user area */
    unsigned user_nbytes;               /* Size of user flah area */

    void (*close) (adapter_t *a, int power_on);
    unsigned (*get_idcode) (adapter_t *a);
    void (*load_executable) (adapter_t *a,
        const unsigned *pe, unsigned nwords, unsigned pe_version);
    void (*read_data) (adapter_t *a, unsigned addr, unsigned nwords, unsigned *data);
    void (*verify_data) (adapter_t *a, unsigned addr, unsigned nwords, unsigned *data);
    void (*program_block) (adapter_t *a, unsigned addr, unsigned *data);
    void (*program_row128) (adapter_t *a, unsigned addr, unsigned *data);
    void (*program_row32) (adapter_t *a, unsigned addr, unsigned *data);
    void (*program_word) (adapter_t *a, unsigned addr, unsigned word);
    unsigned (*read_word) (adapter_t *a, unsigned addr);
    void (*erase_chip) (adapter_t *a);
};

adapter_t *adapter_open_pickit (void);
adapter_t *adapter_open_an1388 (void);
adapter_t *adapter_open_hidboot (void);
adapter_t *adapter_open_mpsse (void);

void mdelay (unsigned msec);
extern int debug_level;
