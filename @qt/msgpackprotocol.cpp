#include "msgpackprotocol.hpp"

#include <QDebug>

namespace aml {
namespace protocols {

class MsgPackProtocolPrivate
{
public:
    void downlookingSink(const QByteArray &block);

    aml::sinkfunction lowerSink;
};

} // protocols
} // aml

using namespace aml::protocols;


void MsgPackProtocolPrivate::downlookingSink(const QByteArray &block)
{
    qDebug() << "sink:" << block;
}

MsgPackProtocol::MsgPackProtocol() : d_ptr(new MsgPackProtocolPrivate)
{

}

MsgPackProtocol::~MsgPackProtocol()
{
    Q_D(MsgPackProtocol);
    delete d;
}

aml::sinkfunction MsgPackProtocol::downlookingSink()
{
    Q_D(MsgPackProtocol);
    return std::bind(&MsgPackProtocolPrivate::downlookingSink, d, std::placeholders::_1);
}

void MsgPackProtocol::connectDownlookingSource(aml::sinkfunction toLowerSink)
{
    Q_D(MsgPackProtocol);
    d->lowerSink = toLowerSink;
}

void MsgPackProtocol::propertyChange()
{
    Q_D(MsgPackProtocol);
    d->lowerSink(QByteArray("someproperty new value"));
}

void MsgPackProtocol::setProperty(const QString &name, quint8 value)
{
    Q_D(MsgPackProtocol);
    d->lowerSink(QByteArray("set_prop") + name.toLocal8Bit());
}

