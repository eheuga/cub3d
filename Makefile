#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~CONFIG~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
NAME		= cub3D
OBJS_PATH	= ./objs

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
HEADER		= ./include/cub3d.h


MLX_DIR		= ./minilibx-linux
MLX			= $(MLX_DIR)/libmlx.a

LIBFT_DIR	= ./Libft
LIBFT		= $(LIBFT_DIR)/libft.a

INCLUDES	= -I ./include -I $(MLX_DIR) -I $(LIBFT_DIR)
LFLAGS		= -L $(LIBFT_DIR) -lft -L $(MLX_DIR) -lmlx -lXext -lX11 -lm
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~SOURCES~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
SRCS		=	srcs/main.c \
				srcs/init/init_game.c \
				srcs/init/init_player.c \
				srcs/init/init_ray.c \
				srcs/dda/perform_dda.c \
				srcs/draw/draw_loop.c \
				srcs/draw/draw_background.c \
				srcs/draw/draw_map.c \
				srcs/draw/draw_square.c \
				srcs/draw/draw_walls.c \
				srcs/keys/key_press.c \
				srcs/keys/key_release.c \
				srcs/player/player_movement.c \
				srcs/utils/close_prog.c \
				srcs/utils/free_all.c \
				srcs/parsing/parsing.c \
				srcs/parsing/parsing_utils.c \
				srcs/parsing/map_check.c \
				srcs/parsing/find_args.c \
				srcs/parsing/parse_map.c \
				srcs/parsing/parse_textures.c \
				srcs/parsing/parse_color.c \
				srcs/parsing/parse_player.c



SRCS_BONUS	= srcs_bonus/main_bonus.c

OBJS		= $(SRCS:%.c=$(OBJS_PATH)/%.o)
TOTAL		:= $(words $(SRCS))
DONE		= 0
BAR_LEN		= 30

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~DIRECTIVES~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)
	@printf "\r\033[K"
	@echo "✅ cub3D successfully compiled!"



$(LIBFT):
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)

$(MLX):
	@$(MAKE) --no-print-directory -C $(MLX_DIR) -f Makefile.mk INC=/usr/include > /dev/null 2>&1

$(OBJS_PATH)/%.o: %.c $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@$(eval DONE=$(shell expr $(DONE) + 1))
	@printf "\r\033[K\033[1;32m[%-$(BAR_LEN)s]\033[0m %3d%%  %s" \
		"$$(printf '#%.0s' $$(seq 1 $$(expr $(DONE) \* $(BAR_LEN) / $(TOTAL))))" \
		"$$(expr $(DONE) \* 100 / $(TOTAL))" "$(notdir $<)"

bonus:
	@$(MAKE) --no-print-directory SRCS="$(SRCS_BONUS)" OBJS_PATH=./objs_bonus

clean:
	@rm -rf ./objs ./objs_bonus
	@$(MAKE) --no-print-directory -C $(MLX_DIR) -f Makefile.mk clean > /dev/null
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean
	@echo "✅ Object files successfully removed!"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean
	@echo "✅ Executable successfully removed!"

re: fclean all

.PHONY: all bonus clean fclean re
