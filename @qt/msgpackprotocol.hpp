#ifndef MSGPACKPROTOCOL_H
#define MSGPACKPROTOCOL_H
#include <QByteArray>
#include <functional>
#include <amlinterface.hpp>

namespace aml {
namespace protocols {

class MsgPackProtocolPrivate;
class MsgPackProtocol// : public aml::Downlooking
{
public:
    MsgPackProtocol();
    ~MsgPackProtocol();

    //returns std::function that processes data coming from lower module (lower module calls it)
    aml::sinkfunction downlookingSink() ;

    //accepts std::function, which will be called to process data coming to lower module (this module calls it)
    void connectDownlookingSource(aml::sinkfunction toLowerSink) ;

    void propertyChange();

    void setProperty(const QString &name, quint8 value);

private:
    MsgPackProtocolPrivate * const d_ptr;
    Q_DECLARE_PRIVATE(MsgPackProtocol)
};


} // protocols
} // aml

#endif // MSGPACKPROTOCOL_H
