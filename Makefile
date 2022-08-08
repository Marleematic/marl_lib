SRC = ./src/marl.c ./src/visual/marl_window.c ./src/util/marl_loop.c
OBJ =  $(SRC:.c=.o)

OUT = ./libmarl.a

INC = -I ./include

default: $(OUT)

.c.o:
	gcc $(INC) -c $< -o $@

$(OUT): $(OBJ)
	ar rcs $(OUT) $(OBJ)

clean:
	rm -f $(OBJ) $(OUT)
