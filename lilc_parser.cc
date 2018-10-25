// A Bison parser, made by GNU Bison 3.0.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2013 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "lilc_parser.cc" // lalr1.cc:399

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "grammar.hh"

// User implementation prologue.

#line 51 "lilc_parser.cc" // lalr1.cc:407
// Unqualified %code blocks.
#line 33 "lilc.yy" // lalr1.cc:408

   #include <iostream>
   #include <cstdlib>
   #include <fstream>

   /* include for interoperation between scanner/parser */
   #include "lilc_compiler.hpp"

#undef yylex
#define yylex scanner.yylex

#line 65 "lilc_parser.cc" // lalr1.cc:408


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif



// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyempty = true)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 5 "lilc.yy" // lalr1.cc:474
namespace LILC {
#line 132 "lilc_parser.cc" // lalr1.cc:474

  /// Build a parser object.
  LilC_Parser::LilC_Parser (LilC_Scanner  &scanner_yyarg, LilC_Compiler &compiler_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg),
      compiler (compiler_yyarg)
  {}

  LilC_Parser::~LilC_Parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  LilC_Parser::syntax_error::syntax_error (const std::string& m)
    : std::runtime_error (m)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  LilC_Parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  LilC_Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
  {
    value = other.value;
  }


  template <typename Base>
  inline
  LilC_Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v)
    : Base (t)
    , value (v)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  LilC_Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t)
    : Base (t)
    , value ()
  {}

  template <typename Base>
  inline
  LilC_Parser::basic_symbol<Base>::~basic_symbol ()
  {
  }

  template <typename Base>
  inline
  void
  LilC_Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
  }

  // by_type.
  inline
  LilC_Parser::by_type::by_type ()
     : type (empty)
  {}

  inline
  LilC_Parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  LilC_Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  LilC_Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.type = empty;
  }

  inline
  int
  LilC_Parser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  LilC_Parser::by_state::by_state ()
    : state (empty)
  {}

  inline
  LilC_Parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  LilC_Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.state = empty;
  }

  inline
  LilC_Parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  LilC_Parser::symbol_number_type
  LilC_Parser::by_state::type_get () const
  {
    return state == empty ? 0 : yystos_[state];
  }

  inline
  LilC_Parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  LilC_Parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s)
  {
    value = that.value;
    // that is emptied.
    that.type = empty;
  }

  inline
  LilC_Parser::stack_symbol_type&
  LilC_Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    return *this;
  }


  template <typename Base>
  inline
  void
  LilC_Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  LilC_Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  LilC_Parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  LilC_Parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  LilC_Parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  LilC_Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  LilC_Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  LilC_Parser::debug_level_type
  LilC_Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  LilC_Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline LilC_Parser::state_type
  LilC_Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  LilC_Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  LilC_Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  LilC_Parser::parse ()
  {
    /// Whether yyla contains a lookahead.
    bool yyempty = true;

    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyempty)
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
        yyempty = false;
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Discard the token being shifted.
    yyempty = true;

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;


      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 162 "lilc.yy" // lalr1.cc:847
    {
          (yylhs.value.programNode) = new ProgramNode(new DeclListNode((yystack_[0].value.declList)));
          compiler.setASTRoot((yylhs.value.programNode));
          }
#line 532 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 3:
#line 168 "lilc.yy" // lalr1.cc:847
    {
           (yystack_[1].value.declList)->push_back((yystack_[0].value.declNode));
           (yylhs.value.declList) = (yystack_[1].value.declList);
           }
#line 541 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 4:
#line 173 "lilc.yy" // lalr1.cc:847
    {
           (yylhs.value.declList) = new std::list<DeclNode *>();
           }
#line 549 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 5:
#line 177 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.declNode) = (yystack_[0].value.declNode); }
#line 555 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 6:
#line 178 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.declNode) = (yystack_[0].value.structDeclNode); }
#line 561 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 7:
#line 179 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.declNode) = (yystack_[0].value.fnDecl); }
#line 567 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 8:
#line 183 "lilc.yy" // lalr1.cc:847
    {
          (yylhs.value.declNode) = new VarDeclNode((yystack_[2].value.typeNode), (yystack_[1].value.idNode), VarDeclNode::NOT_STRUCT);
          }
#line 575 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 9:
#line 187 "lilc.yy" // lalr1.cc:847
    {
          (yylhs.value.declNode) = new VarDeclNode(new StructNode((yystack_[2].value.idNode)), (yystack_[1].value.idNode), 0);
          }
