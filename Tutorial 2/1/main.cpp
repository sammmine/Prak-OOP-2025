#include "Agent.hpp"
#include "SuperAgent.hpp"

int main() {
    SuperAgent agentX;

    Agent& agentXRef = agentX;
    // Upcasting:
    // Proses mengonversi objek dari child class (subclass) menjadi parent class (superclass) secara implisit,
    // Menggunakan reference (atau bisa juga pointer) untuk memanggil method dari parent class
    
    agentXRef.setID(1337);
    agentX.setID(9999);

    agentX.print();
    return 0;
}