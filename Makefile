NAME :=  so_long
SRC :=  main.c set_map.c draw_map.c  GNL/get_next_line.c GNL/get_next_line_utils.c map_validation.c move_spody.c 
OBJ := $(SRC:.c=.o)
CC	:= gcc
CFLAGS := -Wall -Wextra -Werror
all: $(NAME)

$(NAME):  $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME) 
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all