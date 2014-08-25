TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

CONFIG += c++11

SOURCES += main.cpp \
    ChessPiece.cpp \
    ComplexMovement.cpp \
    Board.cpp \
    Bishop.cpp \
    GameEngine.cpp \
    King.cpp \
    Knight.cpp \
    Movement.cpp \
    Pawn.cpp \
    PiecesManipulator.cpp \
    Player.cpp \
    Position.cpp \
    PositionResolver.cpp \
    Queen.cpp \
    Rook.cpp \
    SimpleMovement.cpp

HEADERS += \
    ChessPiece.h \
    Knight.h \
    ComplexMovement.h \
    Board.h \
    Bishop.h \
    GameEngine.h \
    King.h \
    Knight.h \
    Movement.h \
    Pawn.h \
    PiecesManipulator.h \
    Player.h \
    Position.h \
    Queen.h \
    Rook.h \
    SimpleMovement.h \
    PositionResolver.h

