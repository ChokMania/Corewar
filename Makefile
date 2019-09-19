SHELL				=	/bin/zsh

# Executable name
NAME_VM				=	corewar
NAME_ASM			=	asm

# Compilation mode
WALL				=	yes
WEXTRA				=	yes
WERROR				=	yes
FSANITIZE			=	no
DEBUG				=	no
O2					=	yes

CC					:=	gcc
GEN					:=	"Corewar : Generation in mode"

ifeq ($(WALL), yes)
	CC				:=	$(CC) -Wall
	GEN				:=	$(GEN) all
endif

ifeq ($(WEXTRA), yes)
	CC				:=	$(CC) -Wextra
	GEN				:=	$(GEN) extra
endif

ifeq ($(WERROR), yes)
	CC				:=	$(CC) -Werror
	GEN				:=	$(GEN) error
endif

ifeq ($(FSANITIZE), yes)
	CC				:=	$(CC) -fsanitize=address
	GEN				:=	$(GEN) sanitize
endif

ifeq ($(DEBUG), yes)
	CC				:=	$(CC) -g
	GEN				:=	$(GEN) debug
endif

ifeq ($(O2),yes)
	CC				:=	$(CC) -O2
	GEN				:=	$(GEN) O2
endif

ifeq ($(GEN), "Corewar : Generation in mode")
	GEN				:=	$(GEN) no flags
endif

# Name
SRC_NAME_VM			=	main.c							\
						error.c							\
						utiles.c						\
						utiles2.c						\
						parsing.c						\
						arg.c							\
						list.c							\
						opcode.c						\
														\
						opcode/live.c					\
						opcode/ld.c						\
						opcode/st.c						\
						opcode/add.c					\
						opcode/sub.c					\
						opcode/and.c					\
						opcode/or.c						\
						opcode/xor.c					\
						opcode/zjmp.c					\
						opcode/ldi.c					\
						opcode/sti.c					\
						opcode/fork.c					\
						opcode/lld.c					\
						opcode/lldi.c					\
						opcode/lfork.c					\
						opcode/aff.c					\
														\
						visu/init_visu_arena.c			\
						visu/init_visu_hud.c			\
						visu/input.c					\
						visu/refresh_hud.c				\
						visu/refresh_live.c				\
						visu/init_desc.c				\

SRC_NAME_ASM		=	asm.c							\
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

INCLUDE_NAME_VM		=	corewar.h						\
						op.h

INCLUDE_NAME_ASM	=	asm.h							\
						op.h

LIBFT_NAME			=	libft.a

# Path
SRC_PATH_VM			=	./Vm/src/

OBJ_PATH_VM 		=	./Vm/obj/

INCLUDE_PATH_VM		=	./Vm/include/

SRC_PATH_ASM		=	./Assembleur/src/

OBJ_PATH_ASM		=	./Assembleur/obj/

INCLUDE_PATH_ASM	=	./Assembleur/include/

LIBFT_PATH			=	./Libft/

# Name + Path
SRC_VM				=	$(addprefix	$(SRC_PATH_VM),		$(SRC_NAME_VM))

OBJ_VM				=	$(patsubst	$(SRC_PATH_VM)%.c,	$(OBJ_PATH_VM)%.o,	$(SRC_VM))

INCLUDE_VM			=	$(addprefix	$(INCLUDE_PATH_VM),	$(INCLUDE_NAME_VM))

SRC_ASM				=	$(addprefix	$(SRC_PATH_ASM),	$(SRC_NAME_ASM))

OBJ_ASM				=	$(patsubst	$(SRC_PATH_ASM)%.c,	$(OBJ_PATH_ASM)%.o,	$(SRC_ASM))

INCLUDE_ASM			=	$(addprefix	$(INCLUDE_PATH_ASM),$(INCLUDE_NAME_ASM))

# Text format
_DEF				=	$'\033[0m
_END				=	$'\033[0m
_GRAS				=	$'\033[1m
_SOUL				=	$'\033[4m
_CLIG				=	$'\033[5m
_SURL				=	$'\033[7m

# Colors
_BLACK				=	$'\033[30m
_RED				=	$'\033[31m
_GREEN				=	$'\033[32m
_YELLOW				=	$'\033[33m
_BLUE				=	$'\033[34m
_PURPLE				=	$'\033[35m
_CYAN				=	$'\033[36m
_GREY				=	$'\033[37m

