#pragma once
#include <vector>
#include <memory>
#include <queue>
#include <iostream>
class Data
{
public:
    Data(){};
    ~Data(){};
    std::vector<std::string> vGuestBook;
};

class Status
{
public:
    Status();
    ~Status(){};
    void setStatus(const bool& bExecStatus);
    void setStatusMessage(const std::string& sStatusMessage);
    bool getStatus() const;
    std::shared_ptr<std::vector<std::string>> getStatusMessage()const;
private:
    bool bExecutionStatus = true;
    std::shared_ptr<std::vector<std::string>> spExecMessage;
};
class Task
{
public:
    Task(std::string& theTaskName):m_TaskName{theTaskName} 
    {
        if(m_TaskName.size() == 0)
        {
            std::exception("State name can not be empty");
        }
    };
    virtual ~Task(){};
    virtual void executeTask(){};
    void setDataPointer( const std::shared_ptr<Data>& spData );
    void setStatusPointer( const std::shared_ptr<Status>& spStatus );

protected:
    std::shared_ptr<Data> spData;
    std::shared_ptr<Status> spStatus;
private:
    std::string m_TaskName;
    
};

class Task1 : public Task
{
public:
    ~Task1()override{};
    void executeTask() override;
};

class Task2 : public Task
{
public:
    ~Task2()override{};
    void executeTask() override;
};

class Task3 : public Task
{
public:
    ~Task3()override{};
    void executeTask() override;
};

class Task4 : public Task
{
public:
    ~Task4()override{};
    void executeTask() override;
};

class TaskQueue
{
public: 
    TaskQueue(const std::shared_ptr<Data>& spData, const std::shared_ptr<Status>& spStatus);
    ~TaskQueue(){};
    void addTask(const std::shared_ptr<Task>& spTask);
    void runTQ();
protected:
    bool checkForChangingTask();
    void changeTask();
private:
    std::queue<std::shared_ptr<Task>> containerTaskQueue;
    std::shared_ptr<Data> spData;   
    std::shared_ptr<Status> spStatus; 
    
    std::shared_ptr<Task> spTask1;
    std::shared_ptr<Task> spTask2;
    std::shared_ptr<Task> spTask3;
    std::shared_ptr<Task> spTask4;
};