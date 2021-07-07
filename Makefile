#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/20 22:37:03 by ciglesia          #+#    #+#              #
#    Updated: 2021/07/06 20:27:58 by ciglesia         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	libstring.a

INC			=	./include/
ROOTINC		=	../include/

INCLUDE		=	-I $(INC) -I $(ROOTINC)

#***************** SRC ********************#

DIRSRC		=	./src/
DIRC		=	$(DIRSRC)/c
DIRASM		=	$(DIRSRC)/asm

DIRCALL		=	$(DIRC)/allocate
DIRCALD		=	$(DIRC)/allocated

SRCCALD		=	ft_countchr.c ft_strchr.c ft_strcmpn.c ft_strequ.c ft_strlcat.c ft_strncmp.c ft_strnstr.c ft_strclr.c ft_striter.c ft_strncpy.c ft_strrchr.c ft_strcat.c ft_strdel.c ft_striteri.c ft_strncat.c ft_strnequ.c ft_strstr.c ft_memset.c ft_memdel.c ft_memcpy.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memmove.c ft_bzero.c
SRCCALL		=	ft_strmap.c ft_strndup.c ft_strrev.c ft_strsub.c ft_strjoin.c ft_strmapi.c ft_strnew.c ft_strsplit.c ft_strtrim.c ft_memalloc.c ft_memins.c strins.c ft_fstrjoin.c

SRCC		=	$(SRCCALL) $(SRCCALD)

SRCASM		=	ft_strlen.s ft_strcpy.s ft_strcmp.s ft_strdup.s

#***************** DEPS ******************#

DIROBJ		=	./depo/

CAUX		=	$(SRCC:%=$(DIROBJ)%)
ASMAUX		=	$(SRCASM:%=$(DIROBJ)%)
DEPS		=	$(ASMAUX:.s=.d) $(CAUX:.c=.d)
OBJS		=	$(ASMAUX:.s=.o) $(CAUX:.c=.o)

ifdef FLAGS
	ifeq ($(FLAGS), no)
CFLAGS		=
	endif
	ifeq ($(FLAGS), debug)
CFLAGS		=	-Wall -Wextra -Werror -ansi -pedantic -g
	endif
else
CFLAGS		=	-Wall -Wextra -Werror
endif

OS			=	$(shell uname)
ifeq ($(OS), Linux)
	NASM	=	/usr/bin/nasm -f elf64 -D__LINUX__=1
else
	NASM	=	/usr/bin/nasm -f macho64
endif

CC			=	/usr/bin/clang
RM			=	/bin/rm -f
ECHO		=	/bin/echo -e
BOLD		=	"\e[1m"
BLINK		=	 "\e[5m"
RED			=	 "\e[38;2;255;0;0m"
GREEN		=	 "\e[92m"
BLUE		=	 "\e[34m"
YELLOW		=	 "\e[33m"
E0M			=	 "\e[0m"

#************************ DEPS COMPILATION *************************

%.o		:		../$(DIRASM)/%.s
				@printf $(GREEN)"Generating libstring asm objects... %-33.33s\r" $@
				@$(NASM) $< -o $@

%.o		:		../$(DIRCALL)/%.c
				@printf $(GREEN)"Generating libstring c objects...   %-33.33s\r" $@
				@$(CC) $(CFLAGS) $(INCLUDE) -MMD -o $@ -c $<

%.o		:		../$(DIRCALD)/%.c
				@printf $(GREEN)"Generating libstring c objects...   %-33.33s\r" $@
				@$(CC) $(CFLAGS) $(INCLUDE) -MMD -o $@ -c $<

#************************ MAIN COMPILATION *************************

$(NAME)	:		$(OBJS)
				@ar rc $(NAME) $(OBJS)
				@ranlib $(NAME)
				@$(ECHO)
				@$(ECHO) $(BOLD)$(GREEN)'> libstring library compiled'$(E0M)

clean	:
				@($(RM) $(OBJS))
				@($(RM) $(DEPS))
				@$(ECHO) $(BOLD)$(RED)'> libstring directory    cleaned'$(E0M)

all		:		$(NAME)

fclean	:		clean
				@$(RM) $(NAME)
				@$(ECHO) $(BOLD)$(RED)'> libstring.a            removed'$(E0M)

re		:		fclean all

apt		:
				sudo apt install -y clang nasm

.PHONY	:		all clean fclean re apt

-include $(DEPS)
