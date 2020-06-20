#include "TaskQueuePattern.h"
#include <queue>
int main()
{
    
    auto spData{ std::make_shared<cData>() };
    auto spStatus{ std::make_shared<cStatus>() };
    auto spTQ{ std::make_unique<cTaskQueue>(spData, spStatus) };
    
    spTQ->RunTQ();
    
    auto ResultingStatus = spStatus->GetStatusMessage();
    for(auto Message : *(ResultingStatus.get()) )
    {
        std::cout << Message << std::endl;
    }
    return 0;

}