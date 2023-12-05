#include "TaskQueuePattern.h"
#include <utility>
#include <time.h>



void Task::setDataPointer( const std::shared_ptr<Data>& spData )
{
    this->spData = spData;
}

void Task::setStatusPointer( const std::shared_ptr<Status>& spStatus )
{
    this->spStatus = spStatus;
};
std::string Task::getTaskName()const
{
    return m_TaskName;
}
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
m_SpData(spData), m_SpStatus(spStatus)
{
    m_SpTask1 = std::make_shared<Task1>("Task1");
    m_SpTask2 = std::make_shared<Task2>("Task2");
    m_SpTask3 = std::make_shared<Task3>("Task3");
    m_SpTask4 = std::make_shared<Task4>("Task4");

    m_SpTask1->setDataPointer( spData );
    m_SpTask2->setDataPointer( spData );
    m_SpTask3->setDataPointer( spData );
    m_SpTask4->setDataPointer( spData );

    m_SpTask1->setStatusPointer( spStatus );
    m_SpTask2->setStatusPointer( spStatus );
    m_SpTask3->setStatusPointer( spStatus );
    m_SpTask4->setStatusPointer( spStatus );

    m_TasksSortedByNames.emplace(std::pair<std::string, std::shared_ptr<Task>>("Task1", m_SpTask1));
    m_TasksSortedByNames.emplace(std::pair<std::string, std::shared_ptr<Task>>("Task2", m_SpTask2));
    m_TasksSortedByNames.emplace(std::pair<std::string, std::shared_ptr<Task>>("Task3", m_SpTask3));
    m_TasksSortedByNames.emplace(std::pair<std::string, std::shared_ptr<Task>>("Task4", m_SpTask4));

    m_TaskNames.emplace_back("Task1");
    m_TaskNames.emplace_back("Task2");
    m_TaskNames.emplace_back("Task3");
    m_TaskNames.emplace_back("Task4");
        
    spStatus->setStatusMessage("TQ: Task queue is initialized and empty");
}

void TaskQueue::addTaskToQueueByName(const std::string& theTaskName)
{
    m_ContainerTaskQueue.push(m_TasksSortedByNames.at(theTaskName));
}

std::vector<std::string> TaskQueue::getTaskNames()
{
    return m_TaskNames;
}

void TaskQueue::clearTaskQueue()
{
    std::queue<std::shared_ptr<Task>> empty;
    std::swap( m_ContainerTaskQueue, empty );
}

bool TaskQueue::isTaskQueueEmpty()
{
    return m_ContainerTaskQueue.empty();
}

void TaskQueue::runTQ()
{
    while ( checkForChangingTask() )
    {
        changeTask();
    }
    m_SpStatus->setStatusMessage("TQ: Task queue is succesfully executed");
}

bool TaskQueue::checkForChangingTask()
{
    return !m_ContainerTaskQueue.empty() && m_SpStatus->getStatus();
}

void TaskQueue::changeTask()
{
    m_ContainerTaskQueue.front()->executeTask();
    m_ContainerTaskQueue.pop();
}