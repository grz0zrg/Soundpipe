Soundpipe
=========

Soundpipe is a lightweight music DSP library written in C. It aims to provide
a set of high-quality DSP modules for composers, sound designers,
and creative coders.


Compilation
-----------

To compile:

make

sudo make install


Tests
-----

Tests in Soundpipe are used to determine whether or not modules behave as 
expected. Tests write the output of a module to memory, and check the MD5 hash 
value of the output against the MD5 value of a reference signal.

To build a test file, go into the test folder, and run "make". Then, run 
"./run.bin", which runs the tests. As the tests are run, an "ok" will appear in 
the log if a test passes, and a "not ok" will appear if a test fails. 

It is possible to hear the output of a particular test if you know the test 
number. You will need to have sox installed. For example, 
to hear what test 11 sounds like, run the following
commands:

./run.bin render 11

./write_wave.sh 0011.raw

This will generate a file called out.wav.

The testing utility has a few optional arguments. To see all possible arguments,
run "./run.bin help".

The Soundpipe Model
-------------------

Soundpipe is callback driven. Every time Soundpipe needs a frame, it will
call upon a single function specified by the user. Soundpipe modules are
designed to process a signal one sample at a time.  Every module follows the
same life cycle:

1. Create: Memory is allocated for the data struct.
2. Initialize: Buffers are allocated, and initial variables and constants
are set.
3. Compute: the module takes in inputs (if applicable), and generates a
single sample of output.
4. Destroy: All memory allocated is freed.

Documentation
-------------
If you have lua installed on your computer, you can generate the current html
documentation for soundpipe by running "make docs". A folder called "docs"
will be created. The top page for the documentation is docs/index.html.