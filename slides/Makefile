SLIDES := gdb-intro.md  \
  ../exp/exp.md ../exp/exp-soln.md \
  ../square_ints/square_ints.md ../square_ints/square_ints-soln.md

presentation.html: presentation.template.html ${SLIDES}
	/usr/local/bin/python combine-slides.py -t "GDB Intro" ${SLIDES} -o $@
