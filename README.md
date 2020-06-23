# Task queue design pattern in modern C++

## Motivation

Imagine, that you have some data that you would like to process, but the way to process it can be combined of a lot of simple steps, that, in general, can be mixed up with each other, giving different orders of computation. For example, you have many images and it is necessary to process them and get some information out of them. You have also a library that consists of different computer vision algorithms, but you still don't know which is the most optimal way to apply those algorithms. Developing the procedure is time consuming due to checking many combinations and tuning parameters of algorithms. It is also very helpfull to be able to control the results after each step. My solution would be to program a tool with user interface, that lists in one window all possible steps, which can be chosen and added to the next window describing the resulting procedure. This is exactly the case, where a task queue design pattern can be applied. The steps from the resulting procedure are put into a task queue and then processed one after another. The example in this project is much simpler and somehow abstract, because it is made just to represent the idea.

## Classes structure and functionality


![UMLDiagram](/TaskQueue.png)

<!---```plantuml
@startuml

class cData{
    +m_vGuestBook
}

class cStatus{
    +SetStatus()
    +SetStatusMessage()
    +GetStatus()
    +GetStatusMessage()
    -m_bExecutionStatus = true
    -m_spExecMessage
}

class cTaskQueue{
    -m_TaskQueue
    -m_spData
    -m_spStatus
    -m_spTask1
    -m_spTask2
    -m_spTask3
    -m_spTask4
    +AddTask()
    +RunTQ()
}

class cTask{
    #m_spData
    #m_spStatus
    {abstract}+ExecuteTask()
    +SetDataPointer()
    +SetStatusPointer()
}
class cTask1{
    +ExecuteTask()
}
class cTask2{
    +ExecuteTask()
}
class cTask3{
    +ExecuteTask()
}
class cTask4{
    +ExecuteTask()
}

cTask <|-- cTask1
cTask <|-- cTask2
cTask <|-- cTask3
cTask <|-- cTask4

cTaskQueue *-- cData
cTaskQueue *-- cStatus
cTaskQueue *-- cTask1
cTaskQueue *-- cTask2
cTaskQueue *-- cTask3
cTaskQueue *-- cTask4

@enduml
```--->
UML-diagram above represents the design of the example program. There is a class called cTaskQueue, which consists of shared pointers to the objects of the classes cData, cStatus and cTask1 to cTask4. The shared pointers of types cStatus and cData are passed by parameters of the constructor of the cTaskQueue class. The objects of cTask1 to cTask4 types are allocated on heap in this constructor. The member variable m_TaskQueue is also filled out with randomly generated tasks in the constructor, but it can be done generally somewhere else in the program by using function AddTask(). Objects of types cData, cStatus and cTaskQueue are allocated on heap in the main function. Objects of types cTask1 to cTask4 have a function ExecuteTask(). This function can be powered with any custom business logic that processes an object of the type cData. The loop in the function RunTQ() takes the front element of the member variable m_TaskQue and calls the function ExecuteTask(). Afterwards the front element is deleted from the queue. This proceeds until the queue is empty.