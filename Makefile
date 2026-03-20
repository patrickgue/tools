PROGS=trim/trim base64/base64
LIBS=libtools/libtools.a
HEADERS=libtools/base64.h libtools/strutils.h

World:${LIBS} ${PROGS}

trim/trim: ${LIBS}
	${MAKE} -C trim


base64/base64: ${LIBS}
	${MAKE} -C base64

${LIBS}:
	${MAKE} -C libtools

install: $(PROGS)
	cp $(PROGS) /usr/local/bin/
	cp $(LIBS) /usr/local/lib/
	mkdir -p /usr/local/include/tools/ &&	cp $(HEADERS) /usr/local/include/tools/

clean:
	${MAKE} -C base64 clean
	${MAKE} -C trim clean
	${MAKE} -C libtools clean
