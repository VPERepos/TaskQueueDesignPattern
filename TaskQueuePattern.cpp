#include "TaskQueuePattern.h"
#include <time.h>
#include <iostream>


void cTask::SetDataPointer( const std::shared_ptr<cData>& spData )
{
    m_spData = spData;
}

void cTask1::ExecuteStateTask()
{
    m_spData->m_vGuestBook.push_back( "cTask1 was here" );
    std::cout << "Task 1" << std::endl;
}

void cTask2::ExecuteStateTask()
{
    m_spData->m_vGuestBook.push_back( "cTask2 was here" );
    std::cout << "Task 2" << std::endl;
}

void cTask3::ExecuteStateTask()
{
    m_spData->m_vGuestBook.push_back( "cTask3 was here" );
    std::cout << "Task 3" << std::endl;
}

void cTask4::ExecuteStateTask()
{
    m_spData->m_vGuestBook.push_back( "cTask4 was here" );
    std::cout << "Task 4" << std::endl;
}