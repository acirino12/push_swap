# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acirino <acirino@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/25 17:48:12 by acirino           #+#    #+#              #
#    Updated: 2026/05/28 18:16:55 by acirino          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	ft_isdigit.c ft_lstiter.c ft_memcpy.c ft_split.c ft_strlen.c ft_tolower.c \
		ft_atoi.c ft_isprint.c ft_lstlast.c ft_memmove.c ft_strchr.c ft_strmapi.c ft_toupper.c \
		ft_bzero.c ft_itoa.c ft_lstmap.c ft_memset.c ft_strdup.c ft_strncmp.c \
		ft_calloc.c ft_lstadd_back.c ft_lstnew.c ft_putchar_fd.c ft_striteri.c ft_strnstr.c \
		ft_isalnum.c ft_lstadd_front.c ft_lstsize.c ft_putendl_fd.c ft_strjoin.c ft_strrchr.c \
		ft_isalpha.c ft_lstclear.c ft_memchr.c ft_putnbr_fd.c ft_strlcat.c ft_strtrim.c \
		ft_isascii.c ft_lstdelone.c ft_memcmp.c ft_putstr_fd.c ft_strlcpy.c ft_substr.c \

OBJS = ft_isdigit.o ft_lstiter.o ft_memcpy.o ft_split.o ft_strlen.o ft_tolower.o \
		ft_atoi.o ft_isprint.o ft_lstlast.o ft_memmove.o ft_strchr.o ft_strmapi.o ft_toupper.o \
		ft_bzero.o ft_itoa.o ft_lstmap.o ft_memset.o ft_strdup.o ft_strncmp.o \
		ft_calloc.o ft_lstadd_back.o ft_lstnew.o ft_putchar_fd.o ft_striteri.o ft_strnstr.o \
		ft_isalnum.o ft_lstadd_front.o ft_lstsize.o ft_putendl_fd.o ft_strjoin.o ft_strrchr.o \
		ft_isalpha.o ft_lstclear.o ft_memchr.o ft_putnbr_fd.o ft_strlcat.o ft_strtrim.o \
		ft_isascii.o ft_lstdelone.o ft_memcmp.o ft_putstr_fd.o ft_strlcpy.o ft_substr.o \

FLAGS = -Wall -Wextra -Werror

CC = gcc

HEADER = libft.h

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all