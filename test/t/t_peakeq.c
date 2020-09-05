#include <math.h>
#include "soundpipe.h"
#include "md5.h"
#include "tap.h"
#include "test.h"

typedef struct {
    sp_noise *ns;
    sp_peakeq *peakeq;
    int counter;
} UserData;

int t_peakeq(sp_test *tst, sp_data *sp, const char *hash)
{
    sp_srand(sp, 0);
    uint32_t n;
    int fail = 0;
    UserData ud;
    SPFLOAT in = 0;
    SPFLOAT out = 0;

    ud.counter = 0;
    sp_noise_create(&ud.ns);
    sp_peakeq_create(&ud.peakeq);
    sp_noise_init(sp, ud.ns);
    sp_peakeq_init(sp, ud.peakeq);

    for(n = 0; n < tst->size; n++) {
        in = 0;
        out = 0;
        if(ud.counter == 0) {
            ud.peakeq->freq = 500 + sp_rand(sp) % 4000;
            ud.peakeq->bw = fabs(ud.peakeq->freq * 0.5);
        }
        sp_noise_compute(sp, ud.ns, NULL, &in);
        sp_peakeq_compute(sp, ud.peakeq, &in, &out);
        ud.counter = (ud.counter + 1) % 5000;
        sp_test_add_sample(tst, out);
    }

    fail = sp_test_verify(tst, hash);

    sp_noise_destroy(&ud.ns);
    sp_peakeq_destroy(&ud.peakeq);

    if(fail) return SP_NOT_OK;
    else return SP_OK;
}
