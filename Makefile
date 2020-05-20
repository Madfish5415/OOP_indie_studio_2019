##
## EPITECH PROJECT, 2019
## OOP_indie_studio_2019
## File description:
## Makefile
##

NAME				=		bomberman
TEST_NAME			=		tests/unit_tests
TEST_SH_NAME		=		tests/tests.sh

COV_DIR				=		obj
INCL_DIR			=		src
OBJ_DIR				=		obj
SRC_DIR				=		src
TEST_DIR			=		tests

AR					=		ar rcs
CC					=		g++
RM					=		rm -rf

MAIN_SRC			=		main.cpp

PROJ_SRC			=

TEST_SRC			=		ecs/TestsComponentArray.cpp			\
							ecs/TestsComponentManager.cpp		\
							ecs/TestsEntityManager.cpp			\
							ecs/TestsSystem.cpp					\
							ecs/TestsSystemManager.cpp			\
							ecs/TestsWorldManager.cpp			\

CFLAGS				+=		-I $(INCL_DIR) -std=c++17
CFLAGS				+=		-W -Wall -Wextra -Werror

LDLIBS				=		-lpthread -lrt

MAIN_OBJ			=		$(MAIN_SRC:%.cpp=$(OBJ_DIR)/%.o)

PROJ_OBJ			=		$(PROJ_SRC:%.cpp=$(OBJ_DIR)/%.o)

TEST_OBJ			=		$(TEST_SRC:%.cpp=$(OBJ_DIR)/%.o)

TEST_COV			=		$(PROJ_SRC:%.cpp=$(COV_DIR)/%.gcda)	\
							$(PROJ_SRC:%.cpp=$(COV_DIR)/%.gcno)	\
							$(TEST_SRC:%.cpp=$(COV_DIR)/%.gcda)	\
							$(TEST_SRC:%.cpp=$(COV_DIR)/%.gcno)	\

MAKEFLAGS			+=		--silent

NO_COLOR			=		\e[0;0m
GREEN_COLOR			=		\e[0;32m
RED_COLOR			=		\e[0;31m
GREEN_B_COLOR		=		\e[1;32m
RED_B_COLOR			=		\e[1;31m
YELLOW_B_COLOR		=		\e[1;33m

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.cpp
					mkdir -p $(@D)
					$(CC) $(CFLAGS) -c $< -o $@ \
					&& echo "$< $(GREEN_COLOR)successfully compiled$(NO_COLOR)" \
					|| { echo "$< $(RED_COLOR)couldn't be compiled$(NO_COLOR)"; exit 1; }

$(OBJ_DIR)/%.o:		$(TEST_DIR)/%.cpp
					mkdir -p $(@D)
					$(CC) $(CFLAGS) -c $< -o $@ \
					&& echo "$< $(GREEN_COLOR)successfully compiled$(NO_COLOR)" \
					|| { echo "$< $(RED_COLOR)couldn't be compiled$(NO_COLOR)"; exit 1; }

$(NAME):			$(MAIN_OBJ) $(PROJ_OBJ)
					$(CC) $(MAIN_OBJ) $(PROJ_OBJ) -o $(NAME) $(LDFLAGS) $(LDLIBS) \
					&& echo "$(GREEN_B_COLOR)$(NAME) successfully created$(NO_COLOR)" \
					|| { echo "$(RED_B_COLOR)$(NAME) couldn't be created$(NO_COLOR)"; exit 1; }

all:				$(NAME)

clean:
					$(RM) $(MAIN_OBJ) $(PROJ_OBJ)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

sweet:				all clean

debug:				CFLAGS += -g3 -DLOG_DEBUG
debug:				all

debug_hard:			CFLAGS += -g3 -DLOG_DEBUG -DLOG_HARDDEBUG
debug_hard:			all

debug_re:			CFLAGS += -g3 -DLOG_DEBUG
debug_re:			re

debug_hard_re:		CFLAGS += -g3 -DLOG_DEBUG -DLOG_HARDDEBUG
debug_hard_re:		re

debug_sweet:		CFLAGS += -g3 -DLOG_DEBUG
debug_sweet:		sweet

$(TEST_NAME):		CFLAGS += -fprofile-arcs -ftest-coverage
$(TEST_NAME):		LDLIBS += -lgcov -lcriterion
$(TEST_NAME):		$(PROJ_OBJ) $(TEST_OBJ)
					if [ -d $(TEST_DIR) ]; then \
						$(CC) $(PROJ_OBJ) $(TEST_OBJ) -o $(TEST_NAME) $(LDFLAGS) $(LDLIBS) \
						&& echo "$(GREEN_B_COLOR)$(TEST_NAME) successfully created$(NO_COLOR)" \
						|| { echo "$(RED_B_COLOR)$(TEST_NAME) couldn't be created$(NO_COLOR)"; exit 1; } \
					fi

tests_run:			$(TEST_NAME)
					if [ ! -d $(TEST_DIR) ] || [ ! -f $(TEST_NAME) ]; then \
						echo "$(YELLOW_B_COLOR)Unit tests not found$(NO_COLOR)"; \
					else \
						./$(TEST_NAME) \
						&& echo "$(GREEN_B_COLOR)Unit tests passed successfully$(NO_COLOR)" \
						|| { echo "$(RED_B_COLOR)Unit tests did not pass successfully$(NO_COLOR)"; exit 1; } \
					fi

tests_clean:		clean
					$(RM) $(TEST_OBJ)
					$(RM) $(TEST_COV)

tests_fclean:		tests_clean
					$(RM) $(TEST_NAME)

tests_re:			tests_fclean tests_run

tests_sweet:		tests_run tests_clean

tests_sh:			re
					if [ ! -d $(TEST_DIR) ] || [ ! -f $(TEST_SH_NAME) ]; then \
						echo "$(YELLOW_B_COLOR)Functional tests not found$(NO_COLOR)"; \
					else \
						sh $(TEST_SH_NAME) $(NAME) \
						&& echo "$(GREEN_B_COLOR)Functional tests passed successfully$(NO_COLOR)" \
						|| { echo "$(RED_B_COLOR)Functional tests did not pass successfully$(NO_COLOR)"; exit 1; } \
					fi

full:				all

full_clean:			clean tests_clean

full_fclean:		fclean tests_fclean

full_re:			full_fclean full

full_sweet:			full full_clean

.PHONY:				all clean fclean re sweet											\
					debug debug_hard debug_re debug_sweet								\
					tests_run tests_clean tests_fclean tests_re tests_sweet tests_sh	\
					full full_clean full_fclean full_re full_sweet						\