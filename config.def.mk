MODULES= \
base \
ftbl \
adsr \
autowah \
biscale \
blsaw \
blsquare \
bltriangle \
butlp \
butbp \
buthp \
butbr \
brown \
clamp \
clock \
compressor \
count \
crossfade \
delay \
diode \
dmetro \
dtrig \
expon \
in \
incr \
jcrev \
line \
loadwav \
lpc \
maygate \
metro \
noise \
nsmp \
osc \
paulstretch \
peaklim \
phaser \
phasor \
pinknoise \
prop \
pshift \
randmt \
random \
randh \
reverse \
rpt \
saturator \
samphold \
scale \
scrambler \
sdelay \
slice \
smoothdelay \
smoother \
spa \
sparec \
switch \
tadsr \
talkbox \
tblrec \
tdiv \
tenv \
tenv2 \
tenvx \
tgate \
thresh \
timer \
tin \
trand \
tseg \
tseq \
voc \
wavin \
wavout \
wpkorg35 \
zitarev \
bitcrush \
bigverb \
dcblocker \
fmpair \
rline \
vardelay \
peakeq \
modalres \
phasewarp \
tread \

TANGLED += \
tangled/osc.o \
tangled/bigverb.o \
tangled/dcblocker.o \
tangled/fmpair.o \
tangled/rline.o \
tangled/vardelay.o \
tangled/peakeq.o \
tangled/modalres.o \
tangled/phasewarp.o \

NO_LIBSNDFILE=1
CFLAGS += -DNO_LIBSNDFILE

# ini parser needed for nsmp module
include lib/inih/Makefile

# Header files needed for modules generated with FAUST
CFLAGS += -Ilib/faust

# fft library
include lib/fft/Makefile

include lib/kissfft/Makefile
MODULES += fftwrapper
MODULES += padsynth

# Uncomment to use FFTW3 instead of kissfft.
# CFLAGS += -DUSE_FFTW3

# Soundpipe audio
include lib/spa/Makefile

# openlpc
include lib/openlpc/Makefile

# drwav
include lib/dr_wav/Makefile

CFLAGS += -fPIC -g

# Uncomment this to use double precision
#USE_DOUBLE=1
