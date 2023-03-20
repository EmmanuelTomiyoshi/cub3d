# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 10:47:36 by etomiyos          #+#    #+#              #
#    Updated: 2023/03/20 10:21:31 by etomiyos         ###   ########.fr        #
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
FILES				=	destroy/destroy.c					\
						destroy/destroy_level.c				\
						destroy/exit.c						\
						map/map_utils.c						\
						map/map.c							\
						parse.c								\
						color/conversions.c					\
						color/brightness.c					\
						draw/draw.c							\
						draw/texture.c						\
						get_data/colors.c					\
						get_data/coordinates.c				\
						get_data/data.c						\
						get_data/player.c					\
						get_data/texture.c					\
						get_data/validations.c				\
						mlx/hooks/key_handle.c				\
						mlx/hooks/loop.c					\
						mlx/hooks/mouse.c					\
						mlx/hooks/resize.c					\
						mlx/hooks/toggle.c					\
						mlx/hooks/level.c					\
						mlx/pixel_put.c						\
						init/dda.c							\
						init/init.c							\
						init/keys.c							\
						init/mlx.c							\
						player/camera.c						\
						player/movements.c					\
						player/speed.c						\
						player/rotate.c						\
						algorithms/bresenham.c				\
						algorithms/dda.c					\
						algorithms/flood_fill.c				\
						algorithms/init.c					\
						algorithms/queue.c					\
						minimap/minimap.c					\
						minimap/init_minimap.c				\
						main.c								\
						init.c								\
						levels.c							\
						color/int_to_rgb.c					\
						draw/transparency.c					\
						button/button.c						\
						button/button_utils.c
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
