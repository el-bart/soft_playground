#include <iostream>
#include "Msgs.hpp"
#include "Dispatcher.hpp"
#include "sendAll.hpp"

using namespace std;

struct MyDispatcher: public CustomDispatcher<MyDispatcher,
                                             Msg250,
                                             Msg249,
                                             Msg248,
                                             Msg247,
                                             Msg246,
                                             Msg245,
                                             Msg244,
                                             Msg243,
                                             Msg242,
                                             Msg241,
                                             Msg240,
                                             Msg239,
                                             Msg238,
                                             Msg237,
                                             Msg236,
                                             Msg235,
                                             Msg234,
                                             Msg233,
                                             Msg232,
                                             Msg231,
                                             Msg230,
                                             Msg229,
                                             Msg228,
                                             Msg227,
                                             Msg226,
                                             Msg225,
                                             Msg224,
                                             Msg223,
                                             Msg222,
                                             Msg221,
                                             Msg220,
                                             Msg219,
                                             Msg218,
                                             Msg217,
                                             Msg216,
                                             Msg215,
                                             Msg214,
                                             Msg213,
                                             Msg212,
                                             Msg211,
                                             Msg210,
                                             Msg209,
                                             Msg208,
                                             Msg207,
                                             Msg206,
                                             Msg205,
                                             Msg204,
                                             Msg203,
                                             Msg202,
                                             Msg201,
                                             Msg200,
                                             Msg199,
                                             Msg198,
                                             Msg197,
                                             Msg196,
                                             Msg195,
                                             Msg194,
                                             Msg193,
                                             Msg192,
                                             Msg191,
                                             Msg190,
                                             Msg189,
                                             Msg188,
                                             Msg187,
                                             Msg186,
                                             Msg185,
                                             Msg184,
                                             Msg183,
                                             Msg182,
                                             Msg181,
                                             Msg180,
                                             Msg179,
                                             Msg178,
                                             Msg177,
                                             Msg176,
                                             Msg175,
                                             Msg174,
                                             Msg173,
                                             Msg172,
                                             Msg171,
                                             Msg170,
                                             Msg169,
                                             Msg168,
                                             Msg167,
                                             Msg166,
                                             Msg165,
                                             Msg164,
                                             Msg163,
                                             Msg162,
                                             Msg161,
                                             Msg160,
                                             Msg159,
                                             Msg158,
                                             Msg157,
                                             Msg156,
                                             Msg155,
                                             Msg154,
                                             Msg153,
                                             Msg152,
                                             Msg151,
                                             Msg150,
                                             Msg149,
                                             Msg148,
                                             Msg147,
                                             Msg146,
                                             Msg145,
                                             Msg144,
                                             Msg143,
                                             Msg142,
                                             Msg141,
                                             Msg140,
                                             Msg139,
                                             Msg138,
                                             Msg137,
                                             Msg136,
                                             Msg135,
                                             Msg134,
                                             Msg133,
                                             Msg132,
                                             Msg131,
                                             Msg130,
                                             Msg129,
                                             Msg128,
                                             Msg127,
                                             Msg126,
                                             Msg125,
                                             Msg124,
                                             Msg123,
                                             Msg122,
                                             Msg121,
                                             Msg120,
                                             Msg119,
                                             Msg118,
                                             Msg117,
                                             Msg116,
                                             Msg115,
                                             Msg114,
                                             Msg113,
                                             Msg112,
                                             Msg111,
                                             Msg110,
                                             Msg109,
                                             Msg108,
                                             Msg107,
                                             Msg106,
                                             Msg105,
                                             Msg104,
                                             Msg103,
                                             Msg102,
                                             Msg101,
                                             Msg100,
                                             Msg99,
                                             Msg98,
                                             Msg97,
                                             Msg96,
                                             Msg95,
                                             Msg94,
                                             Msg93,
                                             Msg92,
                                             Msg91,
                                             Msg90,
                                             Msg89,
                                             Msg88,
                                             Msg87,
                                             Msg86,
                                             Msg85,
                                             Msg84,
                                             Msg83,
                                             Msg82,
                                             Msg81,
                                             Msg80,
                                             Msg79,
                                             Msg78,
                                             Msg77,
                                             Msg76,
                                             Msg75,
                                             Msg74,
                                             Msg73,
                                             Msg72,
                                             Msg71,
                                             Msg70,
                                             Msg69,
                                             Msg68,
                                             Msg67,
                                             Msg66,
                                             Msg65,
                                             Msg64,
                                             Msg63,
                                             Msg62,
                                             Msg61,
                                             Msg60,
                                             Msg59,
                                             Msg58,
                                             Msg57,
                                             Msg56,
                                             Msg55,
                                             Msg54,
                                             Msg53,
                                             Msg52,
                                             Msg51,
                                             Msg50,
                                             Msg49,
                                             Msg48,
                                             Msg47,
                                             Msg46,
                                             Msg45,
                                             Msg44,
                                             Msg43,
                                             Msg42,
                                             Msg41,
                                             Msg40,
                                             Msg39,
                                             Msg38,
                                             Msg37,
                                             Msg36,
                                             Msg35,
                                             Msg34,
                                             Msg33,
                                             Msg32,
                                             Msg31,
                                             Msg30,
                                             Msg29,
                                             Msg28,
                                             Msg27,
                                             Msg26,
                                             Msg25,
                                             Msg24,
                                             Msg23,
                                             Msg22,
                                             Msg21,
                                             Msg20,
                                             Msg19,
                                             Msg18,
                                             Msg17,
                                             Msg16,
                                             Msg15,
                                             Msg14,
                                             Msg13,
                                             Msg12,
                                             Msg11,
                                             Msg10,
                                             Msg9,
                                             Msg8,
                                             Msg7,
                                             Msg6,
                                             Msg5,
                                             Msg4,
                                             Msg3,
                                             Msg2,
                                             Msg1
                                            >
{
  template<unsigned N, unsigned S>
  void handle(Msg<N,S> const& msg) { cout << __PRETTY_FUNCTION__ << ": " << Msg<N,S>::type() <<endl; }
};


int main(void)
{
  Msg1 m1;
  MyDispatcher md;

  md.dispatch( serialize(m1) );

  for(unsigned i=0; i<1000; ++i)
    sendAll<250>(md);
}
