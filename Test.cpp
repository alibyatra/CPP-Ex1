#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;

TEST_CASE("Test replacement of p and b")
{
    string text = "xxx happy yyy";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));
}

TEST_CASE("Test replacement of lower-case and upper-case")
{
    string text = "Happi xxx yyy";
    CHECK(find(text, "happi") == string("Happi"));
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
}

TEST_CASE("Test replacement of v and w") 
{
    string text = "the visa work in vietnam";    
    CHECK(find(text, "visa") == string("visa"));
    CHECK(find(text, "wisa") == string("visa"));
    CHECK(find(text, "work") == string("work"));
    CHECK(find(text, "vork") == string("work"));
    CHECK(find(text, "vietnam") == string("vietnam"));
    CHECK(find(text, "wietnam") == string("vietnam"));
    CHECK(find(text, "Visa") == string("visa"));
    CHECK(find(text, "Work") == string("work"));
    CHECK(find(text, "Vietnam") == string("vietnam"));
}

TEST_CASE("Test replacement of g and j") 
{
    string text = "the bad guys are jealous of the good";    
    CHECK(find(text, "guys") == string("guys"));
    CHECK(find(text, "Juys") == string("guys"));
    CHECK(find(text, "Guys") == string("guys"));
    CHECK(find(text, "jealous") == string("jealous"));
    CHECK(find(text, "gealous") == string("jealous"));
    CHECK(find(text, "Jealous") == string("jealous"));
    CHECK(find(text, "good") == string("good"));
    CHECK(find(text, "jood") == string("good"));
    CHECK(find(text, "Good") == string("good"));
}

TEST_CASE("Test replacement of s and z") 
{
    string text = "the sun is also a star zoey";    
    CHECK(find(text, "sun") == string("sun"));
    CHECK(find(text, "zun") == string("sun"));
    CHECK(find(text, "Sun") == string("sun"));
    CHECK(find(text, "is") == string("is"));
    CHECK(find(text, "iz") == string("is"));
    CHECK(find(text, "Is") == string("is"));
    CHECK(find(text, "also") == string("also"));
    CHECK(find(text, "alzo") == string("also"));
    CHECK(find(text, "Also") == string("also"));
    CHECK(find(text, "star") == string("star"));
    CHECK(find(text, "Ztar") == string("star"));
    CHECK(find(text, "Star") == string("star"));
    CHECK(find(text, "zoey") == string("zoey"));
    CHECK(find(text, "soey") == string("zoey"));
    CHECK(find(text, "Zoey") == string("zoey"));
}

TEST_CASE("Test replacement of d and t") 
{
    string text = "the darkest time of night";    
    CHECK(find(text, "the") == string("the"));
    CHECK(find(text, "dth") == string("the"));
    CHECK(find(text, "The") == string("the"));
    CHECK(find(text, "darkest") == string("darkest"));
    CHECK(find(text, "tarkest") == string("darkest"));
    CHECK(find(text, "tarkesd") == string("darkest"));
    CHECK(find(text, "darkesd") == string("darkest"));
    CHECK(find(text, "Darkest") == string("darkest"));
    CHECK(find(text, "night") == string("night"));
    CHECK(find(text, "nighd") == string("night"));
    CHECK(find(text, "Night") == string("night"));
}

TEST_CASE("Test replacement of o and u") 
{
    string text = "outlet uk online shop";    
    CHECK(find(text, "outlet") == string("outlet"));
    CHECK(find(text, "uutlet") == string("outlet"));
    CHECK(find(text, "uotlet") == string("outlet"));
    CHECK(find(text, "Outlet") == string("outlet"));
    CHECK(find(text, "uk") == string("uk"));
    CHECK(find(text, "ok") == string("uk"));
    CHECK(find(text, "Uk") == string("uk"));
    CHECK(find(text, "online") == string("online"));
    CHECK(find(text, "Unline") == string("online"));
    CHECK(find(text, "Online") == string("online"));
    CHECK(find(text, "shop") == string("shop"));
    CHECK(find(text, "shup") == string("shop"));
    CHECK(find(text, "Shop") == string("shop"));   
}

TEST_CASE("Test replacement of i and y") 
{
    string text = "ice princess lily ";    
    CHECK(find(text, "ice") == string("ice"));
    CHECK(find(text, "yce") == string("ice"));
    CHECK(find(text, "Ice") == string("ice"));
    CHECK(find(text, "princess") == string("princess"));
    CHECK(find(text, "pryncess") == string("princess"));
    CHECK(find(text, "Princess") == string("princess"));
    CHECK(find(text, "lily") == string("lily"));
    CHECK(find(text, "lyly") == string("lily"));
    CHECK(find(text, "lyli") == string("lily"));
    CHECK(find(text, "Lily") == string("lily"));
}

TEST_CASE("Test replacement of b and f") 
{
    string text = "get Back to flack before Abe comes bac";
    CHECK(find(text, "fack") == string("Back"));
    CHECK(find(text, "back") == string("Back"));
    CHECK(find(text, "black") == string("flack"));
    CHECK(find(text, "Flack") == string("flack"));
	CHECK(find(text, "abe") == string("Abe"));
    CHECK(find(text, "Before") == string("before"));
    CHECK(find(text, "fac") == string("bac"));
}

TEST_CASE("Test replacement of b and p") 
{
    string text = "Boys Blay with Blains and lego pricks";
    CHECK(find(text, "boys") == string("Boys"));
    CHECK(find(text, "Play") == string("Blay"));
    CHECK(find(text, "plains") == string("Blains"));
    CHECK(find(text, "Bricks") == string("pricks"));
	CHECK(find(text, "Poys") == string("Boys"));
}

TEST_CASE("Test replacement of f and p") 
{
    string text = "pay with Paypal for funny cups";
    CHECK(find(text, "Fay") == string("pay"));
    CHECK(find(text, "por") == string("for"));
    CHECK(find(text, "Punny") == string("funny"));
    CHECK(find(text, "cufs") == string("cups"));
	CHECK(find(text, "Paypal") == string("Paypal"));
}

TEST_CASE("Test replacement of c and k") 
{
    string text = "cupkaces made of chokclate";
    CHECK(find(text, "CupCaKes") == string("cupkaces"));
    CHECK(find(text, "CUPKACES") == string("cupkaces"));
    CHECK(find(text, "khocklate") == string("chokclate"));
    CHECK(find(text, "CHokKlate") == string("chokclate"));
}

TEST_CASE("Test replacement of c and q") 
{
    string text = "A snipers greatest tool is precision  and good equipment";
	CHECK(find(text, "a") == string("A"));
    CHECK(find(text, "PREQisioN") == string("precision"));
    CHECK(find(text, "precisioN") == string("precision"));
    CHECK(find(text, "equipMENT") == string("equipment"));
    CHECK(find(text, "ECuipmENt") == string("equipment"));
}

TEST_CASE("Test replacement of k and q") 
{
    string text = "kraqkan will sink your qrown korqi ";
    CHECK(find(text, "qraQqan") == string("kraqkan"));
    CHECK(find(text, "SINQ") == string("sink"));
    CHECK(find(text, "KrowN") == string("qrown"));
    CHECK(find(text, "korQI") == string("korqi"));
}