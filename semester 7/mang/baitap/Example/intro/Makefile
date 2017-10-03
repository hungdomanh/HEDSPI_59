include ../Make.defines

PROGS =	tcpcli01 tcpserv01

all:	${PROGS}

tcpcli01:	tcpcli01.o
		${CC} ${CFLAGS} -o $@ tcpcli01.o ${LIBS}

tcpserv01:	tcpserv01.o
		${CC} ${CFLAGS} -o $@ tcpserv01.o ${LIBS}

server:	server.o
		${CC} ${CFLAGS} -o $@ server.o ${LIBS}

client:	client.o
		${CC} ${CFLAGS} -o $@ client.o ${LIBS}

clean:
		rm -f ${PROGS} ${CLEANFILES}
