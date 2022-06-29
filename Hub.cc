
#include "Hub.h"
#include "Pkt_m.h"

Define_Module(Hub);

void Hub::initialize()
{
    nodeId = 0;
    pktType = 0;
}

void Hub::handleMessage(cMessage *msg)
{
    Pkt* data = check_and_cast<Pkt*>(msg);
    Pkt* k;
    if(data->getPktType() == pktType){
        while(nodeId < 6){
                if(data->getSourceId() == nodeId){
                    nodeId++;
                    continue;
                }
                k = new Pkt();
                k->setSourceId(data->getSourceId());
                k->setDestinationId(data->getDestinationId());
                send(k, "gOut", nodeId++);
        //        nodeId++;
        }
    }else{
        pktType = 1 - pktType;
        nodeId = 0;
        while(nodeId < 6){
                if(data->getSourceId() == nodeId){
                    nodeId++;
                    continue;
                }
                k = new Pkt();
                k->setSourceId(data->getSourceId());
                k->setDestinationId(data->getDestinationId());
                send(k, "gOut", nodeId++);
        //        nodeId++;
        }
    }

}
