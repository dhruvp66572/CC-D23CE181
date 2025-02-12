%{
    #include<stdio.h>
%}

%%
CHARUSAT{printf("university");}
.{printf("%c",yytext[0]);}
%%

int main(){

    yylex();
    return 0;
}


int yywrap()
{
    return 1;
}