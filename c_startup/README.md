c and cpp startup analysis
==========================

Some analysis of the simple hello_world program.


build all
---------

	make &> output_build.txt

See output_build.txt for content.
For example the default configs used when build without any additional argumens like -Wall.
Also the C runtime libraries (\*crt\*) and the gcc specific libs (lgcc\_s) are shown.
See also https://gcc.gnu.org/onlinedocs/gccint/Collect2.html for more info about linker topics at startup.


additional stuff
----------------

([TODO](TODO.md))
