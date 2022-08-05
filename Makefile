SOURCE =  ./src/marl.c
OBJECTS = ${SOURCE:.c=.o}

all: libmarl
	@echo "DONE"

${OBJECTS}: src/%.o : src/%.c
	$(CC) -c $< -I ./include -o $@


libmarl: ${OBJECTS}
	ar r $@.a ./src/*.o
