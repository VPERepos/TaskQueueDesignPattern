#include "TaskQueuePattern.h"
#include <time.h>



void Task::setDataPointer( const std::shared_ptr<Data>& spData )
{
    this->spData = spData;
}

void Task::setStatusPointer( const std::shared_ptr<Status>& spStatus )
{
    this->spStatus = spStatus;
};

void Task1::executeTask()
{
    spData->vGuestBook.push_back( "Task 1 was here" );
    spStatus->setStatusMessage("TQ: Executing Task 1");
}

void Task2::executeTask()
{
    spData->vGuestBook.push_back( "Task 2 was here" );
    spStatus->setStatusMessage("TQ: Executing Task 2");
}

void Task3::executeTask()
{
    spData->vGuestBook.push_back( "Task 3 was here" );
    spStatus->setStatusMessage("TQ: Executing Task 3");
}

void Task4::executeTask()
{
    spData->vGuestBook.push_back( "Task 4 was here" );
    spStatus->setStatusMessage("TQ: Executing Task 4");
}

Status::Status()
{
    spExecMessage = std::make_shared<std::vector<std::string>>();
};

void Status::setStatusMessage(const std::string& sStatusMessage)
{
    spExecMessage->push_back(sStatusMessage);
};

void Status::setStatus(const bool& bExecStatus)
{
    this->bExecutionStatus = bExecStatus;
};

std::shared_ptr<std::vector<std::string>> Status::getStatusMessage() const
{
    return spExecMessage;
};

bool Status::getStatus() const
{
    return bExecutionStatus;
}

TaskQueue::TaskQueue(const std::shared_ptr<Data>& spData, const std::shared_ptr<Status>& spStatus):
spData(spData), spStatus(spStatus)
{
    spTask1 = std::shared_ptr<Task>( new Task1 );
    spTask2 = std::shared_ptr<Task>( new Task2 );
    spTask3 = std::shared_ptr<Task>( new Task3 );
    spTask4 = std::shared_ptr<Task>( new Task4 );

    spTask1->setDataPointer( spData );
    spTask2->setDataPointer( spData );
    spTask3->setDataPointer( spData );
    spTask4->setDataPointer( spData );

    spTask1->setStatusPointer( spStatus );
    spTask2->setStatusPointer( spStatus );
    spTask3->setStatusPointer( spStatus );
    spTask4->setStatusPointer( spStatus );

    size_t nPreviousRandomNumber = 0;
    srand( (unsigned)time(NULL) );
    size_t nRsandNum = ( rand() % 4 ) + 1;
    
    for(size_t i=0; i<10; ++i)
    {
                
        while( nPreviousRandomNumber == nRsandNum )
        {
            nRsandNum = ( rand() % 4 ) + 1;
        }
        
        if(nRsandNum == 1)
        {
            containerTaskQueue.push(spTask1);
        }
        else if(nRsandNum == 2)
        {
            containerTaskQueue.push(spTask2);
        }
        else if(nRsandNum == 3)
        {
            containerTaskQueue.push(spTask3);
        }
        else if(nRsandNum == 4)
        {
            containerTaskQueue.push(spTask4);
        }

        nPreviousRandomNumber = nRsandNum;
    }

    spStatus->setStatusMessage("TQ: Task queue is initialized");
}

void TaskQueue::addTask(const std::shared_ptr<Task>& spTask)
{
    containerTaskQueue.push(spTask);
};

void TaskQueue::runTQ()
{
    while ( checkForChangingTask() )
    {
        changeTask();
    }
    spStatus->setStatusMessage("TQ: Task queue is succesfully executed");
}

bool TaskQueue::checkForChangingTask()
{
    return !containerTaskQueue.empty() && spStatus->getStatus();
}

void TaskQueue::changeTask()
{
    containerTaskQueue.front()->executeTask();
    containerTaskQueue.pop();
}