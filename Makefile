NAME	= fdf
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

LIBFT	= lib/libft/
MLX		= lib/mlx/

LIBFT_A	= $(LIBFT)libft.a
MLX_A	= $(MLX)libmlx.a

SRCS	= main.c error.c draw.c fdf_utils.c init.c get_next_line.c \
		  get_next_line_utils.c read_file.c
OBJS	= $(SRCS:.c=.o)


all: $(NAME) $(LIBFT) $(MLX)

$(MLX):
	@make -C ./lib/mlx/

$(LIBFT):
	@make -C ./lib/libft/

$(NAME): $(OBJS)
	make -C ./lib/mlx/
	make -C ./lib/libft/
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -framework OpenGL -framework AppKit $(LIBFT_A) $(MLX_A)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	$(RM) $(OBJS)
	@make clean -C lib/libft
	@make clean -C lib/mlx

fclean: fclean
	$(RM) $(NAME) $(OBJS)
	@make fclean -C lib/libft
	@make clean -C lib/mlx