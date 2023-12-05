#include "TaskQueuePattern.h"
#include <queue>
int main()
{
    
    auto spData{ std::make_shared<Data>() };
    auto spStatus{ std::make_shared<Status>() };
    auto spTQ{ std::make_unique<TaskQueue>(spData, spStatus) };

    auto taskNames = spTQ->getTaskNames();
    auto numberOfTasks = taskNames.size();
    size_t nPreviousRandomNumber = 0;
    srand( (unsigned)time(NULL) );
    size_t nRsandNum = ( rand() % numberOfTasks );
    
    if(!spTQ->isTaskQueueEmpty())// just to demonstarte the usage
    {
        spTQ->clearTaskQueue();
    }
    spStatus->setStatusMessage("Main: Randomly Initializing Task Queue!");
    for(size_t i=0; i<10; ++i)
    {
                
        while( nPreviousRandomNumber == nRsandNum )
        {
            nRsandNum = ( rand() % numberOfTasks );
        }
        
        spTQ->addTaskToQueueByName(taskNames[nRsandNum]);

        nPreviousRandomNumber = nRsandNum;
    }
    
    spTQ->runTQ();
    
    auto resultingStatus = spStatus->getStatusMessage();
    for(auto message : *(resultingStatus.get()) )
    {
        std::cout << message << std::endl;
    }
    return 0;

}