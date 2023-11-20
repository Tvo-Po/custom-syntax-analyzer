TARGET = analyzer

PREF_SRC = ./src/
PREF_OBJ = ./obj/

SRC = $(wildcard $(PREF_SRC)*.c)
OBJ = $(patsubst $(PREF_SRC)%.c, $(PREF_OBJ)%.o, $(SRC))

compile: $(OBJ)
	gcc $(OBJ) -o $(TARGET)

$(PREF_OBJ)%.o: $(PREF_SRC)%.c
	gcc -c $< -o $@ -I include

clean:
	rm $(TARGET) $(PREF_OBJ)*.o

