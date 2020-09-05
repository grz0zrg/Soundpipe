.PHONY: all clean install docs bootstrap util

default: all

VERSION = 2.0.0

PREFIX ?= /usr/local

LIBSOUNDPIPE = libsoundpipe.a

ifndef CONFIG
CONFIG = config.mk
endif

HPATHS += $(addprefix h/, $(addsuffix .h, $(MODULES)))
MPATHS += $(addprefix modules/, $(addsuffix .o, $(MODULES)))

include $(CONFIG)

ifeq ($(USE_DOUBLE), 1)
CFLAGS+=-DUSE_DOUBLE
SPFLOAT=double
else
SPFLOAT=float
endif

CFLAGS += -DSP_VERSION=$(VERSION) -O3 -DSPFLOAT=${SPFLOAT}
CFLAGS += -Ih -I/usr/local/include -fPIC
CFLAGS += -I.
CFLAGS += -Wall -pedantic
UTIL += util/wav2smp

C89=$(CC) -std=c89
C99=$(CC) -std=c99

libsoundpipe.a: $(MPATHS) $(LPATHS) $(TANGLED)
	@echo "Creating $@"
	@$(AR) rcs $@ $(MPATHS) $(LPATHS) $(TANGLED)

h/soundpipe.h: $(HPATHS)
	echo "#ifndef SOUNDPIPE_H" > $@
ifdef USE_DOUBLE
	echo "#define USE_DOUBLE" >> $@
endif
	echo "#define SOUNDPIPE_H" >> $@
	cat $(HPATHS) >> $@
	echo "#endif" >> $@

h/sp_base.h: h/base.h
	>$@
	echo "#ifndef SOUNDPIPE_H" >> $@
ifdef USE_DOUBLE
	echo "#define USE_DOUBLE" >> $@
endif
	echo "#define SOUNDPIPE_H" >> $@
	cat $< >> $@
	echo "#endif" >> $@

modules/%.o: modules/%.c h/soundpipe.h
	$(C89) $(CFLAGS) -c -static $< -o $@

tangled/%.o: %.c h/soundpipe.h
	$(C89) $(CFLAGS) -c -static $< -o $@

config.mk: config.def.mk
	cp $< $@

sp_dict.lua:
	cat modules/data/*.lua > $@

docs:
	util/gendocs.sh

all: config.mk libsoundpipe.a sp_dict.lua h/sp_base.h

install: \
	h/soundpipe.h \
	h/sp_base.h \
	libsoundpipe.a
	install h/soundpipe.h /usr/local/include/
	install h/sp_base.h /usr/local/include/
	install libsoundpipe.a /usr/local/lib/

clean:
	$(RM) h/soundpipe.h
	$(RM) -r docs
	$(RM) libsoundpipe.a
	$(RM) soundpipe.c
	$(RM) sp_dict.lua
	$(RM) $(LPATHS)
	$(RM) $(MPATHS)
	$(RM) $(TANGLED)
	$(RM) h/sp_base.h
