# **************************************************************************** #
#                                  VARIABLES                                   #
# **************************************************************************** #

NAME	=	push_swap
BONUS	=	checker

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

LIB_DIR	=	libft
LIBFT	=	$(LIB_DIR)/libft.a

SRC		=	init_stack.c utiles.c \
			oper_push.c oper_rotate.c oper_rrotate.c oper_swap.c
MAIN	= 	push_swap.c sort_greedy.c sort_small.c cost.c lis.c
OBJ		=	$(SRC:.c=.o) $(MAIN:.c=.o)

BONUS_MAIN		=	my_checker.c
BONUS_OBJ		=	$(BONUS_MAIN:.c=.o)
SHARED_OBJ		=	$(SRC:.c=.o)

# **************************************************************************** #
#                                  RULES                                       #
# **************************************************************************** #

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

$(BONUS): $(LIBFT) $(SHARED_OBJ) $(BONUS_OBJ)
	$(CC) $(CFLAGS) -o $(BONUS) $(SHARED_OBJ) $(BONUS_OBJ) $(LIBFT)

$(LIBFT):
	make -sC $(LIB_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	@make -sC $(LIB_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS)
	@make -sC $(LIB_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re
