#include "TaskQueuePattern.h"
#include <queue>
int main()
{
    
    auto spData{ std::make_shared<Data>() };
    auto spStatus{ std::make_shared<Status>() };
    auto spTQ{ std::make_unique<TaskQueue>(spData, spStatus) };
    
    spTQ->runTQ();
    
    auto resultingStatus = spStatus->getStatusMessage();
    for(auto message : *(resultingStatus.get()) )
    {
        std::cout << message << std::endl;
    }
    return 0;

}