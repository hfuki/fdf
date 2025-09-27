NAME = fdf
CC = cc
CFLAGS = -Wall -Werror -Wextra
INCS = -Iinclude -Iminilibx
SRC = main.c draw_line.c draw_map.c
OBJ = $(SRC:.c=.o)

MLXDIR = minilibx
MLXFLAGS = -L$(MLXDIR) -lmlx -lXext -lX11 -lm

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(INCS) $(MLXFLAGS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
