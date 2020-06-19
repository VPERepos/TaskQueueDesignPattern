#include "TaskQueuePattern.h"
#include <queue>
int main()
{
    std::queue<std::shared_ptr<cTask>> TaskQueue;
    auto spData{ std::make_shared<cData>() };
    auto spState1{ std::shared_ptr<cTask>( new cTask1 ) };
    auto spState2{ std::shared_ptr<cTask>( new cTask2 ) };
    auto spState3{ std::shared_ptr<cTask>( new cTask3 ) };
    auto spState4{ std::shared_ptr<cTask>( new cTask4 ) };

    spState1->SetDataPointer( spData );
    spState2->SetDataPointer( spData );
    spState3->SetDataPointer( spData );
    spState4->SetDataPointer( spData );

    size_t nPreviousRandomNumber = 0;
    
    for(size_t i=0; i<10; ++i)
    {
        srand( (unsigned)time(NULL) );
        size_t nRsandNum = ( rand() % 4 ) + 1;
        
        while( nPreviousRandomNumber == nRsandNum )
        {
            nRsandNum = ( rand() % 4 ) + 1;
        }
        
        nPreviousRandomNumber = nRsandNum;
        if(nRsandNum == 1)
        {
            TaskQueue.push(spState1);
        }
        else if(nRsandNum == 2)
        {
            TaskQueue.push(spState2);
        }
        else if(nRsandNum == 3)
        {
            TaskQueue.push(spState3);
        }
        else if(nRsandNum == 4)
        {
            TaskQueue.push(spState4);
        }
    }
    
      
    
    while ( !TaskQueue.empty() )
    {
        TaskQueue.front()->ExecuteStateTask();
        TaskQueue.pop();
    }
    return 0;

}