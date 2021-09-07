#include "catch.hpp"
#include "DSString.h"

TEST_CASE("TESTING STRING CLASS", "[string]"){
    DSString s[10];
    s[0]=DSString("this is dsstring class");
    s[1]=DSString("a second string");
    s[2]=DSString("");
    s[3]=DSString("ALL CAPITALS");
    s[4]=DSString("");
    s[5]=DSString("all capitals");
    s[6]=DSString("ab");
    s[7]=DSString("\n");
    s[8]=DSString("cd");
    s[9]=DSString("this is dsstring class");

    SECTION("EQUALITY OPERATORS"){
        REQUIRE( s[0]==DSString("this is dsstring class") );
        REQUIRE( s[0]==s[9] );
        REQUIRE( s[4]=="" );
        REQUIRE( s[1]=="a second string" );
        REQUIRE( !(s[3]==s[5]) );
    }
    SECTION("ASSIGNMENT OPERATORS"){
        DSString str;
        str = "a second string";
        REQUIRE( str==s[1] );
        str = DSString("a second string");
        REQUIRE( str==s[1] );
        str = "";
        REQUIRE( str==s[2] );
        str = DSString("\n");
        REQUIRE(str==s[7]);
    }
    SECTION("ADDITION OPERATOR"){
        REQUIRE( DSString("abcd") ==s[6]+s[8]);
        REQUIRE(s[4]+s[4]=="");
        REQUIRE(s[4]+s[7]=="\n");
        REQUIRE(s[4]+s[7]+s[3]=="\nALL CAPITALS");
    }
    SECTION("GREATER THAN OPERATOR"){
        REQUIRE( s[0]>s[1]);
        REQUIRE(s[8]>s[6]);
        REQUIRE(s[8]>s[4]);
        REQUIRE(s[5]>s[3]);
    }
    SECTION("[] Operator"){
        REQUIRE( s[0][1]=='h');
        REQUIRE(s[1][3]=='e');
        REQUIRE(s[5][4]=='c');
    }
    SECTION("getLength Function"){
        REQUIRE( s[8].getLength()==2);
        REQUIRE(s[1].getLength()==15);
        REQUIRE(s[5].getLength()==12);
    }
    SECTION("Substring Function"){
        REQUIRE( s[0].substring(0,4)=="this");
        REQUIRE(s[0].substring(0,5)=="this ");
        REQUIRE(s[1].substring(1,4)==" sec");
    }
    SECTION("c_str Function"){
        REQUIRE( strcmp(s[0].c_str(),"this is dsstring class")==0);
        REQUIRE( strcmp(s[4].c_str(),"")==0);
        REQUIRE( strcmp(s[6].c_str(),"ab")==0);
    }
};
