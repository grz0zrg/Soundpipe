#ifndef SK_OSC_H
typedef struct sk_osc sk_osc;
#endif

typedef struct {
    SPFLOAT freq, amp, iphs;
    sk_osc *osc;
} sp_osc;

int sp_osc_create(sp_osc **osc);
int sp_osc_destroy(sp_osc **osc);
int sp_osc_init(sp_data *sp, sp_osc *osc, sp_ftbl *ft, SPFLOAT iphs);
int sp_osc_compute(sp_data *sp, sp_osc *osc, SPFLOAT *in, SPFLOAT *out);
