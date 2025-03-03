.PHONY : all clean fclean re bonus norminette

NAME = so_long

# ╭━━━━━━━━━━━━══════════╕出 ❖ BASICS VARIABLES ❖ 力╒═══════════━━━━━━━━━━━━╮ #

CC				:=	cc

CFLAGS			:= -Wall	-Wextra	-Werror

RM				:=	rm	-rf

SHOW_MSG_CLEAN	=	true

# ╰━━━━━━━━━━━━━━━━════════════════╛出 ❖ 力╘════════════════━━━━━━━━━━━━━━━━╯ #

# ╭━━━━━━━━━━━━══════════╕出 ❖ FILE TREE ❖ 力╒═══════════━━━━━━━━━━━━╮ #

# directories
D_SRC	=	src/
D_INC	=	inc/
D_LIB	=	librairies/
D_OBJ	=	.obj/

# file lists
LST_SRC		=	main.c				\
				map.c				\
				input_handlers.c	\
				parsing.c			\
				printers.c			\
				utils.c				\
				bfs.c				\

LST_INC		=	mlx.h				\
				mlx_int.h			\
				$(NAME).h			\


# files paths
SRC		=	$(addprefix $(D_SRC), $(LST_SRC))
INC		=	$(addprefix $(D_INC), $(LST_INC))

OBJ		=	$(subst  $(D_SRC), $(D_OBJ), $(SRC:.c=.o))

# ╭━━━━━━━━━━━━══════════╕出 ❖ RULES ❖ 力╒═══════════━━━━━━━━━━━━╮ #

all : $(NAME)

$(NAME)		:	$(OBJ)
	@$(CC) $(OBJ) -I$(D_INC) -L$(D_LIB) -lmlx -lXext -lX11 -lm -lftprintf -o $@
	@echo "\e[0;32mProgramme créé avec succès ! 🧬\e[0m"

$(D_OBJ)%.o	:	$(D_SRC)%.c
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
	norminette $(D_INC) $(D_SRC)
