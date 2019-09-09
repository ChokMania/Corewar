SHELL = sh

# Executable name, can be change
NAME = libft.a

#Visual
VISUAL				=	yes
VISUALNUM			=	2

#Compilation Modes. Default= -Wall -Wextra -Werror
SANITIZE			=	no
NOERROR				=	no
NOFLAG				=	no

# Sources names
						#	LIBFT
SRCS_LIBFT_NAME		= 	is/ft_isalnum.c						\
						is/ft_isalpha.c						\
						is/ft_isascii.c						\
						is/ft_isblank.c						\
						is/ft_iscntrl.c						\
						is/ft_isdigit.c						\
						is/ft_isgraph.c						\
						is/ft_isprint.c						\
															\
						conv/ft_atoi.c 						\
						conv/ft_atol.c 						\
						conv/ft_dtoa.c 						\
						conv/ft_itoa.c 						\
						conv/ft_lltoa.c						\
						conv/ft_lltoabase_signed.c 			\
						conv/ft_lltoabase_signless.c 		\
						conv/ft_lltoabase_unsigned.c 		\
						conv/ft_ltoa.c						\
						conv/ft_atolli.c					\
						conv/ft_atoi_base.c 				\
						conv/ft_atolli_base.c 				\
						conv/ft_hexatoi.c					\
															\
						mem/ft_bzero.c						\
						mem/ft_memalloc.c					\
						mem/ft_memccpy.c					\
						mem/ft_memchr.c						\
						mem/ft_memcmp.c 					\
						mem/ft_memcpy.c 					\
						mem/ft_memdel.c 					\
						mem/ft_memmove.c					\
						mem/ft_memset.c 					\
															\
						print/ft_printtab_nb.c				\
						print/ft_printtab_str.c				\
															\
						print/ft_putchar.c					\
						print/ft_putchar_fd.c				\
						print/ft_putcharerr.c				\
						print/ft_putendl.c					\
						print/ft_putendl_fd.c				\
						print/ft_putendlerr.c 				\
						print/ft_putnbr.c 					\
						print/ft_putnbrll.c 				\
						print/ft_putnbr_fd.c				\
						print/ft_putnbrerr.c				\
						print/ft_putstr.c					\
						print/ft_putstr_fd.c				\
						print/ft_putstrerr.c				\
															\
						str/ft_strcat.c						\
						str/ft_strchr.c 					\
						str/ft_strclen.c 					\
						str/ft_strclr.c 					\
						str/ft_strcmp.c 					\
						str/ft_strcpy.c 					\
						str/ft_strdel.c 					\
						str/ft_strdup.c 					\
						str/ft_strdupd.c 					\
						str/ft_strequ.c 					\
						str/ft_strfill.c 					\
						str/ft_striter.c 					\
						str/ft_striteri.c 					\
						str/ft_strjoin.c 					\
						str/ft_strjoind.c 					\
						str/ft_strdjoind.c 					\
						str/ft_strlcat.c 					\
						str/ft_strlen.c 					\
						str/ft_strmap.c 					\
						str/ft_strmapi.c 					\
						str/ft_strncat.c 					\
						str/ft_strncmp.c 					\
						str/ft_strncpy.c 					\
						str/ft_strnequ.c 					\
						str/ft_strnew.c 					\
						str/ft_strnstr.c 					\
						str/ft_strrchr.c 					\
						str/ft_strsplit.c 					\
						str/ft_strstr.c 					\
						str/ft_strsub.c 					\
						str/ft_strsub_leakless.c 			\
						str/ft_strtok.c 					\
						str/ft_strtoupper_leakless.c 		\
						str/ft_strtrim.c 					\
						str/ft_tolower.c 					\
						str/ft_toupper.c 					\
						str/ft_strrev_leakless.c 			\
						str/ft_stradd_leakless.c 			\
						str/ft_strisnum.c					\
						str/ft_strtabdel.c					\
						str/ft_strdjoin.c					\
						str/ft_strfindc.c					\
						str/ft_strsplit_multi.c				\
						str/ft_is_sep.c						\
						str/ft_strremove_char.c				\
						str/ft_strdjoinc.c					\
															\
						int/ft_intlen.c 					\
						int/ft_longlen.c	 				\
						int/ft_longlonglen.c 				\
						int/ft_pow.c 						\
						int/ft_inttabdel.c					\
															\
						lst/ft_create_elem.c				\
						lst/ft_create_elem_int.c			\
						lst/ft_list_push_back.c				\
						lst/ft_list_push_back_int.c			\
						lst/ft_list_push_front.c			\
						lst/ft_list_push_front_int.c		\
						lst/ft_list_size.c					\
						lst/ft_list_last.c					\
						lst/ft_list_remove_last.c			\
						lst/ft_list_remove_first.c			\
						lst/ft_list_remove_middle.c			\
						lst/ft_list_push_params.c			\
						lst/ft_list_clear.c					\
						lst/ft_list_clear_data.c			\
						lst/ft_list_at.c					\
						lst/ft_list_reverse.c				\
						lst/ft_list_foreach.c				\
						lst/ft_list_print.c					\
						lst/ft_lstadd.c 					\
						lst/ft_lstdel.c						\
						lst/ft_lstdelone.c					\
						lst/ft_lstiter.c					\
						lst/ft_lstmap.c						\
						lst/ft_lstnew.c						\
						lst/ft_lstlen.c						\
															\
						btree/btree_apply_infix.c			\
						btree/btree_apply_prefix.c			\
						btree/btree_apply_suffix.c			\
						btree/btree_create_node.c			\
						btree/btree_lvl_count.c				\
						btree/btree_insert_data.c			\
						btree/btree_int_cmp.c				\
						btree/btree_print.c					\
						btree/btree_free.c					\
															\
						get_next_line.c 					\

						#	FT_PRINTF
