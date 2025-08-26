NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(MLX_PATH)

SRCS = main.c \
	  map.c \
	  map_utils.c \
	  window.c \
	  render.c \
	  images.c \
	  events.c

OBJS = $(SRCS:.c=.o)

LIBFT_PATH = libft
MLX_PATH = minilibx-linux

all : $(NAME)

$(NAME): $(OBJS) $(LIBFT_PATH)/libft.a $(MLX_PATH)/libmlx.a
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx -lX11 -lXext -lm -o $(NAME)

debug: $(LIBFT_PATH)/libft.a $(MLX_PATH)/libmlx.a
	$(CC) -g -I$(MLX_PATH) $(SRCS) -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx -lX11 -lXext -lm

$(LIBFT_PATH)/libft.a:
	$(MAKE) -C $(LIBFT_PATH)

$(MLX_PATH)/libmlx.a:
	$(MAKE) -C $(MLX_PATH)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(MAKE) clean -C $(LIBFT_PATH)
	rm -f $(OBJS)

fclean : clean
	$(MAKE) fclean -C $(LIBFT_PATH)
	rm -f $(MLX_PATH)/libmlx.a
	rm -f $(MLX_PATH)/libmlx_Linux.a
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
