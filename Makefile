NAME = fdf
CC = cc
CFLAGS = -Wall -Werror -Wextra
INCS = -Iminilibx-linux
SRC = main.c draw_line.c draw_map.c read_map.c get_next_line_bonus.c get_next_line_utils_bonus.c
OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a
MLXDIR = minilibx-linux
MLXFLAGS = -L$(MLXDIR) -lmlx -lXext -lX11 -lm

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT) $(MLXDIR)/libmlx.a
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) $(INCS) $(MLXFLAGS)

%.o : %.c
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(LIBFT):
	@make -C libft

$(MLXDIR)/libmlx.a:
	@$(MAKE) -C $(MLXDIR)

clean :
	@rm -f $(OBJ)
	@make clean -C libft

fclean : clean
	@rm -f $(NAME)
	@make fclean -C libft

re : fclean all

.PHONY : all clean fclean re