SRCS_FT_PRINTF_NAME =	ft_printf.c							\
						ft_printf_c.c						\
						ft_printf_display.c					\
						ft_printf_f.c						\
						ft_printf_get_conv.c				\
						ft_printf_get_flags.c				\
						ft_printf_conv.c					\
						ft_printf_d.c						\
						ft_printf_get_modifier.c			\
						ft_printf_get_precision.c			\
						ft_printf_get_width.c				\
						ft_printf_no_conv.c					\
						ft_printf_o.c						\
						ft_printf_p.c 						\
						ft_printf_parsing.c 				\
						all_for_p.c 						\
						ft_dtoa_printf.c 					\
						ft_printf_f_suite.c 				\
						ft_printf_u.c 						\
						ft_printf_percent.c 				\
						ft_printf_s.c 						\
						ft_printf_x.c 

						#	MINIPRINTF	
SRCS_MNPF_NAME 		=	miniprintf.c						\
						ft_error_miniprintf.c				\
						ft_fill.c							\
						ft_csp.c							\
						ft_mod.c							\
						ft_diouxx.c							\
						ft_longlong.c						\
						ft_struct.c							\
						ft_width.c							\
						ft_accu.c				

SRCS_INCLUDE_LIBFT	=	libft.h								\
						get_next_line.h						\
						miniprintf.h						\
						ftprintf.h



# Sources, objects and includes path
SRCS_MNPF_PATH		= 	./srcs/miniprintf/
SRCS_LIBFT_PATH		= 	./srcs/libft/
SRCS_ft_printf_pointerATH	= 	./srcs/ft_printf/
OBJS_PATH			=	./objs/
OBJS_MNPF_PATH 		= 	./objs/miniprintf/
OBJS_LIBFT_PATH 	= 	./objs/libft/
OBJS_ft_printf_pointerATH = 	./objs/ft_printf/
INCLUDES_PATH 		= 	./includes/

# Sources and objects
INCLUDES  		=	$(addprefix $(INCLUDES_PATH), $(SRCS_INCLUDE_LIBFT))
SRCS_MNPF		=	$(addprefix $(SRCS_MNPF_PATH), $(SRCS_MNPF_NAME))
SRCS_LIBFT		=	$(addprefix $(SRCS_LIBFT_PATH), $(SRCS_LIBFT_NAME))
SRCS_FT_PRINTF	=	$(addprefix $(SRCS_ft_printf_pointerATH), $(SRCS_FT_PRINTF_NAME))
OBJS_MNPF		=	$(patsubst $(SRCS_MNPF_PATH)%.c, $(OBJS_MNPF_PATH)%.o, $(SRCS_MNPF))
OBJS_LIBFT		=	$(patsubst $(SRCS_LIBFT_PATH)%.c, $(OBJS_LIBFT_PATH)%.o, $(SRCS_LIBFT))
OBJS_FT_PRINTF	=	$(patsubst $(SRCS_ft_printf_pointerATH)%.c, $(OBJS_ft_printf_pointerATH)%.o, $(SRCS_FT_PRINTF))

