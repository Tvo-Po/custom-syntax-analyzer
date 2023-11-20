TARGET = analyzer

PREF_SRC = ./src/
PREF_OBJ = ./obj/

SRC = $(wildcard $(PREF_SRC)*.c)

# Remove parser code file to escape definition duplication
# SRC := $(patsubst $(PREF_SRC)parser.tab.c, , $(SRC))

OBJ = $(patsubst $(PREF_SRC)%.c, $(PREF_OBJ)%.o, $(SRC))

test:
	echo $(SRC)

compile: $(OBJ)
	gcc $(OBJ) -o $(TARGET)

$(PREF_OBJ)%.o: $(PREF_SRC)%.c
	gcc -c $< -o $@ -I include

$(PREF_SRC)lexems.yy.c: ./lex/lexems.l $(PREF_SRC)$(PARSER_CODE_NAME).c
	flex -o $(PREF_SRC)$(LEXEMS_CODE_NAME).c ./lex/lexems.l

$(PREF_SRC)$(PARSER_CODE_NAME).c: ./lex/parser.y
	bison -t -v -Wconflicts-sr --header=./include/$(PARSER_CODE_NAME).h \
				-o $(PREF_SRC)$(PARSER_CODE_NAME).c ./lex/parser.y

clean:
	rm $(TARGET) $(PREF_OBJ)*.o
