#https://opensource.com/article/18/8/what-how-makefile

.PHONY = all clean

CC := gcc

LINKERFLAG = -lm
SRCS := $(wildcard *.c) # wildcard la function dung de lay tat ca nhung file .c trong directory
BINS := $(SRCS:%.c=%) # Bo tat ca duoi .c cua cac file

all: ${BINS}

%: %.o
	@echo "Checking.."
	${CC} ${LINKERFLAG} $< -o $@

%.o: %.c
	@echo "Creating object.."
	${CC} -c $<
	
clean:
	@echo "Cleaning up..."
	rm -rvf *.o ${BINS}
