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
D_OBJ	=	.obj/

# file lists
LST_SRC		=	

LST_INC		=	mlx.h		\
				mlx_int.h	\


# files paths
SRC		=	$(addprefix $(D_SRC), $(LST_SRC))
INC		=	$(addprefix $(D_INC), $(LST_INC))

OBJ		=	$(subst  $(D_SRC), $(D_OBJ), $(SRC:.c=.o))

# ╭━━━━━━━━━━━━══════════╕出 ❖ RULES ❖ 力╒═══════════━━━━━━━━━━━━╮ #

all : $(NAME)

$(NAME)		:	$(OBJ)
	@$(CC) $(OBJ) -o $@
	@echo "\e[0;32mProgramme créé avec succès ! 🧬\e[0m"

$(D_OBJ)%.o	:	$(D_SRC)%.c $(D_INC)push_swap.h
	@mkdir -p $(D_OBJ)
	$(CC) $(CFLAGS) -I$(D_INC) -c $< -o $@

$(D_OBJ)%.o	:	$(D_UTL)%.c $(D_INC)push_swap.h
	@mkdir -p $(D_OBJ)
	$(CC) $(CFLAGS) -I$(D_INC) -c $< -o $@

$(D_OBJ)%.o	:	$(D_INST)%.c $(D_INC)push_swap.h
	@mkdir -p $(D_OBJ)
	$(CC) $(CFLAGS) -I$(D_INC) -c $< -o $@


$(D_OBJ)%.o: $(D_UT)%.c $(D_INC)push_swap.h
	@mkdir -p $(D_OBJ)
	$(CC) $(CFLAGS) -I$(D_INC) -c $< -o $@

clean:
ifeq ($(SHOW_MSG_CLEAN), true)
	@echo "\e[0;36mJ'ai enlevé tous les objets relatifs à push_swap 🧹\e[0m"
endif
	@$(RM) $(D_OBJ)

fclean:
	@$(MAKE) -s SHOW_MSG_CLEAN=false clean
	@$(RM) $(NAME) mandatory_tester bonus_tester .bonus
	@echo "\e[0;34mExecutable de push_swap nettoyé 🧼\e[0m"

re :
	$(MAKE) fclean
	$(MAKE) all
	@echo "\e[0;32mExecutable de push_swap recréé avec succès ! 🫡\e[0m"

norminette:
	norminette $(D_INC) $(D_SRC)
