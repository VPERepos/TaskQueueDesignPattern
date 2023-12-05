#pragma once
#include <vector>
#include <memory>
#include <queue>
#include <map>
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
    Task(const std::string& theTaskName):m_TaskName{theTaskName} 
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
    std::string getTaskName() const;
protected:
    std::shared_ptr<Data> spData;
    std::shared_ptr<Status> spStatus;
private:
    std::string m_TaskName;
    
};

class Task1 : public Task
{
public:
    Task1(const std::string& theTaskName):Task(theTaskName){};
    ~Task1()override{};
    void executeTask() override;
};

class Task2 : public Task
{
public:
    Task2(const std::string& theTaskName):Task(theTaskName){};
    ~Task2()override{};
    void executeTask() override;
};

class Task3 : public Task
{
public:
    Task3(const std::string& theTaskName):Task(theTaskName){};
    ~Task3()override{};
    void executeTask() override;
};

class Task4 : public Task
{
public:
    Task4(const std::string& theTaskName):Task(theTaskName){};
    ~Task4()override{};
    void executeTask() override;
};

class TaskQueue
{
public: 
    TaskQueue(const std::shared_ptr<Data>& spData, const std::shared_ptr<Status>& spStatus);
    ~TaskQueue(){};
    void clearTaskQueue();
    void addTaskToQueueByName(const std::string& theTaskName);
    std::vector<std::string> getTaskNames();
    bool isTaskQueueEmpty();
    void runTQ();
protected:
    bool checkForChangingTask();
    void changeTask();
private:
    std::map<std::string, std::shared_ptr<Task>> m_TasksSortedByNames;
    std::vector<std::string> m_TaskNames;
    std::queue<std::shared_ptr<Task>> m_ContainerTaskQueue;
    std::shared_ptr<Data> m_SpData;   
    std::shared_ptr<Status> m_SpStatus; 
    
    std::shared_ptr<Task> m_SpTask1;
    std::shared_ptr<Task> m_SpTask2;
    std::shared_ptr<Task> m_SpTask3;
    std::shared_ptr<Task> m_SpTask4;

    void initTasks();
    void assignDataPointerToTasks(const std::shared_ptr<Data>& theSpData);
    void assignStatusPointerToTasks(const std::shared_ptr<Status>& theSpStatus);
    void initContainerForTasksSortedByNames();
    void initContainerForTaskNames();
};