#include "TaskQueuePattern.h"
#include <time.h>



void cTask::SetDataPointer( const std::shared_ptr<cData>& spData )
{
    m_spData = spData;
}

void cTask::SetStatusPointer( const std::shared_ptr<cStatus>& spStatus )
{
    m_spStatus = spStatus;
};

void cTask1::ExecuteTask()
{
    m_spData->m_vGuestBook.push_back( "Task 1 was here" );
    m_spStatus->SetStatusMessage("TQ: Executing Task 1");
}

void cTask2::ExecuteTask()
{
    m_spData->m_vGuestBook.push_back( "Task 2 was here" );
    m_spStatus->SetStatusMessage("TQ: Executing Task 2");
}

void cTask3::ExecuteTask()
{
    m_spData->m_vGuestBook.push_back( "Task 3 was here" );
    m_spStatus->SetStatusMessage("TQ: Executing Task 3");
}

void cTask4::ExecuteTask()
{
    m_spData->m_vGuestBook.push_back( "Task 4 was here" );
    m_spStatus->SetStatusMessage("TQ: Executing Task 4");
}

cStatus::cStatus()
{
    m_spExecMessage = std::make_shared<std::vector<std::string>>();
};

void cStatus::SetStatusMessage(const std::string& sStatusMessage)
{
    m_spExecMessage->push_back(sStatusMessage);
};

void cStatus::SetStatus(const bool& bExecStatus)
{
    m_bExecutionStatus = bExecStatus;
};

std::shared_ptr<std::vector<std::string>> cStatus::GetStatusMessage() const
{
    return m_spExecMessage;
};

bool cStatus::GetStatus() const
{
    return m_bExecutionStatus;
}

cTaskQueue::cTaskQueue(const std::shared_ptr<cData>& spData, const std::shared_ptr<cStatus>& spStatus):
m_spData(spData), m_spStatus(spStatus)
{
    m_spTask1 = std::shared_ptr<cTask>( new cTask1 );
    m_spTask2 = std::shared_ptr<cTask>( new cTask2 );
    m_spTask3 = std::shared_ptr<cTask>( new cTask3 );
    m_spTask4 = std::shared_ptr<cTask>( new cTask4 );

    m_spTask1->SetDataPointer( m_spData );
    m_spTask2->SetDataPointer( m_spData );
    m_spTask3->SetDataPointer( m_spData );
    m_spTask4->SetDataPointer( m_spData );

    m_spTask1->SetStatusPointer( m_spStatus );
    m_spTask2->SetStatusPointer( m_spStatus );
    m_spTask3->SetStatusPointer( m_spStatus );
    m_spTask4->SetStatusPointer( m_spStatus );

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
            m_TaskQueue.push(m_spTask1);
        }
        else if(nRsandNum == 2)
        {
            m_TaskQueue.push(m_spTask2);
        }
        else if(nRsandNum == 3)
        {
            m_TaskQueue.push(m_spTask3);
        }
        else if(nRsandNum == 4)
        {
            m_TaskQueue.push(m_spTask4);
        }

        nPreviousRandomNumber = nRsandNum;
    }

    m_spStatus->SetStatusMessage("TQ: Task queue is initialized");
}

void cTaskQueue::AddTask(const std::shared_ptr<cTask>& spTask)
{
    m_TaskQueue.push(spTask);
};

void cTaskQueue::RunTQ()
{
    while ( !m_TaskQueue.empty() && m_spStatus->GetStatus())
    {
        m_TaskQueue.front()->ExecuteTask();
        m_TaskQueue.pop();
    }
    m_spStatus->SetStatusMessage("TQ: Task queue is succesfully executed");
}