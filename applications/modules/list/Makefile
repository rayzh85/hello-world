
CUR_DIR = $(shell pwd)
TOP_DIR = ${CUR_DIR}/../..
DIR_SRC = ./src
DIR_OBJ = ./obj
DIR_BIN = ./bin

include ${TOP_DIR}/mk.rule

TARGET := listtest
INSTALL_DIR := $(TOP_DIR)/install

$(shell if [ ! -d $(DIR_OBJ) ] ; then mkdir $(DIR_OBJ) ; fi ;)
$(shell if [ ! -d $(DIR_BIN) ] ; then mkdir $(DIR_BIN) ; fi ;)

SRC = $(wildcard ${DIR_SRC}/*.c)  
OBJ = $(patsubst %.c,${DIR_OBJ}/%.o,$(notdir ${SRC})) 

BIN_TARGET = ${DIR_BIN}/${TARGET}

${BIN_TARGET}: ${OBJ}
	$(CC) $(OBJ) -o $@

${DIR_OBJ}/%.o:${DIR_SRC}/%.c
	$(CC) $(CFLAGS) -c  $< -o $@

.PHONY: clean all

clean:
	find ${DIR_OBJ} -name *.o -exec rm -rf {} \;
	rm -f ${BIN_TARGET}
	rm -f ${INSTALL_DIR}/${TARGET}

all: ${BIN_TARGET}
	cp -rf ${BIN_TARGET} ${INSTALL_DIR}/${TARGET}
