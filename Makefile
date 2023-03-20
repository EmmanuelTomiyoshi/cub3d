# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 10:47:36 by etomiyos          #+#    #+#              #
#    Updated: 2023/03/20 12:54:48 by mtomomit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME				=	cub3D

LFT					=	./libs/libft/libft.a
LFTDIR				=	./libs/libft/
MLXDIR				=	./libs/minilibx_linux/
SRCDIR				=	src/
OBJDIR				=	obj/
INCDIR				=	inc/

BIN					=	bin/cub3D
REQUIRED_DIRS		=	$(OBJDIR) bin/

LFTFLAGS			=	-lft -lmlx -lm -lbsd -lXext -lX11 -lft
CFLAGS				=	-Wall -Werror -Wextra
CFLAGS				+=	-g -I $(LFTDIR) -I $(INCDIR)
CC 					= 	cc -O3
CC 					+=	-march=native -mno-vzeroupper
FILES				=	algorithms/bresenham.c				\
						algorithms/dda.c					\
						algorithms/flood_fill.c				\
						algorithms/init.c					\
						algorithms/queue.c					\
						button/button_utils.c				\
						button/button.c						\
						color/brightness.c					\
						color/conversions.c					\
						color/int_to_rgb.c					\
						destroy/destroy_level.c				\
						destroy/destroy.c					\
						destroy/exit.c						\
						draw/draw.c							\
						draw/texture.c						\
						get_data/colors.c					\
						get_data/coordinates.c				\
						get_data/data.c						\
						get_data/levels.c					\
						get_data/player.c					\
						get_data/texture.c					\
						get_data/validations.c				\
						init/dda.c							\
						init/init.c							\
						init/keys.c							\
						init/map.c							\
						init/mlx.c							\
						map/levels.c						\
						map/map_utils.c						\
						map/map.c							\
						minimap/init.c						\
						minimap/minimap.c					\
						mlx/hooks/key_handle.c				\
						mlx/hooks/level.c					\
						mlx/hooks/loop.c					\
						mlx/hooks/mouse.c					\
						mlx/hooks/resize.c					\
						mlx/hooks/toggle.c					\
						mlx/pixel_put.c						\
						player/camera.c						\
						player/movements.c					\
						player/movements_utlis.c			\
						player/rotate.c						\
						player/speed.c						\
						init.c								\
						main.c								\
						parse.c
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
	@mkdir -p $@
	@mkdir -p $@algorithms
	@mkdir -p $@destroy
	@mkdir -p $@color
	@mkdir -p $@draw
	@mkdir -p $@get_data
	@mkdir -p $@mlx
	@mkdir -p $@mlx/hooks
	@mkdir -p $@player
	@mkdir -p $@minimap
	@mkdir -p $@button
	@mkdir -p $@init
	@mkdir -p $@map

$(OBJDIR)%.o: $(SRCDIR)%.c
	@echo -n "$(COLOR_YELLOW)Compiling $(NAME) $(COLOR_WHITE)$$(( \
	$(PROGRESS) * 100 / $(NUMBER_SRC_FILES)))%\r"
	$(eval PROGRESS=$(shell echo $$(($(PROGRESS)+1))))
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LFT) $(REQUIRED_DIRS) $(OBJ) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) -L $(LFTDIR) $(LFTFLAGS) -o $(BIN)
	cp $(BIN) $(NAME)
	@echo "$(COLOR_GREEN)$(NAME) has compiled succesfully\
	$(COLOR_WHITE)"

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