# Background
_IBLACK				=	$'\033[40m
_IRED				=	$'\033[41m
_IGREEN				=	$'\033[42m
_IYELLOW			=	$'\033[43m
_IBLUE				=	$'\033[44m
_IPURPLE			=	$'\033[45m
_ICYAN				=	$'\033[46m
_IGREY				=	$'\033[47m

all: $(NAME_VM) $(NAME_ASM)

$(LIBFT_PATH)$(LIBFT_NAME):
	@make -C $(LIBFT_PATH) -j
	@echo ""

$(NAME_VM): $(LIBFT_PATH)$(LIBFT_NAME) $(OBJ_VM)
	@echo "\n$(_WHITE)====================================================$(_END)"
	@echo "$(_YELLOW)		COMPILING $(NAME_VM)$(_END)"
	@echo "$(_WHITE)====================================================$(_END)"
	@$(CC) -o $(NAME_VM) $(OBJ_VM) $(LIBFT_PATH)/$(LIBFT_NAME) -lncurses
	@echo "\n$(_WHITE)$(_BOLD)$@\t$(_END)$(_GREEN)[OK]\n$(_END)"
	@echo $(GEN)

$(OBJ_PATH_VM)%.o: $(SRC_PATH_VM)%.c $(INCLUDE_VM)
	@mkdir -p $(OBJ_PATH_VM)
	@mkdir -p $(OBJ_PATH_VM)opcode/
	@mkdir -p $(OBJ_PATH_VM)visu/
	@$(CC) -I $(INCLUDE_PATH_VM) -I $(LIBFT_PATH)include/ \
		-I $(INCLUDE_PATH_VM) -c $< -o $@
	@echo "$(_END)$(_GREEN)[OK]\t$(_UNDER)$(_YELLOW)\t"	\
		"COMPILE :$(_END)$(_BOLD)$(_WHITE)\t$<"

$(NAME_ASM): $(LIBFT_PATH)$(LIBFT_NAME) $(OBJ_ASM)
	@echo "\n$(_WHITE)====================================================$(_END)"
	@echo "$(_YELLOW)		COMPILING $(NAME_ASM)$(_END)"
	@echo "$(_WHITE)====================================================$(_END)"
	@$(CC) -o $(NAME_ASM) $(OBJ_ASM) $(LIBFT_PATH)/$(LIBFT_NAME)
	@echo "\n$(_WHITE)$(_BOLD)$@\t$(_END)$(_GREEN)[OK]\n$(_END)"
	@echo $(GEN)

$(OBJ_PATH_ASM)%.o: $(SRC_PATH_ASM)%.c $(INCLUDE_ASM)
	@mkdir -p $(OBJ_PATH_ASM)
	@$(CC) -I $(INCLUDE_PATH_ASM) -I $(LIBFT_PATH)include/ \
		-I $(INCLUDE_PATH_ASM) -c $< -o $@
	@echo "$(_END)$(_GREEN)[OK]\t$(_UNDER)$(_YELLOW)\t"	\
		"COMPILE :$(_END)$(_BOLD)$(_WHITE)\t$<"

clean:
	@rm -rf $(OBJ_PATH_VM) 2> /dev/null || true
	@rm -rf $(OBJ_PATH_ASM) 2> /dev/null || true
	@echo "$(_YELLOW)Remove :\t$(_RED)" $(LDFLAGS)$(OBJ_PATH_VM)"$(_END)"
	@echo "$(_YELLOW)Remove :\t$(_RED)" $(LDFLAGS)$(OBJ_PATH_ASM)"$(_END)"
	@make -C $(LIBFT_PATH) clean

fclean: clean
	@rm -f $(NAME_VM)
	@rm -f $(NAME_ASM)
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)
	@echo "$(_YELLOW)Remove :\t$(_RED)" $(LDFLAGS)$(NAME_VM)
	@echo "$(_YELLOW)Remove :\t$(_RED)" $(LDFLAGS)$(NAME_ASM)
	@echo "$(_YELLOW)Remove :\t$(_RED)" $(LIBFT_PATH)$(LIBFT_NAME)"$(_END)"

re: fclean all

.PHONY: all clean fclean re
