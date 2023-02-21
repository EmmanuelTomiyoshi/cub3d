NAME				=	cub3d

SRCDIR				=	src/
OBJDIR				=	obj/
INCDIR				=	inc/

BIN					=	bin/cub3d
REQUIRED_DIRS		=	$(OBJDIR) bin/
CFLAGS				=	-Wall -Werror -Wextra
CFLAGS				+=	-g -I ${INCDIR}
CC					=	cc
FILES				=	main.c
SRC					=	$(addprefix $(SRCDIR), $(FILES))
OBJ					=	$(addprefix $(OBJDIR), $(FILES:.c=.o))

COLOR_WHITE			=	\e[00m
COLOR_GREEN			=	\e[32m
COLOR_RED			=	\e[91m
COLOR_YELLOW		=	\e[033m
COLOR_BLUE			=	\e[34m

NUMBER_SRC_FILES	=	$(words $(SRC))
PROGRESS			=	0

all: $(NAME)

$(REQUIRED_DIRS):
	mkdir -p $@

${OBJDIR}%.o: ${SRCDIR}%.c
	@echo -n "$(YELLOW)Compiling $(WHITE)$$(( $(PROGRESS) * 100 / $(NUMBER_SRC_FILES)))%\r"
	$(eval PROGRESS=$(shell echo $$(($(PROGRESS)+1))))
	@${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${REQUIRED_DIRS} ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${BIN}
	cp ${BIN} ${NAME}
	@echo "$(COLOR_GREEN)$(NAME) has compiled succesfully$(COLOR_WHITE)"

$(OBJ_DIR):
	mkdir -p $@

clean:
	@echo "$(COLOR_BLUE)Removing all objects$(COLOR_WHITE)"
	rm -rf ${OBJDIR}

fclean: clean
	@echo "$(COLOR_BLUE)Removing $(NAME)$(COLOR_WHITE)"
	rm -rf ${NAME}
	rm -rf ${BIN}
	rm -rf bin/

re: fclean all

.PHONY: all clean fclean re




