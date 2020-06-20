#pragma once
#include <vector>
#include <memory>
#include <queue>
#include <iostream>
class cData
{
public:
    cData(){};
    ~cData(){};
    std::vector<std::string> m_vGuestBook;
};

class cStatus
{
public:
    cStatus();
    ~cStatus(){};
    void SetStatus(const bool& bExecStatus);
    void SetStatusMessage(const std::string& sStatusMessage);
    bool GetStatus() const;
    std::shared_ptr<std::vector<std::string>> GetStatusMessage()const;
private:
    bool m_bExecutionStatus = true;
    std::shared_ptr<std::vector<std::string>> m_spExecMessage;
};
class cTask
{
public:
    cTask() {};
    virtual ~cTask(){};
    virtual void ExecuteStateTask(){};
    void SetDataPointer( const std::shared_ptr<cData>& spData );
    void SetStatusPointer( const std::shared_ptr<cStatus>& spStatus );
protected:
    std::shared_ptr<cData> m_spData;
    std::shared_ptr<cStatus> m_spStatus;
    
};

class cTask1 : public cTask
{
public:
    ~cTask1()override{};
    void ExecuteStateTask() override;
};

class cTask2 : public cTask
{
public:
    ~cTask2()override{};
    void ExecuteStateTask() override;
};

class cTask3 : public cTask
{
public:
    ~cTask3()override{};
    void ExecuteStateTask() override;
};

class cTask4 : public cTask
{
public:
    ~cTask4()override{};
    void ExecuteStateTask() override;
};

class cTaskQueue
{
public: 
    cTaskQueue(const std::shared_ptr<cData>& spData, const std::shared_ptr<cStatus>& spStatus);
    ~cTaskQueue(){};
    void AddTask(const std::shared_ptr<cTask>& spTask);
    void RunTQ();
private:
    std::queue<std::shared_ptr<cTask>> m_TaskQueue;
    std::shared_ptr<cData> m_spData;   
    std::shared_ptr<cStatus> m_spStatus; 
    
    std::shared_ptr<cTask> m_spTask1;
    std::shared_ptr<cTask> m_spTask2;
    std::shared_ptr<cTask> m_spTask3;
    std::shared_ptr<cTask> m_spTask4;
};