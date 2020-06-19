#pragma once
#include <vector>
#include <memory>
class cData
{
public:
    cData(){};
    ~cData(){};
    std::vector<std::string> m_vGuestBook;
};

class cTask
{
public:
    cTask() {};
    
    virtual void ExecuteStateTask(){};
    void SetDataPointer( const std::shared_ptr<cData>& spData );
protected:
    std::shared_ptr<cData> m_spData;
    
};

class cTask1 : public cTask
{
public:
    void ExecuteStateTask() override;
};

class cTask2 : public cTask
{
    void ExecuteStateTask() override;
};

class cTask3 : public cTask
{
    void ExecuteStateTask() override;
};

class cTask4 : public cTask
{
    void ExecuteStateTask() override;
};