#line 583 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 10:
#line 192 "lilc.yy" // lalr1.cc:847
    {
              (yylhs.value.declList) = new std::list<DeclNode *>();
              }
#line 591 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 11:
#line 196 "lilc.yy" // lalr1.cc:847
    {
              (yystack_[1].value.declList)->push_back((yystack_[0].value.declNode));
              (yylhs.value.declList) = (yystack_[1].value.declList);
              }
#line 600 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 12:
#line 202 "lilc.yy" // lalr1.cc:847
    {
         (yylhs.value.fnDecl) = new FnDeclNode((yystack_[3].value.typeNode), (yystack_[2].value.idNode), (yystack_[1].value.formals), (yystack_[0].value.fnBody));
         }
#line 608 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 13:
#line 207 "lilc.yy" // lalr1.cc:847
    {
             (yylhs.value.structDeclNode) = new StructDeclNode((yystack_[4].value.idNode), new DeclListNode((yystack_[2].value.declList))) ;
             }
#line 616 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 14:
#line 212 "lilc.yy" // lalr1.cc:847
    {
             (yystack_[1].value.declList)->push_back((yystack_[0].value.declNode));
             (yylhs.value.declList) = (yystack_[1].value.declList);
             }
#line 625 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 15:
#line 218 "lilc.yy" // lalr1.cc:847
    {
             std::list<DeclNode *> * list = new std::list<DeclNode *>;
             list->push_back((yystack_[0].value.declNode));
             (yylhs.value.declList) = list;
             }
#line 635 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 16:
#line 225 "lilc.yy" // lalr1.cc:847
    {
          (yylhs.value.formals) = new FormalsListNode(new std::list<FormalDeclNode *>()); 
          }
#line 643 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 17:
#line 230 "lilc.yy" // lalr1.cc:847
    {
          (yylhs.value.formals) = new FormalsListNode((yystack_[1].value.formalsList)); 
          }
#line 651 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 18:
#line 235 "lilc.yy" // lalr1.cc:847
    {
              std::list<FormalDeclNode *> * list = new std::list<FormalDeclNode *>();
              list->push_back((yystack_[0].value.formalDecl));
              (yylhs.value.formalsList) = list;
              }
#line 661 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 19:
#line 241 "lilc.yy" // lalr1.cc:847
    {
              (yystack_[0].value.formalsList)->push_front((yystack_[2].value.formalDecl));
              (yylhs.value.formalsList) = (yystack_[0].value.formalsList);
              }
#line 670 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 20:
#line 246 "lilc.yy" // lalr1.cc:847
    {
         (yylhs.value.fnBody) = new FnBodyNode(new DeclListNode((yystack_[2].value.declList)), new StmtListNode((yystack_[1].value.stmtList)));
       }
#line 678 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 21:
#line 251 "lilc.yy" // lalr1.cc:847
    {
             (yylhs.value.formalDecl) = new FormalDeclNode((yystack_[1].value.typeNode), (yystack_[0].value.idNode));
             }
#line 686 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 22:
#line 256 "lilc.yy" // lalr1.cc:847
    { 
           (yylhs.value.stmtList) = new std::list<StmtNode *>();}
#line 693 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 23:
#line 259 "lilc.yy" // lalr1.cc:847
    { 
           (yystack_[1].value.stmtList)->push_back((yystack_[0].value.stmtNode));
           (yylhs.value.stmtList) = (yystack_[1].value.stmtList);
           }
#line 702 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 24:
#line 264 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.stmtNode) = new AssignStmtNode((yystack_[1].value.assignNode)); }
#line 708 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 25:
#line 265 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.stmtNode) = new PostIncStmtNode((yystack_[2].value.exp)); }
#line 714 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 26:
#line 266 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.stmtNode) = new PostDecStmtNode((yystack_[2].value.exp)); }
#line 720 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 27:
#line 267 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.stmtNode) = new ReadStmtNode((yystack_[1].value.exp)); }
#line 726 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 28:
#line 268 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.stmtNode) = new WriteStmtNode((yystack_[1].value.exp)); }
#line 732 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 29:
#line 270 "lilc.yy" // lalr1.cc:847
    { 
        (yylhs.value.stmtNode) = new IfStmtNode((yystack_[5].value.exp), new DeclListNode((yystack_[2].value.declList)), new StmtListNode((yystack_[1].value.stmtList)));
        }
