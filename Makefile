# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 10:47:36 by etomiyos          #+#    #+#              #
#    Updated: 2023/02/25 04:23:34 by mtomomit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	cub3d

LFT					=	libft/libft.a
LFTDIR				=	libft/
MLXDIR				=	minilibx_linux/
SRCDIR				=	src/
OBJDIR				=	obj/
INCDIR				=	inc/

BIN					=	bin/cub3d
REQUIRED_DIRS		=	$(OBJDIR) bin/

LFTFLAGS			=	-lft -lmlx -lm -lbsd -lXext -lX11 -lft
CFLAGS				=	-Wall -Werror -Wextra
CFLAGS				+=	-g -I $(LFTDIR) -I $(INCDIR)
CC 					= 	cc -O3
CC 					+=	-march=native -mno-vzeroupper
FILES				=	destroy.c			\
						exit.c				\
						get_colors.c		\
						get_coordinates.c	\
						get_data.c			\
						init.c				\
						main.c				\
						parse.c				\
						render.c			\
						map.c				\
						queue.c				\
						flood_fill.c		\
						map_utils.c
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

$(OBJDIR)%.o: $(SRCDIR)%.c
	@echo -n "$(COLOR_YELLOW)Compiling $(COLOR_WHITE)$$(( $(PROGRESS) * 100 / $(NUMBER_SRC_FILES)))%\r"
	$(eval PROGRESS=$(shell echo $$(($(PROGRESS)+1))))
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LFT) $(REQUIRED_DIRS) $(OBJ) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) -L $(LFTDIR) $(LFTFLAGS) -o $(BIN)
	cp $(BIN) $(NAME)
	@echo "$(COLOR_GREEN)$(NAME) has compiled succesfully$(COLOR_WHITE)"

$(OBJ_DIR):
	mkdir -p $@

$(LFT):
	make -C $(LFTDIR)

$(MLX):
	make -C $(MLXDIR)

clean:
	@echo "$(COLOR_BLUE)Removing all objects$(COLOR_WHITE)"
	rm -rf $(OBJDIR)
	cd $(LFTDIR) && make clean
	cd $(MLXDIR) && make clean

fclean: clean
	@echo "$(COLOR_BLUE)Removing $(NAME)$(COLOR_WHITE)"
	rm -rf $(NAME)
	rm -rf $(BIN)
	rm -rf bin/
	rm -rf $(LFT)

re: fclean all

norm:
	@clear
	@norminette ${SRC} ${INCDIR}* | grep Error || true

.PHONY: all clean fclean re norm
