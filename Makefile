NAME		=		my_gui

SRC			= 	core/main.cpp \
						component/CChildren.cpp \
						component/CColor.cpp \
						component/CDraw.cpp \
						component/CDrawButton.cpp \
						component/CDrawCircle.cpp \
						component/CDrawGhost.cpp \
						component/CDrawLabel.cpp \
						component/CDrawLine.cpp \
						component/CDrawImage.cpp \
						component/CDrawRectangle.cpp \
						component/CDrawTriangle.cpp \
						component/CDrawTextBox.cpp \
						component/CEvent.cpp \
						component/CGeometry.cpp \
						component/CIdentifier.cpp \
						component/CLabel.cpp \
						component/Component.cpp \
						system/SRender.cpp \
						factory/Factory.cpp

OBJ			=		$(SRC:.cpp=.o)

CXXFLAGS	=	 -std=c++11 -I component/ -I entity/ -I factory/ -I system/ -I core/ -I/usr/local/Cellar/sfml/2.3/include/SFML/

all			:		$(NAME)

$(NAME)	:		$(OBJ)
						clang++ $(OBJ) -o $(NAME) -lsfml-graphics -lsfml-window -lsfml-system

clean		:
						rm -f $(OBJ)

fclean	:		clean
						rm -f $(NAME)

re			:		fclean all