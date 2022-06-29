
#ifndef __LAB_EXAM_TEST_DEVICE_H_
#define __LAB_EXAM_TEST_DEVICE_H_

#include <omnetpp.h>
#include <Pkt_m.h>

using namespace omnetpp;

/**
 * TODO - Generated class
 */
class Device : public cSimpleModule
{
  protected:
    int sourceId;
    int nodeId;
    int destinationId;
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

#endif
