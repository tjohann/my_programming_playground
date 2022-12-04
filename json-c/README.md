some stuff around json-c
========================


links
-----

https://linuxprograms.wordpress.com/2010/05/20/json-c-libjson-tutorial/

https://github.com/json-c/json-c

https://progur.com/2018/12/how-to-parse-json-in-c.html

https://www.youtube.com/watch?v=dQyXuFWylm4


tutorials
---------

https://github.com/json-c/json-c/wiki/List-of-json-c-tutorials

https://github.com/rbtylee/tutorial-jsonc/blob/master/tutorial/Intro.md


pkgconfig flags
---------------

	CFLAGS += $(shell pkg-config --cflags json-c)
	LDFLAGS += $(shell pkg-config --libs json-c)


useful tools
------------

jless: https://jless.io/

important shortcuts:

	q :quit :exit
	:help


summary
-------

JSON objects:

	collection of key/value pair -> c language construct -> struct
	ordered list of values -> c language construct -> array







additional stuff
----------------

([TODO](TODO.md))
