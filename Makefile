NAME	=	ft
SRCS	=	test_iterator.cpp
INCLUDE	=	ft_iterator.hpp ft_iterator_cat.hpp ft_iterator_body.hpp
OBJS	=	$(SRCS:.cpp=.o)
CC		= 	c++
RM		=	rm -rf
FLAGS	=	-Wall -Wextra -Werror
STD	=	-std=c++98

all:		$(NAME)

${NAME} : ${OBJS} 
	${CC} ${OBJS} -o ${NAME} 

%.o : %.cpp ${INCLUDE}
	${CC} ${STD} ${FLAGS} -c $< -o $@

clean:
			$(RM) $(OBJS) 

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re