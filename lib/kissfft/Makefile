LPATHS += lib/kissfft/kiss_fft.o lib/kissfft/kiss_fftr.o
CFLAGS += -Ilib/kissfft/ -Dkiss_fft_scalar=$(SPFLOAT)

lib/kissfft/kiss_fft.o: lib/kissfft/kiss_fft.c
	$(C89) $< -c $(CFLAGS) -o $@

lib/kissfft/kiss_fftr.o: lib/kissfft/kiss_fftr.c
	$(C89) $< -c $(CFLAGS) -o $@
