%{
	#include<stdio.h>
%}

%%
	NAME{printf("DHRUV");}
	.{prinf("%c",yytext[0]);}
%%
int main(){
	yylex();
	return 0;
}

int yywrap(){
	return 1;
}