#line 740 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 30:
#line 274 "lilc.yy" // lalr1.cc:847
    { 
        (yylhs.value.stmtNode) = new IfElseStmtNode(
                (yystack_[10].value.exp), 
                new DeclListNode((yystack_[7].value.declList)), 
                new StmtListNode((yystack_[6].value.stmtList)), 
                new DeclListNode((yystack_[2].value.declList)), 
                new StmtListNode((yystack_[1].value.stmtList))); 
        }
#line 753 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 31:
#line 283 "lilc.yy" // lalr1.cc:847
    { 
        (yylhs.value.stmtNode) = new WhileStmtNode((yystack_[5].value.exp), new DeclListNode((yystack_[2].value.declList)), new StmtListNode((yystack_[1].value.stmtList))); 
        }
#line 761 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 32:
#line 286 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.stmtNode) = new ReturnStmtNode((yystack_[1].value.exp)); }
#line 767 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 33:
#line 287 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.stmtNode) = new ReturnStmtNode(nullptr); }
#line 773 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 34:
#line 288 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.stmtNode) = new CallStmtNode((yystack_[1].value.callNode)); }
#line 779 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 35:
#line 291 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.assignNode) = new AssignNode((yystack_[2].value.exp), (yystack_[0].value.exp)); }
#line 785 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 36:
#line 293 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.exp) = (yystack_[0].value.assignNode);}
#line 791 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 37:
#line 294 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.exp) = new PlusNode((yystack_[2].value.exp), (yystack_[0].value.exp)); }
#line 797 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 38:
#line 295 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.exp) = new MinusNode((yystack_[2].value.exp), (yystack_[0].value.exp)); }
#line 803 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 39:
#line 296 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.exp) = new TimesNode((yystack_[2].value.exp), (yystack_[0].value.exp)); }
#line 809 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 40:
#line 297 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.exp) = new DivideNode((yystack_[2].value.exp), (yystack_[0].value.exp)); }
#line 815 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 41:
#line 298 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.exp) = new NotNode((yystack_[0].value.exp)); }
#line 821 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 42:
#line 299 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.exp) = new AndNode((yystack_[2].value.exp), (yystack_[0].value.exp)); }
#line 827 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 43:
#line 300 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.exp) = new OrNode((yystack_[2].value.exp), (yystack_[0].value.exp)); }
#line 833 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 44:
#line 301 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.exp) = new EqualsNode((yystack_[2].value.exp), (yystack_[0].value.exp)); }
#line 839 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 45:
#line 302 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.exp) = new NotEqualsNode((yystack_[2].value.exp), (yystack_[0].value.exp)); }
#line 845 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 46:
#line 303 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.exp) = new LessNode((yystack_[2].value.exp), (yystack_[0].value.exp)); }
#line 851 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 47:
#line 304 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.exp) = new GreaterNode((yystack_[2].value.exp), (yystack_[0].value.exp)); }
#line 857 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 48:
#line 305 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.exp) = new LessEqNode((yystack_[2].value.exp), (yystack_[0].value.exp)); }
#line 863 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 49:
#line 306 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.exp) = new GreaterEqNode((yystack_[2].value.exp), (yystack_[0].value.exp)); }
#line 869 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 50:
#line 307 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.exp) = new UnaryMinusNode((yystack_[0].value.exp)); }
#line 875 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 51:
#line 308 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.exp) = (yystack_[0].value.exp); }
#line 881 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 52:
#line 310 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.exp) = (yystack_[0].value.exp); }
#line 887 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 53:
#line 311 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.exp) = new IntLitNode((yystack_[0].value.intTokenValue)); }
#line 893 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 54:
#line 312 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.exp) = new StrLitNode((yystack_[0].value.strTokenValue)); }
#line 899 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 55:
#line 313 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.exp) = new TrueNode(); }
#line 905 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 56:
#line 314 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.exp) = new FalseNode(); }
#line 911 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 57:
#line 315 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.exp) = (yystack_[1].value.exp); }
#line 917 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 58:
#line 316 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.exp) = (yystack_[0].value.callNode); }
#line 923 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 59:
#line 319 "lilc.yy" // lalr1.cc:847
    { 
        (yylhs.value.callNode) = new CallExpNode((yystack_[2].value.idNode), new ExpListNode(new std::list<ExpNode *>()));
        }
#line 931 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 60:
#line 323 "lilc.yy" // lalr1.cc:847
    { 
        (yylhs.value.callNode) = new CallExpNode((yystack_[3].value.idNode), new ExpListNode((yystack_[1].value.expList))); 
        }
#line 939 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 61:
#line 328 "lilc.yy" // lalr1.cc:847
    { 
        std::list<ExpNode *> * list = new std::list<ExpNode *>();
        list->push_back((yystack_[0].value.exp));
        (yylhs.value.expList) = list;
        }
#line 949 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 62:
#line 334 "lilc.yy" // lalr1.cc:847
    {
        (yystack_[2].value.expList)->push_back((yystack_[0].value.exp));
        (yylhs.value.expList) = (yystack_[2].value.expList);
        }
#line 958 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 63:
#line 339 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.typeNode) = new IntNode(); }
#line 964 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 64:
#line 340 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.typeNode) = new BoolNode(); }
#line 970 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 65:
#line 341 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.typeNode) = new VoidNode(); }
#line 976 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 66:
#line 344 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.exp) = (yystack_[0].value.idNode); }
#line 982 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 67:
#line 345 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.exp) = new DotAccessNode((yystack_[2].value.exp), (yystack_[0].value.idNode)); }
#line 988 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 68:
#line 347 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.idNode) = new IdNode((yystack_[0].value.idTokenValue)); }
#line 994 "lilc_parser.cc" // lalr1.cc:847
    break;


