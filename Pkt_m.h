//
// Generated file, do not edit! Created by nedtool 6.0 from Pkt.msg.
//

#ifndef __PKT_M_H
#define __PKT_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0600
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif

class Pkt;
/**
 * Class generated from <tt>Pkt.msg:2</tt> by nedtool.
 * <pre>
 * packet Pkt
 * {
 *     int pktType; //0 -> Data, 1 -> ACK
 *     int sourceId;
 *     int destinationId;
 * }
 * </pre>
 */
class Pkt : public ::omnetpp::cPacket
{
  protected:
    int pktType = 0;
    int sourceId = 0;
    int destinationId = 0;

  private:
    void copy(const Pkt& other);

  protected:
    bool operator==(const Pkt&) = delete;

  public:
    Pkt(const char *name=nullptr, short kind=0);
    Pkt(const Pkt& other);
    virtual ~Pkt();
    Pkt& operator=(const Pkt& other);
    virtual Pkt *dup() const override {return new Pkt(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual int getPktType() const;
    virtual void setPktType(int pktType);

    virtual int getSourceId() const;
    virtual void setSourceId(int sourceId);

    virtual int getDestinationId() const;
    virtual void setDestinationId(int destinationId);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Pkt& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Pkt& obj) {obj.parsimUnpack(b);}


namespace omnetpp {

template<> inline Pkt *fromAnyPtr(any_ptr ptr) { return check_and_cast<Pkt*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __PKT_M_H

