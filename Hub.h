
#ifndef __LAB_EXAM_TEST_HUB_H_
#define __LAB_EXAM_TEST_HUB_H_

#include <omnetpp.h>

using namespace omnetpp;

/**
 * TODO - Generated class
 */
class Hub : public cSimpleModule
{
  protected:
    int nodeId;
    int pktType;
//    int count;
//    cGate* outGate[6];
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

#endif
