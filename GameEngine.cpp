 #include "GameEngine.h"

using namespace Chess::GameLogic::GameComponents;

GameEngine::GameEngine( const int boardWidth,
                        const int boardHeight,
                        const int numberOfPlayers,
                        Colour startingColour )
    : m_board( new Board( boardWidth, boardHeight ) ),
      m_manipulator( m_board ),
      m_currentPlayerColour( startingColour ),
      m_quit( false )
{
    for ( int i = 0; i < numberOfPlayers; ++i )
    {
        Player player( m_board, startingColour );
        m_players.push_back( player );
        startingColour = nextColour( startingColour );
    }
}

GameEngine::~GameEngine()
{
    cout << "~GameEngine()\n";
    this->destroy();
}

void GameEngine::destroy()
{
    delete m_board;
}

void GameEngine::setBoard( Board* const board )
{
    m_board = board;
}

Board* GameEngine::board() const
{
    return m_board;
}

void GameEngine::addPlayer(Player& player )
{
    player.setBoard( m_board );
    m_players.push_back( player );
}

void GameEngine::nextPlayersTurn()
{
    m_currentPlayerColour = nextColour( m_currentPlayerColour );
}

void GameEngine::run()
{
    string instruction;
    while ( !m_quit )
    {
        cout << ">>> ";
        cin >> instruction;

        parseInstructions( instruction );
        cin.clear();
        cin.ignore();

        system( "clear" );

        m_board->display();
    }
}

void GameEngine::setPiecesForStandardGame( const Colour& colour )
{
    m_board->seWidth( 8 );
    m_board->setHeight( 8 );

    for ( int i = 0; i < 8; ++i )
    {
        ChessPiece* pawn = new Pawn( Position( i, VERTICAL_OFFSET - 1 - colour * 5 ), colour, m_board );
        m_board->addPiece( pawn );
    }

    ChessPiece* rook = new Rook( Position ( ROOK_OFFSET, VERTICAL_OFFSET - colour * VERTICAL_OFFSET ), colour, m_board );
    m_board->addPiece( rook );
    rook = new Rook( Position ( ROOK_OFFSET + 7, VERTICAL_OFFSET - colour * VERTICAL_OFFSET ), colour, m_board );
    m_board->addPiece( rook );

    ChessPiece* knight = new Knight( Position( KNIGHT_OFFSET, VERTICAL_OFFSET - colour * VERTICAL_OFFSET ), colour, m_board );
    m_board->addPiece( knight );
    knight = new Knight( Position( KNIGHT_OFFSET + 5, VERTICAL_OFFSET - colour * VERTICAL_OFFSET ), colour, m_board );
    m_board->addPiece( knight );

    ChessPiece* bishop = new Bishop( Position( BISHOP_OFFSET, VERTICAL_OFFSET - colour * VERTICAL_OFFSET ), colour, m_board );
    m_board->addPiece( bishop );
    bishop = new Bishop( Position( BISHOP_OFFSET + 3, VERTICAL_OFFSET - colour * VERTICAL_OFFSET ), colour, m_board );
    m_board->addPiece( bishop );

    ChessPiece* queen = new Queen( Position( QUEEN_OFFSET, VERTICAL_OFFSET - colour * VERTICAL_OFFSET ), colour, m_board );
    m_board->addPiece( queen );

    ChessPiece* king = new King( Position( KING_OFFSET, VERTICAL_OFFSET - colour * VERTICAL_OFFSET ), colour, m_board );
    m_board->addPiece( king );

    //m_board->initMovesMap();
}

void GameEngine::setStandardGame()
{
    setPiecesForStandardGame( white );
    setPiecesForStandardGame( black );
    m_board->display();
}

void GameEngine::parseInstructions( const string& instruction )
{
    const Instruction instr = instructionFromCode( tolower( instruction[ 0 ] ) );
    switch( instr )
    {
    case Quit:
        quit();
        break;
    case Move:
    {
        Position from = fromChessNotation ( instruction[ 2 ], instruction[ 3 ] );
        Position to = fromChessNotation( instruction[ 5 ], instruction[ 6 ] );

        Error errorHandler = m_manipulator.makeAMove( from, to, m_currentPlayerColour );

        switch( errorHandler )
        {
        case EmptyPosition:
            cout << "There's nothing there!\n";
            pressEnterToContinue();
            break;
        case WrongColour:
            cout << "Can't touch this!\n";
            pressEnterToContinue();
            break;
        case InvalidDestination:
            cout << "This can't go there!\n";
            pressEnterToContinue();
            break;
        case Success:
            this->nextPlayersTurn();
            break;
        default:
            cout << "This output is unseen!\n";
        }
        break;
    }
    case Undo:
        m_manipulator.undo();
        this->nextPlayersTurn();
        break;
    case Pass:
        this->nextPlayersTurn();
        break;
    case Castling:
        if ( instruction == "0-0-0"
             || instruction == "o-o-o"
             || instruction == "O-O-O" )
        {
           if ( !m_manipulator.castling( m_currentPlayerColour, Queenside ) )
           {
               cout << "Queenside castling isn't allowed under current circumstances!\n";
               pressEnterToContinue();
           }
        }
        else if ( instruction == "0-0"
                  || instruction == "o-o"
                  || instruction == "O-O" )
        {
            if ( !m_manipulator.castling( m_currentPlayerColour, Kingside ) )
            {
                cout << "Kingside castling isn't allowed under current circumstances!\n";
                pressEnterToContinue();
            }
        }
        else
        {
            cout << "\nUnrecognized Instruction!\n";
            pressEnterToContinue();
        }
        break;
    case FastForward:
        parseInstructions( "m,e2,e4" );
        parseInstructions( "p" );
        parseInstructions( "m,f1,e2" );
        parseInstructions( "p" );
        parseInstructions( "m,g1,h3" );
        parseInstructions( "p" );
        parseInstructions( "m,b1,a3" );
        parseInstructions( "p" );
        parseInstructions( "m,d2,d4" );
        parseInstructions( "p" );
        parseInstructions( "m,c1,e3" );
        parseInstructions( "p" );
        parseInstructions( "m,d1,d2" );
        parseInstructions( "p" );
        break;
    case Invalid:
        cout << "\nUnrecognized instruction!\n";
        break;
    default:
        cout << "woop-woop!\n";
        break;
    }
}

Instruction GameEngine::instructionFromCode( const char& ch )
{
    switch( ch )
    {
    case 'q':
        return Quit;
    case 'm':
        return Move;
    case 'u':
        return Undo;
    case 'p':
        return Pass;
    case '0':
    case 'o':
    case 'O':
        return Castling;
    case 'f':
        return FastForward;
    }
    return Invalid;
}

Position GameEngine::fromChessNotation( const char& x, const char& y )
{
    return Position( x - 'a', m_board->height() - ( y - '0' ) );
}

void GameEngine::quit()
{
    /*
     * exterminate( allPeople );
     * exterminate( blackRace );
     */

    m_quit |= 1; // hate as much as you want
}

void GameEngine::pressEnterToContinue()
{
    cout << "\nPress Enter to continue...\n";

    cin.ignore();
    cin.get();

}
