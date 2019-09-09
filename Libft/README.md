# Lib C / ft_printf / Miniprintf
    by Mabouce and Judumay

| Is (8) | Conv (9) | Mem (9) | Print (14) | Str (38) | Int (3) | List (29) | BTree (8) |
|:-------|:---------|:--------|:-----------|:---------|:--------|:----------|:----------|
| [isalnum](srcs/libft/is/ft_isalnum.c) | [atoi](srcs/libft/conv/ft_atoi.c) | [bzero](srcs/libft/mem/ft_bzero.c) | [printtab_nb](srcs/libft/print/ft_printtab_nb.c) | [strcat](srcs/libft/str/ft_strcat.c) | [intlen](srcs/libft/int/ft_intlen.c) | [cr_elem](srcs/libft/ft_create_elem.c) | [b_app_infix](srcs/libft/btree/btree_apply_infix.c) |
| [isalpha](srcs/libft/is/ft_isalpha.c) | [atol](srcs/libft/conv/ft_atol.c) | [memalloc](srcs/libft/mem/ft_memalloc.c) | [printtab_str](srcs/libft/print/ft_printtab_str.c) | [strchr](srcs/libft/str/ft_strchr.c) | [longlen](srcs/libft/int/ft_longlen.c) | [cr_elem_int](srcs/libft/lst/ft_create_elem_int.c) | [b_app_prefix](srcs/libft/btree/btree_apply_prefix.c) |
| [isascii](srcs/libft/is/ft_isascii.c) | [dtoa](srcs/libft/conv/ft_dtoa.c) | [memccpy](srcs/libft/mem/ft_memccpy.c) | [putchar](srcs/libft/print/ft_putchar.c) | [strclen](srcs/libft/str/ft_strclen.c) | [pow](srcs/libft/int/ft_pow.c) | [list_p_back](srcs/libft/lst/ft_list_push_back.c) | [b_app_suffix](srcs/libft/btree/btree_apply_suffix.c) |
| [isblank](srcs/libft/is/ft_isblank.c) | [itoa](srcs/libft/conv/ft_itoa.c) | [memchr](srcs/libft/mem/ft_memchr.c) | [putchar_fd](srcs/libft/print/ft_putchar_fd.c) | [strclen](srcs/libft/str/ft_strclen.c) || [list_p_back_int](srcs/libft/lst/ft_list_push_back_int.c) | [b_cr_node](srcs/libft/btree/btree_create_node.c) |
| [iscntrl](srcs/libft/is/ft_iscntrl.c) | [lltoa](srcs/libft/conv/ft_lltoa.c) | [memcmp](srcs/libft/mem/ft_memcmp.c) | [putcharerr](srcs/libft/print/ft_putcharerr.c) | [strclr](srcs/libft/str/ft_strclr.c) || [list_p_front](srcs/libft/lst/ft_list_push_front.c) | [b_lvl_count](srcs/libft/btree/btree_lvl_count.c) |
| [isdigit](srcs/libft/is/ft_isdigit.c) | [lltoabase_+](srcs/libft/conv/ft_lltoabase_signed.c) | [memcpy](srcs/libft/mem/ft_memcpy.c) | [putendl](srcs/libft/print/ft_putendl.c) | [strcmp](srcs/libft/str/ft_strcmp.c) || [list_p_front_int](srcs/libft/lst/ft_list_push_front_int.c) | [b_insert_data](srcs/libft/btree/btree_insert_data.c) |
| [isgraph](srcs/libft/is/ft_isgraph.c) | [lltoabase](srcs/libft/conv/ft_lltoabase_signless.c) | [memdel](srcs/libft/mem/ft_memdel.c) | [putendl_fd](srcs/libft/print/ft_putendl_fd.c) | [strcpy](srcs/libft/str/ft_strcpy.c) || [list_size](srcs/libft/lst/ft_list_size.c) | [b_int_cmp](srcs/libft/btree/btree_int_cmp.c) |
| [isprint](srcs/libft/is/ft_isprint.c) | [lltoabase_u](srcs/libft/conv/ft_lltoabase_unsigned.c) | [memmove](srcs/libft/mem/ft_memmove.c) | [putendlerr](srcs/libft/print/ft_putendlerr.c) | [strdel](srcs/libft/str/ft_strdel.c) || [list_last](srcs/libft/lst/ft_list_last.c) | [b_print](srcs/libft/btree/btree_print.c) |
| | [ltoa](srcs/libft/conv/ft_ltoa.c) | [memset](srcs/libft/mem/ft_memset.c) | [putnbr](srcs/libft/print/ft_putnbr.c) | [strdup](srcs/libft/str/ft_strdup.c) || [list_rm_last](srcs/libft/lst/ft_list_remove_last.c) ||
| | | | [putnbr_fd](srcs/libft/print/ft_putnbr_fd.c) | [strdupd](srcs/libft/str/ft_strdupd.c) ||||
| | | | [putnbrerr](srcs/libft/print/ft_putnbrerr.c) | [strequ](srcs/libft/str/ft_strequ.c) ||||
| | | | [putstr](srcs/libft/print/ft_putstr.c) | [strfill](srcs/libft/str/ft_strfill.c) ||||
| | | | [putstr_fd](srcs/libft/print/ft_putstr_fd.c) | [striter](srcs/libft/str/ft_striter.c) || [list_clear](srcs/libft/lst/ft_list_clear.c) ||
| | | | [putstrerr](srcs/libft/print/ft_putstrerr.c) | [striteri](srcs/libft/str/ft_striteri.c) || [list_clear_data](srcs/libft/lst/ft_list_clear_data.c) ||
| | | | | [strjoin](srcs/libft/str/ft_strjoin.c) || [list_at](srcs/libft/lst/ft_list_at.c) |
| | | | | [strjoind](srcs/libft/str/ft_strjoind.c) || [list_reverse](srcs/libft/lst/ft_list_reverse.c) |
| | | | | [strdjoind](srcs/libft/str/ft_strdjoind.c) || [list_foreach](srcs/libft/lst/ft_list_foreach.c) |
| | | | | [strlcat](srcs/libft/str/ft_strlcat.c) || [list_print](srcs/libft/lst/ft_list_print.c) |
| | | | | [strlen](srcs/libft/str/ft_strlen.c) || [lstadd](srcs/libft/lst/ft_lstadd.c) |
| | | | | [strmap](srcs/libft/str/ft_strmap.c) || [lstdel](srcs/libft/lst/ft_lstdel.c) |
| | | | | [strmapi](srcs/libft/str/ft_strmapi.c) || [lstdelone](srcs/libft/lst/ft_lstdelone.c) |
| | | | | [strncat](srcs/libft/str/ft_strncat.c) || [lstiter](srcs/libft/lst/ft_lstiter.c) |
| | | | | [strncmp](srcs/libft/str/ft_strncmp.c) || [lstmap](srcs/libft/lst/ft_lstmap.c) |
| | | | | [strncpy](srcs/libft/str/ft_strncpy.c) || [lstnew](srcs/libft/lst/ft_lstnew.c) |
| | | | | [strnequ](srcs/libft/str/ft_strnequ.c) || [lstlen](srcs/libft/lst/ft_lstlen.c) |
| | | | | [strnew](srcs/libft/str/ft_strnew.c) || [lst_print_i](srcs/libft/lst/ft_list_print_int.c) |
| | | | | [strnstr](srcs/libft/str/ft_strnstr.c) || [lst_print_s](srcs/libft/lst/ft_list_print_str.c) |
| | | | | [strrchr](srcs/libft/str/ft_strrchr.c) || [lst_rm_last_i](srcs/libft/lst/ft_list_remove_last_int.c) |
| | | | | [strsplit](srcs/libft/str/ft_strsplit.c) || [lst_rm_last_d](srcs/libft/lst/ft_list_remove_middle_int.c) |
| | | | | [strstr](srcs/libft/str/ft_strstr.c) || [lst_rm_mid_i](srcs/libft/lst/ft_list_print_str.c) |
| | | | | [strsub](srcs/libft/str/ft_strsub.c) || [lst_rm_mid_d](srcs/libft/lst/ft_list_remove_middle_data.c) |
| | | | | [strsub_2](srcs/libft/str/ft_strsub_leakless.c) || [lst_rm_first_i](srcs/libft/lst/ft_list_remove_first_int.c) |
| | | | | [strtok](srcs/libft/str/ft_strtok.c) ([wiki](../../wiki/ft_strtok)) || [lst_rm_first_d](srcs/libft/lst/ft_list_remove_first_data.c) |
| | | | | [strtoupper_2](srcs/libft/str/ft_strtoupper_leakless.c) |||
| | | | | [strtrim](srcs/libft/str/ft_strtrim.c) |||
| | | | | [tolower](srcs/libft/str/ft_tolower.c) |||
| | | | | [toupper](srcs/libft/str/ft_toupper.c) |||
| | | | | [strrev_2](srcs/libft/str/ft_strrev_leakless.c) |||
| | | | | [stradd_2](srcs/libft/str/ft_stradd_leakless.c) ||||
