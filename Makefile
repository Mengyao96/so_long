NAME = solong
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
	  map.c \
	  map_utils.c \
	  window.c \
	  render.c \
	  images.c \
	  events.c

OBJS = $(SRCS:.c=.o)

LIBFT_PATH = libft
MLX_PATH = minilibx_linux
LDFLAGS = -L$(LIBFT_PATH) -lft \
          -L$(MLX_PATH) -lmlx -lX11 -lXext -lm -lz

all : $(NAME)


$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean :
	$(MAKE) clean -C $(LIBFT_PATH)
	rm -f $(OBJS)

fclean : clean
	$(MAKE) fclean -C $(LIBFT_PATH)
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
