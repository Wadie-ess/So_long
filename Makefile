NAME :=  so_long
SRC :=  main.c set_map.c draw_map.c  get_next_line.c get_next_line_utils.c map_validation.c move_spody.c 
OBJ := main.o set_map.o draw_map.o  get_next_line.o get_next_line_utils.o map_validation.o move_spody.o  
MAP := maps/map.ber
CC:= gcc
all: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx  -c $<  -o $@ 

$(NAME):  $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME) -g -fsanitize=address 
clean:
	@rm -f $(OBJ)
fclean: clean
	@rm -f $(NAME)
re: fclean all

play: $(NAME)
	./$(NAME) $(MAP)