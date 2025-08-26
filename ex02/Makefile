NAME			=	theJobOfYourDreams

CXX				=	c++
CXXFLAGS		=	-Wall -Wextra -Werror -std=c++98

SRCS			=	Account.cpp tests.cpp

OBJS_PATH		=	objs/
OBJS			=	$(SRCS:%.cpp=objs/%.o)

ISDEBUG = 0
ARGS ?= ""

ifeq ($(ISDEBUG), 1)
	CXX +=  -g -fsanitize=address,undefined
endif

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

$(OBJS_PATH)%.o:	%.cpp
	@mkdir -p $(OBJS_PATH)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
debug:
	make fclean
	$(MAKE) ISDEBUG=1 all

va:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(ARGS)

test:
	@./$(NAME) | sed -E 's/[0-9]{8}_[0-9]{6}/19920104_091532/g' | diff -u - 19920104_091532.log > /tmp/diff_result 2>&1 && echo "OK" || (echo "FAILED:" && cat /tmp/diff_result)
	

clean:
	rm -rf $(OBJS_PATH)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

init:
	bear -- make

.PHONY:	all clean fclean re debug va init test