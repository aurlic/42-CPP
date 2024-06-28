# **************************************************************************** #
#                                    PROGRAM                                   #
# **************************************************************************** #

NAME		:=	RPN

# **************************************************************************** #
#                                     UTILS                                    #
# **************************************************************************** #

CC			:=	c++
CFLAGS		:=	-g3 -Wall -Wextra -Werror -std=c++98
DEP_FLAGS	:=	-MMD -MP
RM			:=	rm -rf

# **************************************************************************** #
#                                  DIRECTORIES                                 #
# **************************************************************************** #

SRCS_DIR 	:=	src
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
INCLUDES	:=	$(strip $(INCLD_DIR))
INCLD_FLAG	:=	$(addprefix -I , $(INCLUDES))


# SOURCES #
SRC_FILES	:=	main.cpp \
				RPN.cpp
SRC			:=	$(addprefix $(SRCS_DIR)/, $(SRC_FILES))

# OBJECTS AND DEPENDENCIES #
OBJS        :=  $(patsubst $(SRCS_DIR)/%.cpp,$(OBJS_DIR)/%.o,$(SRC))
DEPS        :=  $(patsubst $(SRCS_DIR)/%.cpp,$(OBJS_DIR)/%.d,$(SRC))


# **************************************************************************** #
#                                     RULES                                    #
# **************************************************************************** #

all:	$(NAME)

$(NAME): $(OBJS)
	@printf "\r\033[K[RPN 🧮] \033[4;32mBuilding RPN: $<\033[0m"
	@$(CC) $(OBJS) -o $(NAME)
	@printf "\r\033[K[RPN 🧮] \033[0;32mDone!\033[0m\n"

-include $(DEPS)
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	@printf "$(NEW)[RPN 🧮] $(U_GREEN)Building:$(DEFAULT) $<"
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(DEP_FLAGS) $(CFLAGS) $(INCLD_FLAG) -c $< -o $@

clean:
	@printf "[RPN 🧮] $(RED)Cleaning objects...$(DEFAULT)\n"
	@$(RM) $(OBJS_DIR)
	@printf "[RPN 🧮] $(RED)Cleaned objects!$(DEFAULT)\n"

fclean: clean
	@printf "[RPN 🧮] \033[0;31mDeleting RPN executable\033[0m\n"
	@$(RM) $(NAME)
	@printf "[RPN 🧮] \033[1;32mDone\033[0m\n\n"

re: fclean all

.PHONY: all clean fclean re