# Compilation
ifeq ($(SANITIZE),yes)
	CC				=	gcc -Wall -Wextra -Werror -fsanitize=address \
						-Wall -Wextra -Werror
else ifeq ($(NOERROR),yes)
	CC				=	gcc -Wall -Wextra
else ifeq ($(NOFLAG),yes)
	CC				=	gcc
else
	CC				=	gcc -Wall -Wextra -Werror
endif

LDFLAGS = ./libft/

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

$(NAME): $(OBJS_LIBFT) $(OBJS_MNPF) $(OBJS_FT_PRINTF)
	@ar rc $(NAME) $(OBJS_LIBFT) $(OBJS_MNPF) $(OBJS_FT_PRINTF)
	@ranlib $(NAME)
	@echo "\n"
ifeq ($(SANITIZE),yes)
	@echo "LIBFT : Génération en mode sanitize"
else ifeq ($(NOERROR),yes)
	@echo "LIBFT : Génération en mode noerror"
else ifeq ($(NOFLAG),yes)
	@echo "LIBFT : Génération en mode noflag"
else
	@echo "LIBFT : Génération en mode release"
endif

ifeq ($(shell [[ $(VISUAL) == yes && $(VISUALNUM) == 2 ]] && echo true ), true)
	@echo "VISUAL VERSION 2"
endif

$(OBJS_MNPF_PATH)%.o: $(SRCS_MNPF_PATH)%.c $(INCLUDES)

ifeq ($(shell [[ $(VISUAL) == yes && $(VISUALNUM) == 2 ]] && echo true ), true)
	@echo "$(_END)$(_GREEN)[OK]\t$(_UNDER)$(_YELLOW)	\
	COMPILE :$(_END)$(_BOLD)$(_WHITE)\t$<"
endif

	@mkdir -p objs/miniprintf
	@$(CC) -I $(INCLUDES_PATH) -o $@ -c $<

$(OBJS_ft_printf_pointerATH)%.o: $(SRCS_ft_printf_pointerATH)%.c $(INCLUDES)

ifeq ($(shell [[ $(VISUAL) == yes && $(VISUALNUM) == 2 ]] && echo true ), true)
	@echo "$(_END)$(_GREEN)[OK]\t$(_UNDER)$(_YELLOW)	\
	COMPILE :$(_END)$(_BOLD)$(_WHITE)\t$<"
endif

	@mkdir -p objs/ft_printf
	@$(CC) -I $(INCLUDES_PATH) -o $@ -c $<

$(OBJS_LIBFT_PATH)%.o: $(SRCS_LIBFT_PATH)%.c $(INCLUDES)

ifeq ($(shell [[ $(VISUAL) == yes && $(VISUALNUM) == 2 ]] && echo true ), true)
	@echo "$(_END)$(_GREEN)[OK]\t$(_UNDER)$(_YELLOW)	\
	COMPILE :$(_END)$(_BOLD)$(_WHITE)\t$<"
endif

	@mkdir -p objs/libft/is objs/libft/conv objs/libft/str objs/libft/print
	@mkdir -p objs/libft/mem objs/libft/lst objs/libft/btree objs/libft/int
	@$(CC) -I $(INCLUDES_PATH) -o $@ -c $<

clean:
ifeq ($(shell [[ $(VISUAL) == yes && $(VISUALNUM) == 2 ]] && echo true ), true)
	@echo "$(_YELLOW)Remove :\t$(_RED)" $(LDFLAGS)objs/"$(_END)"
endif
	@rm -rf $(OBJS_PATH) 2> /dev/null || true

fclean: clean
	@rm -f $(NAME)
ifeq ($(shell [[ $(VISUAL) == yes && $(VISUALNUM) == 2 ]] && echo true ), true)
	@echo "$(_YELLOW)Remove :\t$(_RED)" $(LDFLAGS)$(NAME)" $(_END)"
endif

re:
	@make fclean
	@make all

norme:
	@echo "$(_GREEN)"
	@norminette $(SRCS_PATH)
	@norminette $(INCS_PATH)
	@echo "$(_DEF)"

.PHONY: all clean fclean re norme
