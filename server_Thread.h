//
// Created by leobellaera on 19/9/19.
//

#ifndef FRAME_OF_REFERENCE_THREAD_H
#define FRAME_OF_REFERENCE_THREAD_H

#include <thread>

class server_Thread {
private:
    std::thread thread;
public:
    server_Thread();
    void start();
    void join();
    virtual void run() = 0;
    server_Thread(const server_Thread&) = delete;
    server_Thread& operator=(const server_Thread&) = delete;
    server_Thread(server_Thread&& other);
    server_Thread& operator=(server_Thread&& other);
    virtual ~server_Thread();
};

#endif //FRAME_OF_REFERENCE_THREAD_H
