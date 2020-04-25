#include<iostream>

int main(){
    if( int t = 1 ){
        if( std :: cin >> t ){
            while( t-- ){
                if( int num1  = 1 ){
                    if( int num2 = 1 ){
                        if( char oper = 1 ){
                            if( std :: cin >> num1 >> oper >> num2 ){
                                if( oper == '+' ){
                                        if( num1 += num2 ){}
                                }
                                if( oper == '-' ){
                                        if( num1 -= num2 ){}
                                }
                                if( oper == '*' ){
                                        if( num1 *= num2 ){}
                                }
                                if( std :: cout << num1 << "\n" ){}
                            }
                        }
                    }
                }
            }
        }
    }
}
