
network HubNetwork
{
    parameters:
        int src;
        int dest;
    submodules:
        D[6] : Device{
        	address = index;
        	source = parent.src;
        	destination = parent.dest;
        }
        H : Hub{
         	source = parent.src;
         	destination = parent.dest;   
        }
    connections:
        D[0].dIn <-- H.gOut[0];
        D[0].dOut --> H.gIn[0];
        
        D[1].dIn <-- H.gOut[1];
        D[1].dOut --> H.gIn[1];
        
        D[2].dIn <-- H.gOut[2];
        D[2].dOut --> H.gIn[2];
        
        D[3].dIn <-- H.gOut[3];
        D[3].dOut --> H.gIn[3];
        
        D[4].dIn <-- H.gOut[4];
        D[4].dOut --> H.gIn[4];
        
        D[5].dIn <-- H.gOut[5];
        D[5].dOut --> H.gIn[5];
}
