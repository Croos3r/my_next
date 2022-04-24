##
## EPITECH PROJECT, 2022
## Remastered 'My' Library
## File description:
## Makefile of the project
##

HEADERS_DIR					=	include
HEADERS						=	$(HEADERS_DIR)/my_next.h \
								$(HEADERS_DIR)/my_strings.h \
								$(HEADERS_DIR)/my_memory.h \
								$(HEADERS_DIR)/my_converters.h \
								$(HEADERS_DIR)/my_meters.h \
								$(HEADERS_DIR)/my_displayers.h
CONVERTERS_SRC				=	int_converters.c
DISPLAYERS_SRC				=	simple_displayers.c
MEMORY_SRC					=	memory_allocation.c \
								memory_manipulation.c
METERS_SRC					=	meters.c
STRINGS_SRC					=	string_comparison.c \
								string_search.c \
								$(addprefix manipulation/, \
								$(STRINGS_MANIPULATION_SRC))
STRINGS_MANIPULATION_SRC	=	string_concatenation.c \
								string_copy.c \
								string_duplication.c \
								string_split.c
BASE_SRC					=	$(addprefix converters/, $(CONVERTERS_SRC)) \
								$(addprefix displayers/, $(DISPLAYERS_SRC)) \
								$(addprefix memory/, $(MEMORY_SRC)) \
								$(addprefix meters/, $(METERS_SRC)) \
								$(addprefix strings/, $(STRINGS_SRC))
SRC							=	$(addprefix src/, $(BASE_SRC))
OBJ							=	$(SRC:.c=.o)
TST_DIR						=	tests
TST							=	$(TST_DIR)/test_converters.c \
								$(TST_DIR)/test_meters.c \
								$(TST_DIR)/test_strings.c
TST_OBJ						=	$(SRC:.c=.o) $(TST:.c=.o)
LIB_DIR						=	lib
LIBS						=
LIBS_ARCHIVES				=	$(LIBS:%=$(LIB_DIR)/lib%.a)

NAME						=	my_next
ARCHIVE						=	$(NAME:%=lib%.a)
TST_BINARY					= 	$(ARCHIVE).test

CPPFLAGS					+= 	-Wall -Wextra -iquote "include"
CFLAGS						+=
LDFLAGS						+= 	-L $(LIB_DIR)
LDLIBS						+= 	$(addprefix -l, $(LIBS))

HEADERS_DEST				=	$(HEADERS:%=../../%)
ARCHIVE_DEST				=	$(ARCHIVE:%=../%)

CC							=	gcc
AR							=	ar
CP 							=	cp

# Build targets:

all: $(ARCHIVE)

$(ARCHIVE): $(OBJ)
	$(AR) rc $(ARCHIVE) $(OBJ)

$(TST_BINARY): LIBS		+=	criterion gcov
$(TST_BINARY): CFLAGS 	+=	-ftest-coverage -fprofile-arcs
$(TST_BINARY): $(TST_OBJ) $(LIBS_ARCHIVES)
	$(CC) $(TST_OBJ) -o $(TST_BINARY) $(LDFLAGS) $(LDLIBS)

$(LIBS_ARCHIVES): $(LIB_DIR)
	$(MAKE) -C $(@:$(LIB_DIR)/lib%.a=$(LIB_DIR)/%)

re:	fclean all

# Tests and debug targets:

tests_run: $(TST_BINARY)
	./$(TST_BINARY)
	gcovr --exclude $(TST_DIR)
	gcovr --exclude $(TST_DIR) --branches

debug: $(DEBUG_ARCHIVE)
	valgrind ./$(DEBUG_ARCHIVE) $(ARGS)

# Cleaning targets:

clean:
	$(RM) $(OBJ) $(TST_OBJ)

fclean: clean
	$(RM) $(ARCHIVE) $(TST_BINARY)

aclean: fclean
	find . \( -name "#*#" -o -name "*~" -o -name "*.gcda" \
	-o -name "*.gcno" -o -name "vgcore.*" \) -delete

# Installation targets:

install: $(HEADERS_DEST) $(ARCHIVE_DEST)

$(HEADERS_DEST):
	$(CP) $(@:../../%=%) $@

$(ARCHIVE_DEST): $(ARCHIVE)
	$(CP) $(ARCHIVE) $@

# Makefile's safety:

.PHONY: all clean fclean aclean build_lib tests_run re debug
