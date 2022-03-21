# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brickard <brickard@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/19 23:27:33 by brickard          #+#    #+#              #
#    Updated: 2022/01/19 18:42:11 by brickard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minitalk

SERVER		=	server
CLIENT		= 	client

SRCS_S		=	./server.c
SRCS_C		=	./client.c 
SRCS_U		=	./utils.c

OBJS_S		=	$(SRCS_S:.c=.o)
OBJS_C 		= 	$(SRCS_C:.c=.o)
OBJS_U 		= 	$(SRCS_U:.c=.o)

HEAD 		= 	./minitalk.h

CC 			= 	gcc

FLAGS 		= 	-Wall -Wextra -Werror 

RM 			= 	rm -f

.PHONY: 		all clean fclean re

all:			$(NAME)

$(NAME):		$(SERVER) $(CLIENT)

$(SERVER):		$(OBJS_S) $(OBJS_U) $(HEAD) 
				$(CC) $(FLAGS) $(OBJS_S) $(OBJS_U) -o $(SERVER)

$(CLIENT):		$(OBJS_C) $(OBJS_U) $(HEAD) 
				$(CC) $(FLAGS) $(OBJS_C) $(OBJS_U) -o $(CLIENT)

%.o: %.c   $(HEAD)
	$(CC) $(FLAGS) -c $< -o $@ 

clean: 
			$(RM) $(OBJS_S) $(OBJS_C) $(OBJS_U)

fclean:	clean
			$(RM) $(CLIENT) $(SERVER)

re: fclean all