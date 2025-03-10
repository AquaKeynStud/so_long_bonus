.PHONY : all clean fclean re bonus norminette

NAME = so_long

# ╭━━━━━━━━━━━━══════════╕出 ❖ BASICS VARIABLES ❖ 力╒═══════════━━━━━━━━━━━━╮ #

CC				:=	cc

CFLAGS			:= -Wall -Wextra -Werror

RM				:=	rm	-rf

SHOW_MSG_CLEAN	=	true

# ╰━━━━━━━━━━━━━━━━════════════════╛出 ❖ 力╘════════════════━━━━━━━━━━━━━━━━╯ #

# ╭━━━━━━━━━━━━══════════╕出 ❖ FILE TREE ❖ 力╒═══════════━━━━━━━━━━━━╮ #

# directories
D_SRC	=	src/
D_INC	=	inc/
D_OBJ	=	.obj/
D_LIB	=	librairies/
D_PAR	=	$(D_SRC)parsing/
D_PRI	=	$(D_SRC)printers/
D_IMG	=	$(D_SRC)display_handler/

D_SRCS	= $(D_SRC) $(D_PRI) $(D_PAR) $(D_IMG)

# file lists
LST_SRC		=	map.c				\
				main.c				\
				utils.c				\
				input_handlers.c	

LST_PRI		=	err_printers.c		\
				map_printers.c		\
				print_on_window.c	

LST_PAR		=	bfs.c				\
				parsing.c		

LST_IMG		=	load_img.c			\
				display_img.c		

LST_INC		=	mlx.h				\
				mlx_int.h			\
				parsing.h			\
				$(NAME).h			\
				printers.h			\
				ft_printf.h			

LST_SRCS	=	$(LST_SRC) $(LST_PRI) $(LST_PAR) $(LST_IMG)

INC	=	$(addprefix $(D_INC), $(LST_INC))

OBJ = $(addprefix $(D_OBJ), $(patsubst %.c, %.o, $(LST_SRCS)))

# ╭━━━━━━━━━━━━══════════╕出 ❖ RULES ❖ 力╒═══════════━━━━━━━━━━━━╮ #

all : $(NAME)

$(NAME)		:	$(OBJ)
	@$(CC) $(OBJ) -I$(D_INC) -L$(D_LIB) -lmlx -lXext -lX11 -lm -lftprintf -o $@
	@echo "\e[0;32mProgramme créé avec succès ! 🧬\e[0m"

vpath %.c $(D_SRCS)

$(D_OBJ)%.o	:	%.c $(INC)
	@mkdir -p $(D_OBJ)
	$(CC) $(CFLAGS) -I$(D_INC) -c $< -o $@

clean:
ifeq ($(SHOW_MSG_CLEAN), true)
	@echo "\e[0;36mJ'ai enlevé tous les objets relatifs à $(NAME) 🧹\e[0m"
endif
	@$(RM) $(D_OBJ)

fclean:
	@$(MAKE) -s SHOW_MSG_CLEAN=false clean
	@$(RM) $(NAME) mandatory_tester bonus_tester .bonus
	@echo "\e[0;34mExecutable de $(NAME) nettoyé 🧼\e[0m"

re :
	$(MAKE) fclean
	$(MAKE) all
	@echo "\e[0;32mProgramme $(NAME) recréé avec succès ! 🫡\e[0m"

norminette:
	norminette $(D_SRCS) $(D_INC)ft_printf.h $(D_INC)parsing.h $(D_INC)printers.h $(D_INC)$(NAME).h

# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes