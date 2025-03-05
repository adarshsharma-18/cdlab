%{
    #include "cal.tab.h"
%}
NUMBER    ([0-9])+
%%

[0-9]+   { yylval.num = atoi(yytext); return NUMBER; }
[\t ]+   { /* Ignore whitespace */ }
\n       { return '\n'; }
[-+*/()] { return yytext[0]; }
.        { printf("Unexpected character: %s\n", yytext); }
%%

int yywrap() {
    return 1;
}
