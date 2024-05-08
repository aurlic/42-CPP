# **************************************************************************** #
#                                    PROGRAM                                   #
# **************************************************************************** #

NAME		:=	weapons

# **************************************************************************** #
#                                     UTILS                                    #
# **************************************************************************** #

CC			:=	c++
CFLAGS		:=	-Wall -Wextra -Werror -std=c++98
DEP_FLAGS	:=	-MMD -MP
RM			:=	rm -rf

# **************************************************************************** #
#                                  DIRECTORIES                                 #
# **************************************************************************** #

INCLD_DIR 	:=	includes
OBJS_DIR 	:=	objs

# **************************************************************************** #
#                                    COLORS                                    #
# **************************************************************************** #

NEW			:=	\r\033[K
DEFAULT		:=	\033[0m
BLACK		:=	\033[0;30m
WHITE		:=	\033[0;37m
RED			:=	\033[0;31m
NEON_RED	:=	\033[38;5;196m
GREEN		:=	\033[0;32m
U_GREEN		:=	\033[4;32m
NEON_GREEN	:=	\033[38;5;82m
YELLOW		:=	\033[0;33m
BLUE		:=	\033[0;34m
PURPLE		:=	\033[0;35m
CYAN		:=	\033[0;36m
BOLD		:=	\033[1m
ITALIC		:=	\033[3m

# **************************************************************************** #
#                                    SOURCES                                   #
# **************************************************************************** #

# INCLUDES #
INCLUDES	:=	Weapon.hpp \
				HumanA.hpp \
				HumanB.hpp \
INCLD_FLAG	:=	$(addprefix -I , $(INCLUDES))

# SOURCES #
SRC			:=	main.cpp \
				Weapon.cpp \
				HumanA.cpp \
				HumanB.cpp \

OBJS 		:=	$(patsubst %.cpp,$(OBJS_DIR)/%.o,$(SRC))
DEPS		:=	$(patsubst %.cpp,$(OBJS_DIR)/%.d,$(SRC))


# **************************************************************************** #
#                                     RULES                                    #
# **************************************************************************** #

all:	$(NAME)

$(NAME): $(OBJS)
	@printf "\r\033[K[weapons 🗡️] \033[4;32mBuilding weapons: $<\033[0m"
	@$(CC) $(OBJS) -o $(NAME)
	@printf "\r\033[K[weapons 🗡️] \033[0;32mDone!\033[0m\n"

-include $(DEPS)
$(OBJS_DIR)/%.o: ./%.cpp
	@printf "$(NEW)[weapons 🗡️] $(U_GREEN)Building:$(DEFAULT) $<"
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(DEP_FLAGS) $(CFLAGS) $(INCLD_FLAG) -c $< -o $@

clean:
	@printf "[weapons 🗡️] $(RED)Cleaning objects...$(DEFAULT)\n"
	@$(RM) $(OBJS_DIR)
	@printf "[weapons 🗡️] $(RED)Cleaned objects!$(DEFAULT)\n"

fclean: clean
	@printf "[weapons 🗡️] \033[0;31mDeleting weapons executable\033[0m\n"
	@$(RM) $(NAME)
	@printf "[weapons 🗡️] \033[1;32mDone\033[0m\n\n"

re: fclean all

.PHONY: all clean fclean re