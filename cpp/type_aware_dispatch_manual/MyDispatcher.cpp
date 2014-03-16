#include "MyDispatcher.hpp"

void MyDispatcher::dispatch(BinaryMsg const& bin)
{
  if( bin.type_ == Msg1::type() )
  {
    handle( deserialize<Msg1>(bin) );
    return;
  }
  if( bin.type_ == Msg2::type() )
  {
    handle( deserialize<Msg2>(bin) );
    return;
  }
  if( bin.type_ == Msg3::type() )
  {
    handle( deserialize<Msg3>(bin) );
    return;
  }
  if( bin.type_ == Msg4::type() )
  {
    handle( deserialize<Msg4>(bin) );
    return;
  }
  if( bin.type_ == Msg5::type() )
  {
    handle( deserialize<Msg5>(bin) );
    return;
  }
  if( bin.type_ == Msg6::type() )
  {
    handle( deserialize<Msg6>(bin) );
    return;
  }
  if( bin.type_ == Msg7::type() )
  {
    handle( deserialize<Msg7>(bin) );
    return;
  }
  if( bin.type_ == Msg8::type() )
  {
    handle( deserialize<Msg8>(bin) );
    return;
  }
  if( bin.type_ == Msg9::type() )
  {
    handle( deserialize<Msg9>(bin) );
    return;
  }
  if( bin.type_ == Msg10::type() )
  {
    handle( deserialize<Msg10>(bin) );
    return;
  }
  if( bin.type_ == Msg11::type() )
  {
    handle( deserialize<Msg11>(bin) );
    return;
  }
  if( bin.type_ == Msg12::type() )
  {
    handle( deserialize<Msg12>(bin) );
    return;
  }
  if( bin.type_ == Msg13::type() )
  {
    handle( deserialize<Msg13>(bin) );
    return;
  }
  if( bin.type_ == Msg14::type() )
  {
    handle( deserialize<Msg14>(bin) );
    return;
  }
  if( bin.type_ == Msg15::type() )
  {
    handle( deserialize<Msg15>(bin) );
    return;
  }
  if( bin.type_ == Msg16::type() )
  {
    handle( deserialize<Msg16>(bin) );
    return;
  }
  if( bin.type_ == Msg17::type() )
  {
    handle( deserialize<Msg17>(bin) );
    return;
  }
  if( bin.type_ == Msg18::type() )
  {
    handle( deserialize<Msg18>(bin) );
    return;
  }
  if( bin.type_ == Msg19::type() )
  {
    handle( deserialize<Msg19>(bin) );
    return;
  }
  if( bin.type_ == Msg20::type() )
  {
    handle( deserialize<Msg20>(bin) );
    return;
  }
  if( bin.type_ == Msg21::type() )
  {
    handle( deserialize<Msg21>(bin) );
    return;
  }
  if( bin.type_ == Msg22::type() )
  {
    handle( deserialize<Msg22>(bin) );
    return;
  }
  if( bin.type_ == Msg23::type() )
  {
    handle( deserialize<Msg23>(bin) );
    return;
  }
  if( bin.type_ == Msg24::type() )
  {
    handle( deserialize<Msg24>(bin) );
    return;
  }
  if( bin.type_ == Msg25::type() )
  {
    handle( deserialize<Msg25>(bin) );
    return;
  }
  if( bin.type_ == Msg26::type() )
  {
    handle( deserialize<Msg26>(bin) );
    return;
  }
  if( bin.type_ == Msg27::type() )
  {
    handle( deserialize<Msg27>(bin) );
    return;
  }
  if( bin.type_ == Msg28::type() )
  {
    handle( deserialize<Msg28>(bin) );
    return;
  }
  if( bin.type_ == Msg29::type() )
  {
    handle( deserialize<Msg29>(bin) );
    return;
  }
  if( bin.type_ == Msg30::type() )
  {
    handle( deserialize<Msg30>(bin) );
    return;
  }
  if( bin.type_ == Msg31::type() )
  {
    handle( deserialize<Msg31>(bin) );
    return;
  }
  if( bin.type_ == Msg32::type() )
  {
    handle( deserialize<Msg32>(bin) );
    return;
  }
  if( bin.type_ == Msg33::type() )
  {
    handle( deserialize<Msg33>(bin) );
    return;
  }
  if( bin.type_ == Msg34::type() )
  {
    handle( deserialize<Msg34>(bin) );
    return;
  }
  if( bin.type_ == Msg35::type() )
  {
    handle( deserialize<Msg35>(bin) );
    return;
  }
  if( bin.type_ == Msg36::type() )
  {
    handle( deserialize<Msg36>(bin) );
    return;
  }
  if( bin.type_ == Msg37::type() )
  {
    handle( deserialize<Msg37>(bin) );
    return;
  }
  if( bin.type_ == Msg38::type() )
  {
    handle( deserialize<Msg38>(bin) );
    return;
  }
  if( bin.type_ == Msg39::type() )
  {
    handle( deserialize<Msg39>(bin) );
    return;
  }
  if( bin.type_ == Msg40::type() )
  {
    handle( deserialize<Msg40>(bin) );
    return;
  }
  if( bin.type_ == Msg41::type() )
  {
    handle( deserialize<Msg41>(bin) );
    return;
  }
  if( bin.type_ == Msg42::type() )
  {
    handle( deserialize<Msg42>(bin) );
    return;
  }
  if( bin.type_ == Msg43::type() )
  {
    handle( deserialize<Msg43>(bin) );
    return;
  }
  if( bin.type_ == Msg44::type() )
  {
    handle( deserialize<Msg44>(bin) );
    return;
  }
  if( bin.type_ == Msg45::type() )
  {
    handle( deserialize<Msg45>(bin) );
    return;
  }
  if( bin.type_ == Msg46::type() )
  {
    handle( deserialize<Msg46>(bin) );
    return;
  }
  if( bin.type_ == Msg47::type() )
  {
    handle( deserialize<Msg47>(bin) );
    return;
  }
  if( bin.type_ == Msg48::type() )
  {
    handle( deserialize<Msg48>(bin) );
    return;
  }
  if( bin.type_ == Msg49::type() )
  {
    handle( deserialize<Msg49>(bin) );
    return;
  }
  if( bin.type_ == Msg50::type() )
  {
    handle( deserialize<Msg50>(bin) );
    return;
  }
  if( bin.type_ == Msg51::type() )
  {
    handle( deserialize<Msg51>(bin) );
    return;
  }
  if( bin.type_ == Msg52::type() )
  {
    handle( deserialize<Msg52>(bin) );
    return;
  }
  if( bin.type_ == Msg53::type() )
  {
    handle( deserialize<Msg53>(bin) );
    return;
  }
  if( bin.type_ == Msg54::type() )
  {
    handle( deserialize<Msg54>(bin) );
    return;
  }
  if( bin.type_ == Msg55::type() )
  {
    handle( deserialize<Msg55>(bin) );
    return;
  }
  if( bin.type_ == Msg56::type() )
  {
    handle( deserialize<Msg56>(bin) );
    return;
  }
  if( bin.type_ == Msg57::type() )
  {
    handle( deserialize<Msg57>(bin) );
    return;
  }
  if( bin.type_ == Msg58::type() )
  {
    handle( deserialize<Msg58>(bin) );
    return;
  }
  if( bin.type_ == Msg59::type() )
  {
    handle( deserialize<Msg59>(bin) );
    return;
  }
  if( bin.type_ == Msg60::type() )
  {
    handle( deserialize<Msg60>(bin) );
    return;
  }
  if( bin.type_ == Msg61::type() )
  {
    handle( deserialize<Msg61>(bin) );
    return;
  }
  if( bin.type_ == Msg62::type() )
  {
    handle( deserialize<Msg62>(bin) );
    return;
  }
  if( bin.type_ == Msg63::type() )
  {
    handle( deserialize<Msg63>(bin) );
    return;
  }
  if( bin.type_ == Msg64::type() )
  {
    handle( deserialize<Msg64>(bin) );
    return;
  }
  if( bin.type_ == Msg65::type() )
  {
    handle( deserialize<Msg65>(bin) );
    return;
  }
  if( bin.type_ == Msg66::type() )
  {
    handle( deserialize<Msg66>(bin) );
    return;
  }
  if( bin.type_ == Msg67::type() )
  {
    handle( deserialize<Msg67>(bin) );
    return;
  }
  if( bin.type_ == Msg68::type() )
  {
    handle( deserialize<Msg68>(bin) );
    return;
  }
  if( bin.type_ == Msg69::type() )
  {
    handle( deserialize<Msg69>(bin) );
    return;
  }
  if( bin.type_ == Msg70::type() )
  {
    handle( deserialize<Msg70>(bin) );
    return;
  }
  if( bin.type_ == Msg71::type() )
  {
    handle( deserialize<Msg71>(bin) );
    return;
  }
  if( bin.type_ == Msg72::type() )
  {
    handle( deserialize<Msg72>(bin) );
    return;
  }
  if( bin.type_ == Msg73::type() )
  {
    handle( deserialize<Msg73>(bin) );
    return;
  }
  if( bin.type_ == Msg74::type() )
  {
    handle( deserialize<Msg74>(bin) );
    return;
  }
  if( bin.type_ == Msg75::type() )
  {
    handle( deserialize<Msg75>(bin) );
    return;
  }
  if( bin.type_ == Msg76::type() )
  {
    handle( deserialize<Msg76>(bin) );
    return;
  }
  if( bin.type_ == Msg77::type() )
  {
    handle( deserialize<Msg77>(bin) );
    return;
  }
  if( bin.type_ == Msg78::type() )
  {
    handle( deserialize<Msg78>(bin) );
    return;
  }
  if( bin.type_ == Msg79::type() )
  {
    handle( deserialize<Msg79>(bin) );
    return;
  }
  if( bin.type_ == Msg80::type() )
  {
    handle( deserialize<Msg80>(bin) );
    return;
  }
  if( bin.type_ == Msg81::type() )
  {
    handle( deserialize<Msg81>(bin) );
    return;
  }
  if( bin.type_ == Msg82::type() )
  {
    handle( deserialize<Msg82>(bin) );
    return;
  }
  if( bin.type_ == Msg83::type() )
  {
    handle( deserialize<Msg83>(bin) );
    return;
  }
  if( bin.type_ == Msg84::type() )
  {
    handle( deserialize<Msg84>(bin) );
    return;
  }
  if( bin.type_ == Msg85::type() )
  {
    handle( deserialize<Msg85>(bin) );
    return;
  }
  if( bin.type_ == Msg86::type() )
  {
    handle( deserialize<Msg86>(bin) );
    return;
  }
  if( bin.type_ == Msg87::type() )
  {
    handle( deserialize<Msg87>(bin) );
    return;
  }
  if( bin.type_ == Msg88::type() )
  {
    handle( deserialize<Msg88>(bin) );
    return;
  }
  if( bin.type_ == Msg89::type() )
  {
    handle( deserialize<Msg89>(bin) );
    return;
  }
  if( bin.type_ == Msg90::type() )
  {
    handle( deserialize<Msg90>(bin) );
    return;
  }
  if( bin.type_ == Msg91::type() )
  {
    handle( deserialize<Msg91>(bin) );
    return;
  }
  if( bin.type_ == Msg92::type() )
  {
    handle( deserialize<Msg92>(bin) );
    return;
  }
  if( bin.type_ == Msg93::type() )
  {
    handle( deserialize<Msg93>(bin) );
    return;
  }
  if( bin.type_ == Msg94::type() )
  {
    handle( deserialize<Msg94>(bin) );
    return;
  }
  if( bin.type_ == Msg95::type() )
  {
    handle( deserialize<Msg95>(bin) );
    return;
  }
  if( bin.type_ == Msg96::type() )
  {
    handle( deserialize<Msg96>(bin) );
    return;
  }
  if( bin.type_ == Msg97::type() )
  {
    handle( deserialize<Msg97>(bin) );
    return;
  }
  if( bin.type_ == Msg98::type() )
  {
    handle( deserialize<Msg98>(bin) );
    return;
  }
  if( bin.type_ == Msg99::type() )
  {
    handle( deserialize<Msg99>(bin) );
    return;
  }
  if( bin.type_ == Msg100::type() )
  {
    handle( deserialize<Msg100>(bin) );
    return;
  }
  if( bin.type_ == Msg101::type() )
  {
    handle( deserialize<Msg101>(bin) );
    return;
  }
  if( bin.type_ == Msg102::type() )
  {
    handle( deserialize<Msg102>(bin) );
    return;
  }
  if( bin.type_ == Msg103::type() )
  {
    handle( deserialize<Msg103>(bin) );
    return;
  }
  if( bin.type_ == Msg104::type() )
  {
    handle( deserialize<Msg104>(bin) );
    return;
  }
  if( bin.type_ == Msg105::type() )
  {
    handle( deserialize<Msg105>(bin) );
    return;
  }
  if( bin.type_ == Msg106::type() )
  {
    handle( deserialize<Msg106>(bin) );
    return;
  }
  if( bin.type_ == Msg107::type() )
  {
    handle( deserialize<Msg107>(bin) );
    return;
  }
  if( bin.type_ == Msg108::type() )
  {
    handle( deserialize<Msg108>(bin) );
    return;
  }
  if( bin.type_ == Msg109::type() )
  {
    handle( deserialize<Msg109>(bin) );
    return;
  }
  if( bin.type_ == Msg110::type() )
  {
    handle( deserialize<Msg110>(bin) );
    return;
  }
  if( bin.type_ == Msg111::type() )
  {
    handle( deserialize<Msg111>(bin) );
    return;
  }
  if( bin.type_ == Msg112::type() )
  {
    handle( deserialize<Msg112>(bin) );
    return;
  }
  if( bin.type_ == Msg113::type() )
  {
    handle( deserialize<Msg113>(bin) );
    return;
  }
  if( bin.type_ == Msg114::type() )
  {
    handle( deserialize<Msg114>(bin) );
    return;
  }
  if( bin.type_ == Msg115::type() )
  {
    handle( deserialize<Msg115>(bin) );
    return;
  }
  if( bin.type_ == Msg116::type() )
  {
    handle( deserialize<Msg116>(bin) );
    return;
  }
  if( bin.type_ == Msg117::type() )
  {
    handle( deserialize<Msg117>(bin) );
    return;
  }
  if( bin.type_ == Msg118::type() )
  {
    handle( deserialize<Msg118>(bin) );
    return;
  }
  if( bin.type_ == Msg119::type() )
  {
    handle( deserialize<Msg119>(bin) );
    return;
  }
  if( bin.type_ == Msg120::type() )
  {
    handle( deserialize<Msg120>(bin) );
    return;
  }
  if( bin.type_ == Msg121::type() )
  {
    handle( deserialize<Msg121>(bin) );
    return;
  }
  if( bin.type_ == Msg122::type() )
  {
    handle( deserialize<Msg122>(bin) );
    return;
  }
  if( bin.type_ == Msg123::type() )
  {
    handle( deserialize<Msg123>(bin) );
    return;
  }
  if( bin.type_ == Msg124::type() )
  {
    handle( deserialize<Msg124>(bin) );
    return;
  }
  if( bin.type_ == Msg125::type() )
  {
    handle( deserialize<Msg125>(bin) );
    return;
  }
  if( bin.type_ == Msg126::type() )
  {
    handle( deserialize<Msg126>(bin) );
    return;
  }
  if( bin.type_ == Msg127::type() )
  {
    handle( deserialize<Msg127>(bin) );
    return;
  }
  if( bin.type_ == Msg128::type() )
  {
    handle( deserialize<Msg128>(bin) );
    return;
  }
  if( bin.type_ == Msg129::type() )
  {
    handle( deserialize<Msg129>(bin) );
    return;
  }
  if( bin.type_ == Msg130::type() )
  {
    handle( deserialize<Msg130>(bin) );
    return;
  }
  if( bin.type_ == Msg131::type() )
  {
    handle( deserialize<Msg131>(bin) );
    return;
  }
  if( bin.type_ == Msg132::type() )
  {
    handle( deserialize<Msg132>(bin) );
    return;
  }
  if( bin.type_ == Msg133::type() )
  {
    handle( deserialize<Msg133>(bin) );
    return;
  }
  if( bin.type_ == Msg134::type() )
  {
    handle( deserialize<Msg134>(bin) );
    return;
  }
  if( bin.type_ == Msg135::type() )
  {
    handle( deserialize<Msg135>(bin) );
    return;
  }
  if( bin.type_ == Msg136::type() )
  {
    handle( deserialize<Msg136>(bin) );
    return;
  }
  if( bin.type_ == Msg137::type() )
  {
    handle( deserialize<Msg137>(bin) );
    return;
  }
  if( bin.type_ == Msg138::type() )
  {
    handle( deserialize<Msg138>(bin) );
    return;
  }
  if( bin.type_ == Msg139::type() )
  {
    handle( deserialize<Msg139>(bin) );
    return;
  }
  if( bin.type_ == Msg140::type() )
  {
    handle( deserialize<Msg140>(bin) );
    return;
  }
  if( bin.type_ == Msg141::type() )
  {
    handle( deserialize<Msg141>(bin) );
    return;
  }
  if( bin.type_ == Msg142::type() )
  {
    handle( deserialize<Msg142>(bin) );
    return;
  }
  if( bin.type_ == Msg143::type() )
  {
    handle( deserialize<Msg143>(bin) );
    return;
  }
  if( bin.type_ == Msg144::type() )
  {
    handle( deserialize<Msg144>(bin) );
    return;
  }
  if( bin.type_ == Msg145::type() )
  {
    handle( deserialize<Msg145>(bin) );
    return;
  }
  if( bin.type_ == Msg146::type() )
  {
    handle( deserialize<Msg146>(bin) );
    return;
  }
  if( bin.type_ == Msg147::type() )
  {
    handle( deserialize<Msg147>(bin) );
    return;
  }
  if( bin.type_ == Msg148::type() )
  {
    handle( deserialize<Msg148>(bin) );
    return;
  }
  if( bin.type_ == Msg149::type() )
  {
    handle( deserialize<Msg149>(bin) );
    return;
  }
  if( bin.type_ == Msg150::type() )
  {
    handle( deserialize<Msg150>(bin) );
    return;
  }
  if( bin.type_ == Msg151::type() )
  {
    handle( deserialize<Msg151>(bin) );
    return;
  }
  if( bin.type_ == Msg152::type() )
  {
    handle( deserialize<Msg152>(bin) );
    return;
  }
  if( bin.type_ == Msg153::type() )
  {
    handle( deserialize<Msg153>(bin) );
    return;
  }
  if( bin.type_ == Msg154::type() )
  {
    handle( deserialize<Msg154>(bin) );
    return;
  }
  if( bin.type_ == Msg155::type() )
  {
    handle( deserialize<Msg155>(bin) );
    return;
  }
  if( bin.type_ == Msg156::type() )
  {
    handle( deserialize<Msg156>(bin) );
    return;
  }
  if( bin.type_ == Msg157::type() )
  {
    handle( deserialize<Msg157>(bin) );
    return;
  }
  if( bin.type_ == Msg158::type() )
  {
    handle( deserialize<Msg158>(bin) );
    return;
  }
  if( bin.type_ == Msg159::type() )
  {
    handle( deserialize<Msg159>(bin) );
    return;
  }
  if( bin.type_ == Msg160::type() )
  {
    handle( deserialize<Msg160>(bin) );
    return;
  }
  if( bin.type_ == Msg161::type() )
  {
    handle( deserialize<Msg161>(bin) );
    return;
  }
  if( bin.type_ == Msg162::type() )
  {
    handle( deserialize<Msg162>(bin) );
    return;
  }
  if( bin.type_ == Msg163::type() )
  {
    handle( deserialize<Msg163>(bin) );
    return;
  }
  if( bin.type_ == Msg164::type() )
  {
    handle( deserialize<Msg164>(bin) );
    return;
  }
  if( bin.type_ == Msg165::type() )
  {
    handle( deserialize<Msg165>(bin) );
    return;
  }
  if( bin.type_ == Msg166::type() )
  {
    handle( deserialize<Msg166>(bin) );
    return;
  }
  if( bin.type_ == Msg167::type() )
  {
    handle( deserialize<Msg167>(bin) );
    return;
  }
  if( bin.type_ == Msg168::type() )
  {
    handle( deserialize<Msg168>(bin) );
    return;
  }
  if( bin.type_ == Msg169::type() )
  {
    handle( deserialize<Msg169>(bin) );
    return;
  }
  if( bin.type_ == Msg170::type() )
  {
    handle( deserialize<Msg170>(bin) );
    return;
  }
  if( bin.type_ == Msg171::type() )
  {
    handle( deserialize<Msg171>(bin) );
    return;
  }
  if( bin.type_ == Msg172::type() )
  {
    handle( deserialize<Msg172>(bin) );
    return;
  }
  if( bin.type_ == Msg173::type() )
  {
    handle( deserialize<Msg173>(bin) );
    return;
  }
  if( bin.type_ == Msg174::type() )
  {
    handle( deserialize<Msg174>(bin) );
    return;
  }
  if( bin.type_ == Msg175::type() )
  {
    handle( deserialize<Msg175>(bin) );
    return;
  }
  if( bin.type_ == Msg176::type() )
  {
    handle( deserialize<Msg176>(bin) );
    return;
  }
  if( bin.type_ == Msg177::type() )
  {
    handle( deserialize<Msg177>(bin) );
    return;
  }
  if( bin.type_ == Msg178::type() )
  {
    handle( deserialize<Msg178>(bin) );
    return;
  }
  if( bin.type_ == Msg179::type() )
  {
    handle( deserialize<Msg179>(bin) );
    return;
  }
  if( bin.type_ == Msg180::type() )
  {
    handle( deserialize<Msg180>(bin) );
    return;
  }
  if( bin.type_ == Msg181::type() )
  {
    handle( deserialize<Msg181>(bin) );
    return;
  }
  if( bin.type_ == Msg182::type() )
  {
    handle( deserialize<Msg182>(bin) );
    return;
  }
  if( bin.type_ == Msg183::type() )
  {
    handle( deserialize<Msg183>(bin) );
    return;
  }
  if( bin.type_ == Msg184::type() )
  {
    handle( deserialize<Msg184>(bin) );
    return;
  }
  if( bin.type_ == Msg185::type() )
  {
    handle( deserialize<Msg185>(bin) );
    return;
  }
  if( bin.type_ == Msg186::type() )
  {
    handle( deserialize<Msg186>(bin) );
    return;
  }
  if( bin.type_ == Msg187::type() )
  {
    handle( deserialize<Msg187>(bin) );
    return;
  }
  if( bin.type_ == Msg188::type() )
  {
    handle( deserialize<Msg188>(bin) );
    return;
  }
  if( bin.type_ == Msg189::type() )
  {
    handle( deserialize<Msg189>(bin) );
    return;
  }
  if( bin.type_ == Msg190::type() )
  {
    handle( deserialize<Msg190>(bin) );
    return;
  }
  if( bin.type_ == Msg191::type() )
  {
    handle( deserialize<Msg191>(bin) );
    return;
  }
  if( bin.type_ == Msg192::type() )
  {
    handle( deserialize<Msg192>(bin) );
    return;
  }
  if( bin.type_ == Msg193::type() )
  {
    handle( deserialize<Msg193>(bin) );
    return;
  }
  if( bin.type_ == Msg194::type() )
  {
    handle( deserialize<Msg194>(bin) );
    return;
  }
  if( bin.type_ == Msg195::type() )
  {
    handle( deserialize<Msg195>(bin) );
    return;
  }
  if( bin.type_ == Msg196::type() )
  {
    handle( deserialize<Msg196>(bin) );
    return;
  }
  if( bin.type_ == Msg197::type() )
  {
    handle( deserialize<Msg197>(bin) );
    return;
  }
  if( bin.type_ == Msg198::type() )
  {
    handle( deserialize<Msg198>(bin) );
    return;
  }
  if( bin.type_ == Msg199::type() )
  {
    handle( deserialize<Msg199>(bin) );
    return;
  }
  if( bin.type_ == Msg200::type() )
  {
    handle( deserialize<Msg200>(bin) );
    return;
  }
  if( bin.type_ == Msg201::type() )
  {
    handle( deserialize<Msg201>(bin) );
    return;
  }
  if( bin.type_ == Msg202::type() )
  {
    handle( deserialize<Msg202>(bin) );
    return;
  }
  if( bin.type_ == Msg203::type() )
  {
    handle( deserialize<Msg203>(bin) );
    return;
  }
  if( bin.type_ == Msg204::type() )
  {
    handle( deserialize<Msg204>(bin) );
    return;
  }
  if( bin.type_ == Msg205::type() )
  {
    handle( deserialize<Msg205>(bin) );
    return;
  }
  if( bin.type_ == Msg206::type() )
  {
    handle( deserialize<Msg206>(bin) );
    return;
  }
  if( bin.type_ == Msg207::type() )
  {
    handle( deserialize<Msg207>(bin) );
    return;
  }
  if( bin.type_ == Msg208::type() )
  {
    handle( deserialize<Msg208>(bin) );
    return;
  }
  if( bin.type_ == Msg209::type() )
  {
    handle( deserialize<Msg209>(bin) );
    return;
  }
  if( bin.type_ == Msg210::type() )
  {
    handle( deserialize<Msg210>(bin) );
    return;
  }
  if( bin.type_ == Msg211::type() )
  {
    handle( deserialize<Msg211>(bin) );
    return;
  }
  if( bin.type_ == Msg212::type() )
  {
    handle( deserialize<Msg212>(bin) );
    return;
  }
  if( bin.type_ == Msg213::type() )
  {
    handle( deserialize<Msg213>(bin) );
    return;
  }
  if( bin.type_ == Msg214::type() )
  {
    handle( deserialize<Msg214>(bin) );
    return;
  }
  if( bin.type_ == Msg215::type() )
  {
    handle( deserialize<Msg215>(bin) );
    return;
  }
  if( bin.type_ == Msg216::type() )
  {
    handle( deserialize<Msg216>(bin) );
    return;
  }
  if( bin.type_ == Msg217::type() )
  {
    handle( deserialize<Msg217>(bin) );
    return;
  }
  if( bin.type_ == Msg218::type() )
  {
    handle( deserialize<Msg218>(bin) );
    return;
  }
  if( bin.type_ == Msg219::type() )
  {
    handle( deserialize<Msg219>(bin) );
    return;
  }
  if( bin.type_ == Msg220::type() )
  {
    handle( deserialize<Msg220>(bin) );
    return;
  }
  if( bin.type_ == Msg221::type() )
  {
    handle( deserialize<Msg221>(bin) );
    return;
  }
  if( bin.type_ == Msg222::type() )
  {
    handle( deserialize<Msg222>(bin) );
    return;
  }
  if( bin.type_ == Msg223::type() )
  {
    handle( deserialize<Msg223>(bin) );
    return;
  }
  if( bin.type_ == Msg224::type() )
  {
    handle( deserialize<Msg224>(bin) );
    return;
  }
  if( bin.type_ == Msg225::type() )
  {
    handle( deserialize<Msg225>(bin) );
    return;
  }
  if( bin.type_ == Msg226::type() )
  {
    handle( deserialize<Msg226>(bin) );
    return;
  }
  if( bin.type_ == Msg227::type() )
  {
    handle( deserialize<Msg227>(bin) );
    return;
  }
  if( bin.type_ == Msg228::type() )
  {
    handle( deserialize<Msg228>(bin) );
    return;
  }
  if( bin.type_ == Msg229::type() )
  {
    handle( deserialize<Msg229>(bin) );
    return;
  }
  if( bin.type_ == Msg230::type() )
  {
    handle( deserialize<Msg230>(bin) );
    return;
  }
  if( bin.type_ == Msg231::type() )
  {
    handle( deserialize<Msg231>(bin) );
    return;
  }
  if( bin.type_ == Msg232::type() )
  {
    handle( deserialize<Msg232>(bin) );
    return;
  }
  if( bin.type_ == Msg233::type() )
  {
    handle( deserialize<Msg233>(bin) );
    return;
  }
  if( bin.type_ == Msg234::type() )
  {
    handle( deserialize<Msg234>(bin) );
    return;
  }
  if( bin.type_ == Msg235::type() )
  {
    handle( deserialize<Msg235>(bin) );
    return;
  }
  if( bin.type_ == Msg236::type() )
  {
    handle( deserialize<Msg236>(bin) );
    return;
  }
  if( bin.type_ == Msg237::type() )
  {
    handle( deserialize<Msg237>(bin) );
    return;
  }
  if( bin.type_ == Msg238::type() )
  {
    handle( deserialize<Msg238>(bin) );
    return;
  }
  if( bin.type_ == Msg239::type() )
  {
    handle( deserialize<Msg239>(bin) );
    return;
  }
  if( bin.type_ == Msg240::type() )
  {
    handle( deserialize<Msg240>(bin) );
    return;
  }
  if( bin.type_ == Msg241::type() )
  {
    handle( deserialize<Msg241>(bin) );
    return;
  }
  if( bin.type_ == Msg242::type() )
  {
    handle( deserialize<Msg242>(bin) );
    return;
  }
  if( bin.type_ == Msg243::type() )
  {
    handle( deserialize<Msg243>(bin) );
    return;
  }
  if( bin.type_ == Msg244::type() )
  {
    handle( deserialize<Msg244>(bin) );
    return;
  }
  if( bin.type_ == Msg245::type() )
  {
    handle( deserialize<Msg245>(bin) );
    return;
  }
  if( bin.type_ == Msg246::type() )
  {
    handle( deserialize<Msg246>(bin) );
    return;
  }
  if( bin.type_ == Msg247::type() )
  {
    handle( deserialize<Msg247>(bin) );
    return;
  }
  if( bin.type_ == Msg248::type() )
  {
    handle( deserialize<Msg248>(bin) );
    return;
  }
  if( bin.type_ == Msg249::type() )
  {
    handle( deserialize<Msg249>(bin) );
    return;
  }
  if( bin.type_ == Msg250::type() )
  {
    handle( deserialize<Msg250>(bin) );
    return;
  }
  throw std::runtime_error("no handler for a given message type");
}
