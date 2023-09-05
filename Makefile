PROGS=trim/trim
LIBS=libtools/libtools.a

World:${LIBS} ${PROGS}

trim/trim:
	${MAKE} -C trim


libtools/libtools.a:
	${MAKE} -C libtools


clean:
	${MAKE} -C trim clean
	${MAKE} -C libtools clean
