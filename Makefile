# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjupille <sjupille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 16:01:34 by sjupille          #+#    #+#              #
#    Updated: 2024/11/11 18:33:17 by sjupille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

CC = cc
RM = rm -f

SOURCES =	get_next_line_utils.c \
			get_next_line.c


OBJETS = $(SOURCES:.c=.o)

all : $(NAME)

$(NAME):  $(OBJETS)
		ar -rcs $(NAME) $(OBJETS)
		ranlib $(NAME)
	

clean : 
		$(RM) $(OBJETS)

fclean : clean
		$(RM) $(NAME)

re : fclean all

%.o: %.c 
		 $(CC) -Wall -Wextra -Werror -c $< -o $@

.PHONY: all clean fclean re