#line 998 "lilc_parser.cc" // lalr1.cc:847
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state,
                                           yyempty ? yyempty_ : yyla.type_get ()));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyempty)
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyempty = true;
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyempty)
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyempty)
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  LilC_Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what());
  }

  // Generate an error message.
  std::string
  LilC_Parser::yysyntax_error_ (state_type, symbol_number_type) const
  {
    return YY_("syntax error");
  }


  const signed char LilC_Parser::yypact_ninf_ = -77;

  const signed char LilC_Parser::yytable_ninf_ = -1;

  const short int
  LilC_Parser::yypact_[] =
  {
     -77,    25,   139,   -77,   -77,   -77,   -77,    21,   -77,   -77,
     -77,   -77,    21,   -77,    -2,   -19,   160,    30,    81,   -77,
      37,    21,   -77,   100,    21,   -77,   -77,    45,    49,    21,
     -77,   -77,    21,    57,   -77,    71,   -77,    78,   -77,   160,
     -77,   -77,   -77,   266,    43,    70,    77,    96,     2,   -77,
     -77,    95,   103,    33,   112,    21,    47,    47,    47,   -77,
     -77,   -77,   -77,    47,   -77,   106,    47,   -77,   161,   -77,
     -77,   -12,   -77,   -77,    21,   123,   124,    47,    94,     5,
     -77,   181,    99,   120,   141,   -77,   129,   -77,   -77,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,   -77,   -77,   -77,   194,   -77,   194,    10,   -77,   -77,
     130,   148,   -77,    75,    75,   -77,   -77,   220,   207,   233,
     233,   233,   233,   233,   233,   -77,    47,   -77,   -77,   194,
     160,   160,   273,   280,   155,   -77,   151,   -77,   160,   287,
     -77
  };

  const unsigned char
  LilC_Parser::yydefact_[] =
  {
       4,     0,     2,     1,    64,    63,    65,     0,     3,     5,
       7,     6,     0,    68,     0,     0,     0,     0,     0,     8,
       0,     0,    15,     0,     0,     9,    16,     0,    18,     0,
      10,    12,     0,     0,    14,     0,    17,     0,    21,    22,
      13,    19,    11,     0,     0,     0,     0,     0,     0,    20,
      23,     0,     0,     0,    66,     0,     0,     0,     0,    55,
      56,    53,    54,     0,    33,     0,     0,    36,     0,    51,
      58,    52,    24,    34,     0,     0,     0,     0,     0,     0,
      66,     0,     0,     0,     0,    50,    52,    41,    32,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    67,    25,    26,    35,    59,    61,     0,    27,    28,
       0,     0,    57,    37,    38,    39,    40,    42,    43,    44,
      45,    46,    47,    48,    49,    60,     0,    10,    10,    62,
      22,    22,     0,     0,    29,    31,     0,    10,    22,     0,
      30
  };

  const short int
  LilC_Parser::yypgoto_[] =
  {
     -77,   -77,   -77,   -77,     7,   -76,   -77,   -77,   -77,   -77,
     149,   -77,   -77,   -58,   -77,   -41,   -50,   111,   -39,   -77,
      -1,   -43,    46
  };

  const signed char
  LilC_Parser::yydefgoto_[] =
  {
      -1,     1,     2,     8,    42,    39,    10,    11,    23,    20,
      27,    31,    28,    43,    50,    67,    68,    69,    70,   107,
      24,    71,    54
  };

  const short int
  LilC_Parser::yytable_[] =
  {
      53,    12,    51,    18,    52,    19,    81,    82,    83,     9,
      59,    60,    79,    84,    74,    13,    87,    29,    16,    13,
      61,    62,    86,    22,    63,     3,    64,   104,   106,   108,
      34,    74,    77,   125,    65,   126,    29,    66,    13,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   130,   131,    14,    25,    59,    60,    30,    15,    74,
      17,   138,    75,    76,    13,    61,    62,    32,    36,    63,
      35,    55,   132,   133,    37,    38,   129,    77,    17,    65,
     139,    40,    66,     4,     5,     6,     4,     5,     6,    53,
      53,    51,    51,    52,    52,    19,    53,    56,    51,    57,
      52,    80,    59,    60,    26,     4,     5,     6,    91,    92,
      21,    13,    61,    62,    59,    60,    63,   105,    58,    72,
     101,    33,   110,    13,    61,    62,    65,    73,    63,    66,
      89,    90,    91,    92,    78,    93,    94,    95,    96,    97,
      98,    99,   100,   111,     4,     5,     6,   102,   103,     7,
     127,    89,    90,    91,    92,    74,    93,    94,    95,    96,
      97,    98,    99,   100,   112,     4,     5,     6,   128,   136,
      21,   137,    89,    90,    91,    92,    85,    93,    94,    95,
      96,    97,    98,    99,   100,    88,    41,     0,     0,     0,
       0,     0,    89,    90,    91,    92,     0,    93,    94,    95,
      96,    97,    98,    99,   100,   109,     0,     0,     0,     0,
       0,     0,    89,    90,    91,    92,     0,    93,    94,    95,
      96,    97,    98,    99,   100,    89,    90,    91,    92,     0,
      93,    94,    95,    96,    97,    98,    99,   100,    89,    90,
      91,    92,     0,    93,     0,    95,    96,    97,    98,    99,
     100,    89,    90,    91,    92,     0,     0,     0,    95,    96,
      97,    98,    99,   100,    89,    90,    91,    92,     0,     0,
       0,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
       0,    47,    48,    13,    44,    45,    46,    49,    47,    48,
      13,    44,    45,    46,   134,    47,    48,    13,    44,    45,
      46,   135,    47,    48,    13,     0,     0,     0,   140
  };

  const short int
  LilC_Parser::yycheck_[] =
  {
      43,     2,    43,    22,    43,    24,    56,    57,    58,     2,
       8,     9,    55,    63,    26,    17,    66,    18,    20,    17,
      18,    19,    65,    16,    22,     0,    24,    77,    78,    24,
      23,    26,    44,    23,    32,    25,    37,    35,    17,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   127,   128,     7,    24,     8,     9,    20,    12,    26,
      14,   137,    29,    30,    17,    18,    19,    21,    23,    22,
      24,    28,   130,   131,    25,    29,   126,    44,    32,    32,
     138,    24,    35,     5,     6,     7,     5,     6,     7,   132,
     133,   132,   133,   132,   133,    24,   139,    27,   139,    22,
     139,    55,     8,     9,    23,     5,     6,     7,    33,    34,
      10,    17,    18,    19,     8,     9,    22,    23,    22,    24,
      74,    21,    23,    17,    18,    19,    32,    24,    22,    35,
      31,    32,    33,    34,    22,    36,    37,    38,    39,    40,
      41,    42,    43,    23,     5,     6,     7,    24,    24,    10,
      20,    31,    32,    33,    34,    26,    36,    37,    38,    39,
      40,    41,    42,    43,    23,     5,     6,     7,    20,    14,
      10,    20,    31,    32,    33,    34,    65,    36,    37,    38,
      39,    40,    41,    42,    43,    24,    37,    -1,    -1,    -1,
      -1,    -1,    31,    32,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    31,    32,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    31,    32,
      33,    34,    -1,    36,    -1,    38,    39,    40,    41,    42,
      43,    31,    32,    33,    34,    -1,    -1,    -1,    38,    39,
      40,    41,    42,    43,    31,    32,    33,    34,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    11,    12,    13,
      -1,    15,    16,    17,    11,    12,    13,    21,    15,    16,
      17,    11,    12,    13,    21,    15,    16,    17,    11,    12,
      13,    21,    15,    16,    17,    -1,    -1,    -1,    21
  };

  const unsigned char
  LilC_Parser::yystos_[] =
  {
       0,    46,    47,     0,     5,     6,     7,    10,    48,    49,
      51,    52,    65,    17,    67,    67,    20,    67,    22,    24,
      54,    10,    49,    53,    65,    24,    23,    55,    57,    65,
      20,    56,    67,    21,    49,    67,    23,    25,    67,    50,
      24,    55,    49,    58,    11,    12,    13,    15,    16,    21,
      59,    60,    63,    66,    67,    28,    27,    22,    22,     8,
       9,    18,    19,    22,    24,    32,    35,    60,    61,    62,
      63,    66,    24,    24,    26,    29,    30,    44,    22,    66,
      67,    61,    61,    61,    61,    62,    66,    61,    24,    31,
      32,    33,    34,    36,    37,    38,    39,    40,    41,    42,
      43,    67,    24,    24,    61,    23,    61,    64,    24,    24,
      23,    23,    23,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    23,    25,    20,    20,    61,
      50,    50,    58,    58,    21,    21,    14,    20,    50,    58,
      21
  };

  const unsigned char
  LilC_Parser::yyr1_[] =
  {
       0,    45,    46,    47,    47,    48,    48,    48,    49,    49,
      50,    50,    51,    52,    53,    53,    54,    54,    55,    55,
      56,    57,    58,    58,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    60,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    62,    62,    62,    62,    62,    62,    62,    63,
      63,    64,    64,    65,    65,    65,    66,    66,    67
  };

  const unsigned char
  LilC_Parser::yyr2_[] =
  {
       0,     2,     1,     2,     0,     1,     1,     1,     3,     4,
       0,     2,     4,     6,     2,     1,     2,     3,     1,     3,
       4,     2,     0,     2,     2,     3,     3,     4,     4,     8,
      13,     8,     3,     2,     2,     3,     1,     3,     3,     3,
       3,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     1,     1,     1,     1,     1,     1,     3,     1,     3,
       4,     1,     3,     1,     1,     1,     1,     3,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const LilC_Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"newline\"", "CHAR", "BOOL",
  "INT", "VOID", "TRUE", "FALSE", "STRUCT", "INPUT", "OUTPUT", "IF",
  "ELSE", "WHILE", "RETURN", "ID", "INTLITERAL", "STRINGLITERAL", "LCURLY",
  "RCURLY", "LPAREN", "RPAREN", "SEMICOLON", "COMMA", "DOT", "WRITE",
  "READ", "PLUSPLUS", "MINUSMINUS", "PLUS", "MINUS", "TIMES", "DIVIDE",
  "NOT", "AND", "OR", "EQUALS", "NOTEQUALS", "LESS", "GREATER", "LESSEQ",
  "GREATEREQ", "ASSIGN", "$accept", "program", "declList", "decl",
  "varDecl", "varDeclList", "fnDecl", "structDecl", "structBody",
  "formals", "formalsList", "fnBody", "formalDecl", "stmtList", "stmt",
  "assignExp", "exp", "term", "fncall", "actualList", "type", "loc", "id", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  LilC_Parser::yyrline_[] =
  {
       0,   161,   161,   167,   173,   177,   178,   179,   182,   186,
     192,   195,   201,   206,   211,   217,   224,   229,   234,   240,
     246,   250,   256,   258,   264,   265,   266,   267,   268,   269,
     273,   282,   286,   287,   288,   291,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   310,   311,   312,   313,   314,   315,   316,   318,
     322,   327,   333,   339,   340,   341,   344,   345,   347
  };

  // Print the state stack on the debug stream.
  void
  LilC_Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  LilC_Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  LilC_Parser::token_number_type
  LilC_Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
    };
    const unsigned int user_token_number_max_ = 299;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

#line 5 "lilc.yy" // lalr1.cc:1155
} // LILC
#line 1450 "lilc_parser.cc" // lalr1.cc:1155
#line 349 "lilc.yy" // lalr1.cc:1156

void
LILC::LilC_Parser::error(const std::string &err_message )
{
   std::cerr << "Error: " << err_message << "\n";
}
