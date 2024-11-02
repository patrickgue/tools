PROGS=trim/trim base64/base64
LIBS=libtools/libtools.a

World:${LIBS} ${PROGS}

trim/trim: ${LIBS}
	${MAKE} -C trim


base64/base64: ${LIBS}
	${MAKE} -C base64

${LIBS}:
	${MAKE} -C libtools


clean:
	${MAKE} -C base64 clean
	${MAKE} -C trim clean
	${MAKE} -C libtools clean
