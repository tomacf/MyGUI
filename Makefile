NAME		=		my_gui

SRC			= 	core/main.cpp \
						component/Component.cpp \
						component/CIdentifier.cpp \
						component/CLabel.cpp \
						component/CGeometry.cpp \
						component/CColor.cpp \
						component/CChildren.cpp \
						component/CDraw.cpp \
						component/CDrawRectangle.cpp \
						component/CDrawGhost.cpp \
						component/CEvent.cpp \
						system/SRender.cpp \
						system/System.cpp \
						factory/Factory.cpp

OBJ			=		$(SRC:.cpp=.o)

CXXFLAGS	=	 -std=c++11 -I component/ -I entity/ -I factory/ -I system/ -I core/

all			:		$(NAME)

$(NAME)	:		$(OBJ)
						g++ $(OBJ) -o $(NAME) -L/usr/local/include/SDL2 -lSDL2

clean		:
						rm -f $(OBJ)

fclean	:		clean
						rm -f $(NAME)

re			:		fclean all