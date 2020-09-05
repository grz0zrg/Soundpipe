/* This code is placed in the public domain. */

#include <stdlib.h>
#include "soundpipe.h"
#include "lib/dr_wav/sp_dr_wav.h"

#define WAVOUT_BUFSIZE 1024

struct sp_wavout {
    drwav *wav;
    SPFLOAT buf[WAVOUT_BUFSIZE];
    int count;
};

int sp_wavout_create(sp_wavout **p)
{
    *p = malloc(sizeof(sp_wavout));
    return SP_OK;
}

int sp_wavout_destroy(sp_wavout **p)
{
    /* write any remaining samples */
    if ((*p)->count != 0) {
        sp_drwav_write((*p)->wav, (*p)->count, (*p)->buf);
    }
    sp_drwav_close((*p)->wav);
    free(*p);
    return SP_OK;
}

int sp_wavout_init(sp_data *sp, sp_wavout *p, const char *filename)
{
    p->count = 0;
    p->wav = sp_drwav_open_mono_write(filename, sp->sr);
    return SP_OK;
}

int sp_wavout_compute(sp_data *sp, sp_wavout *p, SPFLOAT *in, SPFLOAT *out)
{
    *out = *in;
    if(p->count == WAVOUT_BUFSIZE) {
        sp_drwav_write(p->wav, WAVOUT_BUFSIZE, p->buf);
        p->count = 0;
    }
    p->buf[p->count] = *in;
    p->count++;
    return SP_OK;
}
