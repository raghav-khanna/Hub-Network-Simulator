
#include "Device.h"
#include "Pkt_m.h"

Define_Module(Device);

void Device::initialize()
{
    sourceId = par("source");
    destinationId = par("destination");
    nodeId = par("address");
    if(nodeId == sourceId){
        cMessage *event = new cMessage();
        scheduleAt(0, event);
    }
}

void Device::handleMessage(cMessage *msg)
{
    if(msg->isSelfMessage()){
        Pkt* data = new Pkt("Data");
        data->setSourceId(nodeId);
        data->setDestinationId(destinationId);
        data->setPktType(0);
        send(data, "dOut");
    }else{
        Pkt* data = check_and_cast<Pkt*>(msg);
        if(data->getDestinationId() == nodeId && data->getPktType() == 0){
            Pkt* ack = new Pkt("ACK");
            ack->setSourceId(nodeId);
            ack->setPktType(1);
            ack->setDestinationId(data->getSourceId());
            send(ack, "dOut");
        }else if(data->getDestinationId() == nodeId && data->getPktType() == 1){
            bubble("ACK Accepted");
            delete msg;
        }else{
            bubble("Deleting the Message");
            delete msg;
        }
    }
}
