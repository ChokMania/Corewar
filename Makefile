SHELL = /bin/zsh

# Executable name, can be change
NAME = asm
NAME2 = deasm

#Visual
VISUAL				=	yes
VISUALNUM			=	2

#Compilation Modes. Default= -Wall -Wextra -Werror
SANITIZE			=	no
NOERROR				=	no
NOFLAG				=	no

ifeq ($(SANITIZE),yes)
	CC				=	gcc -Wall -Wextra -Werror -fsanitize=address \
						-Wall -Wextra -Werror
else ifeq ($(NOERROR),yes)
	CC				=	gcc -Wall -Wextra
else
	CC				=	gcc -Wall -Wextra -Werror
endif

SRCS_ASM_NAME		=	asm.c							\
						error.c							\
						ft_gnl_parsing.c				\
						ft_calcule_val.c				\
						file.c							\
						header.c						\
						ft_get_line.c					\
						list.c							\
						utiles.c						\
						ft_struct.c						\
						ft_one_arg.c 					\
						ft_two_args.c 					\
						ft_three_args.c 				\
						ft_instru.c						\
						ft_set_args_to_tabs.c			\
						ft_dispatch.c					\
						ft_output.c						\
						ft_index_label.c				\
						ft_is.c							\
						ft_is_labels.c					\
						ft_is_direct.c					\

SRCS_ASM_PATH		=	./assembleur/srcs/

INCLUDES_ASM_PATH	=	./assembleur/includes/

OBJS_ASM_PATH 		=	./assembleur/objs/

LIBFT				=	./Libft/
LIBFTA				=	libft.a
LIBFTINCLUDES		=	./Libft/includes/

INCLUDES_ASM_NAME	=	asm.h				\
						op.h				\

INCLUDES_ASM		=	$(addprefix $(INCLUDES_ASM_PATH), $(INCLUDES_ASM_NAME))

SRCS_ASM			=	$(addprefix $(SRCS_ASM_PATH), $(SRCS_ASM_NAME))

OBJS_ASM			=	$(patsubst $(SRCS_ASM_PATH)%.c, \
						$(OBJS_ASM_PATH)%.o, $(SRCS_ASM))

.PHONY				:	all clean fclean re

# Text format
_DEF = $'\033[0m
_END = $'\033[0m
_GRAS = $'\033[1m
_SOUL = $'\033[4m
_CLIG = $'\033[5m
_SURL = $'\033[7m

# Colors
_BLACK = $'\033[30m
_RED = $'\033[31m
_GREEN = $'\033[32m
_YELLOW = $'\033[33m
_BLUE = $'\033[34m
_PURPLE = $'\033[35m
_CYAN = $'\033[36m
_GREY = $'\033[37m

# Background
_IBLACK = $'\033[40m
_IRED = $'\033[41m
_IGREEN = $'\033[42m
_IYELLOW = $'\033[43m
_IBLUE = $'\033[44m
_IPURPLE = $'\033[45m
_ICYAN = $'\033[46m
_IGREY = $'\033[47m

all: $(NAME)

$(LIBFT)/$(LIBFTA):
	@make -C $(LIBFT) -j 100

$(NAME): $(LIBFT)/$(LIBFTA) $(OBJS_ASM)
	@echo "$(_WHITE)====================================================$(_END)"
	@echo "$(_YELLOW)		COMPILING : $(NAME)$(_END)"
	@echo "$(_WHITE)====================================================$(_END)"
	@$(CC) -o $(NAME) $(OBJS_ASM) $(LIBFT)/$(LIBFTA)
	@echo "\n$(_WHITE)$(_BOLD)$@\t$(_END)$(_GREEN)[OK]\n$(_END)"
ifeq ($(SANITIZE),yes)
	@echo "Génération en mode sanitize"
else ifeq ($(NOERROR),yes)
	@echo "Génération en mode noerror"
else ifeq ($(NOFLAG),yes)
	@echo "Génération en mode noflag"
else
	@echo "Génération en mode release"
endif

clean:
	@rm -rf $(OBJS_ASM_PATH) 2> /dev/null || true
ifeq ($(shell [[ $(VISUAL) == yes && $(VISUALNUM) == 2 ]] && echo true ), true)
	@echo "$(_YELLOW)Remove :\t$(_RED)" $(LDFLAGS)$(OBJS_ASM_PATH)"$(_END)"
endif
	@make -C $(LIBFT) clean

fclean: clean
	@rm -f $(NAME)
	@rm -f libft.a
	@rm -f ./libft/libft.a
ifeq ($(shell [[ $(VISUAL) == yes && $(VISUALNUM) == 2 ]] && echo true ), true)
	@echo "$(_YELLOW)Remove :\t$(_RED)" $(LDFLAGS)$(NAME)
	@echo "$(_YELLOW)Remove :\t$(_RED)" libft.a"$(_END)"
	@echo "$(_YELLOW)Remove :\t$(_RED)" ./libft/libft.a"$(_END)"
endif

re:
	@make fclean
	@make all

$(OBJS_ASM_PATH)%.o: $(SRCS_ASM_PATH)%.c $(INCLUDES_ASM)
	@mkdir -p $(OBJS_ASM_PATH)
	@$(CC) -I $(LIBFTINCLUDES) \
		-I $(INCLUDES_ASM_PATH) -c $< -o $@
	@echo "$(_END)$(_GREEN)[OK]\t$(_UNDER)$(_YELLOW)	\
		COMPILE :$(_END)$(_BOLD)$(_WHITE)\t$<"
