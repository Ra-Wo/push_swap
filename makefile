NAME 		= push_swap

NAME_BONUS	= checker

CC 			= gcc

CFLAGS 		= -Wall -Wextra -Werror

SRCS 		=	push_swap.c									\
				push_swap_utils.c							\
				sort_ab.c									\
				./utils/check_sort.c						\
				./utils/ft_atoi.c							\
				./utils/ft_isdigit.c						\
				./utils/ft_split.c							\
				./utils/get_length_and_check_params.c		\
				./utils/get_params.c						\
				./utils/pa.c								\
				./utils/pb.c								\
				./utils/push_swap_utils.c					\
				./utils/ra.c								\
				./utils/rb.c								\
				./utils/rr.c								\
				./utils/rra.c								\
				./utils/rrb.c								\
				./utils/rrr.c								\
				./utils/sa.c								\
				./utils/sb.c								\
				./utils/sorting.c							\
				./utils/sort3.c								\
				./utils/sort5.c

SRCS_BONUS	=	./bonus/checker.c							\
				./bonus/checker_utils.c						\
				./bonus/GetNextLine/get_next_line.c			\
				./bonus/GetNextLine/get_next_line_utils.c	\
				./bonus/instruction/pa.c					\
				./bonus/instruction/pb.c					\
				./bonus/instruction/ra.c					\
				./bonus/instruction/rb.c					\
				./bonus/instruction/rr.c					\
				./bonus/instruction/rra.c					\
				./bonus/instruction/rrb.c					\
				./bonus/instruction/rrr.c					\
				./bonus/instruction/sa.c					\
				./bonus/instruction/sb.c					\
				./bonus/instruction/ss.c					\
				./bonus/utils/ft_atoi.c						\
				./bonus/utils/ft_isdigit.c					\
				./bonus/utils/ft_split.c					\
				./bonus/utils/ft_strcmp.c					\
				./bonus/utils/ft_string_join.c				\
				./bonus/utils/ft_string_len.c				\
				./bonus/utils/get_length_and_check_params.c	\
				./bonus/utils/get_params.c

OBJS		= $(SRCS:.c=.o)

OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

all: $(NAME) $(NAME_BONUS)

$(NAME) : $(OBJS) 
	@$(CC) $(OBJS) -o $(NAME)

$(NAME_BONUS) : $(OBJS_BONUS)
	@$(CC) $(OBJS_BONUS) -o $(NAME_BONUS)
	@echo " \n\n\
		\n\
	 ██▓███   █    ██   ██████  ██░ ██   ██████  █     █░ ▄▄▄       ██▓███   \n \
	▓██░  ██▒ ██  ▓██▒▒██    ▒ ▓██░ ██▒▒██    ▒ ▓█░ █ ░█░▒████▄    ▓██░  ██▒ \n \
	▓██░ ██▓▒▓██  ▒██░░ ▓██▄   ▒██▀▀██░░ ▓██▄   ▒█░ █ ░█ ▒██  ▀█▄  ▓██░ ██▓▒ \n \
	▒██▄█▓▒ ▒▓▓█  ░██░  ▒   ██▒░▓█ ░██   ▒   ██▒░█░ █ ░█ ░██▄▄▄▄██ ▒██▄█▓▒ ▒ \n \
	▒██▒ ░  ░▒▒█████▓ ▒██████▒▒░▓█▒░██▓▒██████▒▒░░██▒██▓  ▓█   ▓██▒▒██▒ ░  ░ \n \
	▒▓▒░ ░  ░░▒▓▒ ▒ ▒ ▒ ▒▓▒ ▒ ░ ▒ ░░▒░▒▒ ▒▓▒ ▒ ░░ ▓░▒ ▒   ▒▒   ▓▒█░▒▓▒░ ░  ░ \n \
	░▒ ░     ░░▒░ ░ ░ ░ ░▒  ░ ░ ▒ ░▒░ ░░ ░▒  ░ ░  ▒ ░ ░    ▒   ▒▒ ░░▒ ░      \n \
	░░        ░░░ ░ ░ ░  ░  ░   ░  ░░ ░░  ░  ░    ░   ░    ░   ▒   ░░        \n \
		            ░           ░   ░  ░  ░      ░      ░          ░  ░      \n \
	\n\
	"

%.o : %.c push_swap.h
	@$(CC) $(CFLAGS) $< -c -o $@

clean: 
	@rm -f $(OBJS)
	@rm -f $(OBJS_BONUS)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)

re: fclean all
